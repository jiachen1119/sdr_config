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
    QSharedPointer<QCPAxisTickerFixed> fixTicker(new QCPAxisTickerFixed);
    customPlot->yAxis->setTickLabels(true);     //设置y轴刻度值显示
    customPlot->yAxis->setTicker(fixTicker);
    customPlot->yAxis->setBasePen(TickPen);    //设置y轴的绘制画笔
    customPlot->yAxis->setTickPen(TickPen);    //设置y轴的主刻度线绘制画笔
    customPlot->yAxis->setSubTickPen(subTickPen); //设置y轴的子刻度线绘制画笔
    customPlot->yAxis->setLabel("CNo");
    customPlot->axisRect()->axis(QCPAxis::atRight, 0)->setPadding(55); // add some padding to have space for tags

    //设置曲线可拖拽、可缩放 //、可选择
    customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom ); //| QCP::iSelectPlottables
    //customPlot->axisRect()->setRangeZoom(Qt::Horizontal);  //设置水平缩放
    //customPlot->axisRect()->setRangeDrag(Qt::Horizontal);  //设置水平拖拽
}
// 设置曲线信息
void PlotBaseWidget::CreateGraph(std::vector<StLineInfo> lineInfo)
{
    mapLineInfo.clear();
    //图例
    customPlot->legend->setVisible(true);
    customPlot->legend->setBrush(QBrush(QColor(255, 255, 255, 0)));
    customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignLeft | Qt::AlignTop);
    //图例内容行间距
//    customPlot->legend->setRowSpacing(-3);
    // 创建图层
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
        drawStruct.graph->setName(lineStruct.lineName);
        drawStruct.graph->setPen(pen);
        drawStruct.graph->setLineStyle(QCPGraph::lsLine);

        //set scatter
        drawStruct.graph->setScatterStyle(
                QCPScatterStyle(QCPScatterStyle::ssCircle,
                     QPen(Qpen_color, 1),
                     QBrush(Qt::white), 1));
        customPlot->legend->item(i)->setTextColor(Qpen_color);  //设置图例中每条线的文本颜色

        drawStruct.info.lineName = lineStruct.lineName;
        drawStruct.info.c = Qpen_color;

        mapLineInfo.insert(i, drawStruct);
    }
}
// 添加数据
void PlotBaseWidget::AddData(double key,QMap<int,double> mapData)
{
    //两次遍历 将新增的数据添加到对应的图层中
    QMap<int, double>::Iterator it_inputData = mapData.begin();
    for(; it_inputData != mapData.end(); it_inputData++)
    {
        QMap<int,StLineInfoAll>::Iterator it_graph = mapLineInfo.find(it_inputData.key());
        if(it_graph != mapLineInfo.end())
            it_graph.value().graph->addData(key,it_inputData.value());
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
// init
void PlotBaseWidget::InitParam()
{
    //初始化默认颜色列表
    listDefaultColor.push_back(QColor(250, 120, 0));
    listDefaultColor.push_back(QColor(0, 180, 60));
    listDefaultColor.push_back(Qt::green);
    listDefaultColor.push_back(Qt::black);
    listDefaultColor.push_back(Qt::red);
    listDefaultColor.push_back(Qt::darkCyan);
    //start a new thread
    plot_Qthread *plotQthread=new plot_Qthread();

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