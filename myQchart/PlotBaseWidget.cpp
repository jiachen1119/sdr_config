//
// Created by tang on 23-3-2.
//

#include "PlotBaseWidget.h"


PlotBaseWidget::PlotBaseWidget(QWidget *parent) :
        QWidget(parent)
{
    //setFixedSize(width,height);
    InitParam();
    customPlot = new QCustomPlot(parent);
    QScreen *screen = qApp->primaryScreen();
    int screenWidth = screen->size().width();            //屏幕宽
    int screenHeight = screen->size().height();
    customPlot->setFixedSize(screenWidth/2,screenHeight/2);

    //设置Tick画笔
    QPen TickPen;
    TickPen.setColor(Qt::black);
    TickPen.setWidth(2);
    QPen subTickPen;
    subTickPen.setColor(Qt::black);
    subTickPen.setWidth(1);
    //axis setting
    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker->setTimeFormat("%s");
    customPlot->xAxis->setVisible(true);
    customPlot->xAxis->setTicker(timeTicker);
    customPlot->xAxis->setTickLabels(true);
    customPlot->xAxis->setBasePen(TickPen);
    customPlot->xAxis->setTickPen(TickPen);
    customPlot->xAxis->setSubTickPen(subTickPen);
    customPlot->xAxis->setLabel("Time");         //设置坐标名字
    customPlot->xAxis->setLabelColor(Qt::black); //设置坐标颜色
    customPlot->xAxis->setLabelPadding(1);       //设置坐标轴名称文本距离坐标轴刻度线距离

    //设置Y轴
    /*说明：虽然通过setVisible()可以设置Y2轴的不可见，但是在绘制时游标标签需要重新进行设置
     *因为setVisible(false)后，Y2轴不绘制，Y2轴上的刻度线长度将无用，而将画笔设为Qt::NoPen，
     *则是使用透明画笔绘制Y2轴，其刻度线长度仍然占用空间，也就不会将游标标签的空间压缩，导致游标
     *标签显示不完整，这就需要在基础控件中修改游标标签的位置
     */
    QSharedPointer<QCPAxisTickerFixed> fixTicker(new QCPAxisTickerFixed);
    customPlot->yAxis->setTickLabels(true);     //设置y轴刻度值显示
    customPlot->yAxis->setTicker(fixTicker);
    customPlot->yAxis->setBasePen(TickPen);    //设置y轴的绘制画笔
    customPlot->yAxis->setTickPen(TickPen);    //设置y轴的主刻度线绘制画笔
    customPlot->yAxis->setSubTickPen(subTickPen); //设置y轴的子刻度线绘制画笔
    customPlot->yAxis->setLabel("CNo");
    connect(customPlot->yAxis2, SIGNAL(rangeChanged(QCPRange)), customPlot->yAxis, SLOT(setRange(QCPRange))); // left axis only mirrors inner right axis
    customPlot->axisRect()->axis(QCPAxis::atRight, 0)->setPadding(55); // add some padding to have space for tags


    //鼠标移动事件
    connect(customPlot, SIGNAL(mouseMove(QMouseEvent *)), this, SLOT(slotShowValueTracer(QMouseEvent *)));
    //设置曲线可拖拽、可缩放 //、可选择
    customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom ); //| QCP::iSelectPlottables
    //customPlot->axisRect()->setRangeZoom(Qt::Horizontal);  //设置水平缩放
    //customPlot->axisRect()->setRangeDrag(Qt::Horizontal);  //设置水平拖拽
}
// 设置曲线信息
void PlotBaseWidget::CreateGraph(std::vector<StLineInfo> lineInfo)
{
    m_mapLineInfo.clear();
    //图例
    customPlot->legend->setVisible(true);
    customPlot->legend->setBrush(QBrush(QColor(255, 255, 255, 0)));
    customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignLeft | Qt::AlignTop);
    //图例内容行间距
//    customPlot->legend->setRowSpacing(-3);
    // 创建图层及游标
    for(int i = 0; i< lineInfo.size();i++)
    {
        StLineInfo lineStruct = lineInfo.at(i);
        StLineInfoAll drawStruct;
        //get Qpen color
        QColor Qpen_color=GetUsefullColor(i);
        //set Qpen config
        QPen pen;
        pen.setColor(Qpen_color);
        pen.setWidth(3);
        pen.setStyle(Qt::SolidLine);
        // 创建图层
        drawStruct.graph = customPlot->addGraph();
        drawStruct.graph->setName(lineStruct.name);
        drawStruct.graph->setPen(pen);
        drawStruct.graph->setLineStyle(QCPGraph::lsLine);

        //set scatter
        drawStruct.graph->setScatterStyle(
                QCPScatterStyle(QCPScatterStyle::ssCircle,
                     QPen(Qpen_color, 1),
                     QBrush(Qt::white), 1));
        customPlot->legend->item(i)->setTextColor(Qpen_color);  //设置图例中每条线的文本颜色


        // 创建数值游标
        drawStruct.vtrac = new myQchart(customPlot, DataTracer);
        drawStruct.vtrac->setArrowHead(QCPLineEnding::esSpikeArrow);
        drawStruct.vtrac->setTracerStyle(QCPItemTracer::tsNone);
        drawStruct.vtrac->setArrowPen(QPen(Qpen_color));
//        drawStruct.vtrac->setTracerPen(QPen(Qpen_color));
        drawStruct.vtrac->setLabelPen(Qt::NoPen);
        drawStruct.vtrac->setTextColor(Qpen_color);


        drawStruct.info.name = lineStruct.name;
        drawStruct.info.c = Qpen_color;

        m_mapLineInfo.insert(i, drawStruct);
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
        }
    }

    // make key axis range scroll with the data
//    customPlot->xAxis->setRange(key, m_nXlength, Qt::AlignRight); //50是X轴的长度
    customPlot->replot();
}
// 设置游标标签的显示和隐藏
void PlotBaseWidget::ShowTagLabels(bool b)
{
    QMap<int,StLineInfoAll>::Iterator it = m_mapLineInfo.begin();  //曲线属性
    for(; it != m_mapLineInfo.end(); it++)
    {
        StLineInfoAll st = it.value();
    }
    customPlot->replot();
}

// 设置X轴范围
void PlotBaseWidget::SetXrange(int id,double lower, double upper)
{
    if(id == 0)
        customPlot->xAxis->setRange(lower, upper);         //设置X轴范围
    else
        customPlot->xAxis2->setRange(lower, upper);
}
// 设置Y轴范围
void PlotBaseWidget::SetYrange(int id,double lower, double upper)
{
    if(id == 0)
        customPlot->yAxis->setRange(lower, upper);
    else
        customPlot->yAxis2->setRange(lower, upper);
}
// 设置X轴窗口长度（动态曲线使用）
void PlotBaseWidget::SetXLength(int w)
{
    m_nXlength = w;
}
//显示数值游标
void PlotBaseWidget::slotShowValueTracer(QMouseEvent *event)
{
    double x = customPlot->xAxis->pixelToCoord(event->pos().x());
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
    customPlot->replot();

}

// 初始化参数
void PlotBaseWidget::InitParam()
{
    m_nXlength = 50;
    m_nYchanged = -1;

    //初始化默认颜色列表
    {
        listDefaultColor.push_back(QColor(250, 120, 0));
        listDefaultColor.push_back(QColor(0, 180, 60));
        listDefaultColor.push_back(Qt::green);
        listDefaultColor.push_back(Qt::yellow);
        listDefaultColor.push_back(Qt::black);
        listDefaultColor.push_back(Qt::blue);
        listDefaultColor.push_back(Qt::red);
        listDefaultColor.push_back(Qt::darkCyan);
    }

}
// 获取可用颜色
QColor PlotBaseWidget::GetUsefullColor(int i)
{
    if(i>= 0 && i < listDefaultColor.size())
        return listDefaultColor.at(i);
    else
    {
        //QColor c(222,222,222);
        QColor c(qSin(i*0.3)*100+100, qSin(i*0.6+0.7)*100+100, qSin(i*0.4+0.6)*100+100);
        listDefaultColor.push_back(c);
        return c;
    }
}