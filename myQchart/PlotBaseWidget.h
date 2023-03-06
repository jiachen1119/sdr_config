#ifndef PLOTBASEWIDGET_H
#define PLOTBASEWIDGET_H

#include <QWidget>
#include "qcustomplot.h"
#include <vector>


//曲线属性
struct StLineInfo
{
    QString lineName;   //曲线名称
    QColor c;       //曲线颜色
    int penWitdth=2;  //曲线粗细

    StLineInfo(){
        lineName="default";
        c = Qt::transparent;}
};


class PlotBaseWidget : public QWidget
{
Q_OBJECT
public:
    explicit PlotBaseWidget(QWidget *parent);
    void CreateGraph(std::vector<StLineInfo> mapLineInfo);
    void AddData(double key,QMap<int,double> mapData);
    void SetXrange(int id,double lower, double upper);
    void SetYrange(int id,double lower, double upper);

private:
    void InitParam();                        //初始化参数
    QColor GetUsefullColor(int i);           //获取可用颜色

private:
    QCustomPlot* customPlot;                    //曲线窗口
    //定义曲线属性信息
    struct StLineInfoAll
    {
        QPointer<QCPGraph> graph;          //图层标识
        StLineInfo info;                   //曲线信息
    };

    QMap<int,StLineInfoAll> mapLineInfo;  //曲线属性
    QList<QColor> listDefaultColor;           //默认颜色


};

#endif // PLOTBASEWIDGET_H

