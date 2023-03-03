//
// Created by tang on 23-3-2.
//

#include "PlotBaseWidget.h"


PlotBaseWidget::PlotBaseWidget(QWidget *parent,int w,int h) :
        QWidget(parent)
{
    setFixedSize(w,h);
    InitParam();
    m_plot = new QCustomPlot(this);
    m_plot->setFixedSize(w,h);

    //设置Tick画笔
    QPen TickPen;
    TickPen.setColor(Qt::black);
    TickPen.setWidth(2);
    QPen subTickPen;
    subTickPen.setColor(Qt::black);
    subTickPen.setWidth(1);
    //x坐标轴设置
    m_plot->xAxis->setLabel("TIME");         //设置坐标名字
    m_plot->xAxis->setLabelColor(Qt::black); //设置坐标颜色
    m_plot->xAxis->setLabelPadding(1);       //设置坐标轴名称文本距离坐标轴刻度线距离
    m_plot->xAxis->setTickLabels(true);
    m_plot->xAxis->setBasePen(TickPen);
    //设置Y轴
    /*说明：虽然通过setVisible()可以设置Y2轴的不可见，但是在绘制时游标标签需要重新进行设置
     *因为setVisible(false)后，Y2轴不绘制，Y2轴上的刻度线长度将无用，而将画笔设为Qt::NoPen，
     *则是使用透明画笔绘制Y2轴，其刻度线长度仍然占用空间，也就不会将游标标签的空间压缩，导致游标
     *标签显示不完整，这就需要在基础控件中修改游标标签的位置
     */
    m_plot->yAxis2->setTickLabels(true);     //设置y轴刻度值显示

    m_plot->yAxis2->setBasePen(TickPen);    //设置y2轴的绘制画笔
    m_plot->yAxis2->setTickPen(TickPen);    //设置y2轴的主刻度线绘制画笔
    m_plot->yAxis2->setSubTickPen(subTickPen); //设置y2轴的子刻度线绘制画笔
    connect(m_plot->yAxis2, SIGNAL(rangeChanged(QCPRange)), m_plot->yAxis, SLOT(setRange(QCPRange))); // left axis only mirrors inner right axis
    m_plot->yAxis2->setVisible(true);
    m_plot->axisRect()->axis(QCPAxis::atRight, 0)->setPadding(55); // add some padding to have space for tags


    //鼠标移动事件
    connect(m_plot, SIGNAL(mouseMove(QMouseEvent*)), this,SLOT(slotShowValueTracer(QMouseEvent*)));
    //设置曲线可拖拽、可缩放 //、可选择
    m_plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom ); //| QCP::iSelectPlottables
    //m_plot->axisRect()->setRangeZoom(Qt::Horizontal);  //设置水平缩放
    //m_plot->axisRect()->setRangeDrag(Qt::Horizontal);  //设置水平拖拽
}
// 设置曲线信息
void PlotBaseWidget::CreateGraph(QMap<int,StLineInfo> mapLineInfo)
{
    m_mapLineInfo.clear();
    //显示图例
    m_plot->legend->setVisible(true);
    //QColor bc = m_plot->legend->brush().color();
    m_plot->legend->setBrush(QBrush(QColor(255,255,255,0)));
    //图例内容行间距
    m_plot->legend->setRowSpacing(-3);
    // 创建图层及游标
    QMap<int,StLineInfo>::Iterator it = mapLineInfo.begin();
    for(int i = 0; it != mapLineInfo.end(); it++,i++)
    {
        StLineInfo st = it.value();
        StLineInfoAll line;
        // 创建图层
        line.graph = m_plot->addGraph();
        line.graph->setName(st.name);
        //获取图层颜色
        QColor cc;
        if(st.c == Qt::transparent)
            cc = GetUsefullColor(i);
        else
            cc = st.c;

        line.graph->setPen(QPen(cc));

        m_plot->legend->item(i)->setTextColor(cc);  //设置图例中每条线的文本颜色

        // 创建右侧游标
        line.tag = new myQchart(m_plot,YAxisTracer);
        line.tag->setArrowLineLength(5);
        line.tag->setArrowHead(QCPLineEnding::esDisc);
        line.tag->setTracerStyle(QCPItemTracer::tsNone);
        line.tag->setArrowPen(line.graph->pen());
        line.tag->setLabelPen(Qt::NoPen);
        line.tag->setTextColor(cc);
        line.tag->setText("");

        // 创建数值游标
        line.vtrac = new myQchart(m_plot,DataTracer);
        line.vtrac->setArrowHead(QCPLineEnding::esSpikeArrow);
        line.vtrac->setTracerStyle(QCPItemTracer::tsNone);
        line.vtrac->setArrowPen(QPen(cc));
//        line.vtrac->setTracerPen(QPen(cc));
        line.vtrac->setLabelPen(Qt::NoPen);
        line.vtrac->setTextColor(cc);


        line.info.name = st.name;
        line.info.c = cc;

        m_mapLineInfo.insert(it.key(),line);
    }
}
// 添加数据
void PlotBaseWidget::AddData(double key,QMap<int,double> mapData)
{
    QMap<int, double>::Iterator it = mapData.begin();
    for(; it != mapData.end(); it++)
    {
        double vv = it.value();

        QMap<int,StLineInfoAll>::Iterator ff = m_mapLineInfo.find(it.key());
        if(ff != m_mapLineInfo.end())
        {
            StLineInfoAll line = ff.value();
            line.graph->addData(key,vv);
            //更新标签位置和内容
            if(line.tag)
            {
                double graphValue = line.graph->dataMainValue(line.graph->dataCount()-1);
                line.tag->updateTracerPosition(key,graphValue);
                line.tag->setText(QString::number(graphValue, 'f', 2));
            }
        }
    }

    // make key axis range scroll with the data
//    m_plot->xAxis->setRange(key, m_nXlength, Qt::AlignRight); //50是X轴的长度
    m_plot->replot();
}
// 设置游标标签的显示和隐藏
void PlotBaseWidget::ShowTagLabels(bool b)
{
    QMap<int,StLineInfoAll>::Iterator it = m_mapLineInfo.begin();  //曲线属性
    for(; it != m_mapLineInfo.end(); it++)
    {
        StLineInfoAll st = it.value();
        if(st.tag)
            st.tag->setVisible(b);
    }
    m_plot->replot();
}

// 设置X轴范围
void PlotBaseWidget::SetXrange(int id,double lower, double upper)
{
    if(id == 0)
        m_plot->xAxis->setRange(lower,upper);         //设置X轴范围
    else
        m_plot->xAxis2->setRange(lower,upper);
}
// 设置Y轴范围
void PlotBaseWidget::SetYrange(int id,double lower, double upper)
{
    if(id == 0)
        m_plot->yAxis->setRange(lower,upper);
    else
        m_plot->yAxis2->setRange(lower,upper);
}
// 设置X轴窗口长度（动态曲线使用）
void PlotBaseWidget::SetXLength(int w)
{
    m_nXlength = w;
}
//显示数值游标
void PlotBaseWidget::slotShowValueTracer(QMouseEvent *event)
{
    double x = m_plot->xAxis->pixelToCoord(event->pos().x());
    QMap<int,StLineInfoAll>::Iterator it = m_mapLineInfo.begin();
    for(; it != m_mapLineInfo.end();it++)
    {
        StLineInfoAll info = it.value();
        double y = 0;
        QSharedPointer<QCPGraphDataContainer> tmpContainer;
        tmpContainer = info.graph->data();
        //使用二分法快速查找所在点数据
        int low = 0, high = tmpContainer->size();
        while(high > low)
        {
            int middle = (low + high) / 2;
            if(x < tmpContainer->constBegin()->mainKey() ||
               x > (tmpContainer->constEnd()-1)->mainKey())
                break;

            if(x == (tmpContainer->constBegin() + middle)->mainKey())
            {
                y = (tmpContainer->constBegin() + middle)->mainValue();
                break;
            }
            if(x > (tmpContainer->constBegin() + middle)->mainKey())
            {
                low = middle;
            }
            else if(x < (tmpContainer->constBegin() + middle)->mainKey())
            {
                high = middle;
            }
            if(high - low <= 1)
            {   //差值计算所在位置数据
                y = (tmpContainer->constBegin()+low)->mainValue() + ( (x - (tmpContainer->constBegin() + low)->mainKey()) *
                                                                      ((tmpContainer->constBegin()+high)->mainValue() - (tmpContainer->constBegin()+low)->mainValue()) ) /
                                                                    ((tmpContainer->constBegin()+high)->mainKey() - (tmpContainer->constBegin()+low)->mainKey());
                break;
            }

        }

        if(info.vtrac)
        {
            info.vtrac->updateTracerPosition(x, y);
            info.vtrac->setText(QString::number(y, 'f', 2));
        }
    }
    m_plot->replot();

}

// 初始化参数
void PlotBaseWidget::InitParam()
{
    m_nXlength = 50;
    m_nYchanged = -1;

    //初始化默认颜色列表
    {
        m_listColorDef.push_back(QColor(250, 120, 0));
        m_listColorDef.push_back(QColor(0, 180, 60));
        m_listColorDef.push_back(Qt::green);
        m_listColorDef.push_back(Qt::yellow);
        m_listColorDef.push_back(Qt::black);
        m_listColorDef.push_back(Qt::blue);
        m_listColorDef.push_back(Qt::red);
        m_listColorDef.push_back(Qt::darkCyan);
    }

}
// 获取可用颜色
QColor PlotBaseWidget::GetUsefullColor(int i)
{
    if(i>= 0 && i < m_listColorDef.size())
        return m_listColorDef.at(i);
    else
    {
        //QColor c(222,222,222);
        QColor c(qSin(i*0.3)*100+100, qSin(i*0.6+0.7)*100+100, qSin(i*0.4+0.6)*100+100);
        m_listColorDef.push_back(c);
        return c;
    }
}