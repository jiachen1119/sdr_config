#ifndef PLOTBASEWIDGET_H
#define PLOTBASEWIDGET_H

#include <QWidget>
#include "qcustomplot.h"
#include "myQchart.h"
#include <vector>


//曲线属性
struct StLineInfo
{
    QString name;   //曲线名称
    QColor c;       //曲线颜色
    int penWitdth=2;  //曲线粗细

    StLineInfo(){
        name="default";
        c = Qt::transparent;}
};


class PlotBaseWidget : public QWidget
{
Q_OBJECT
public:
    explicit PlotBaseWidget(QWidget *parent,int w = 400,int h = 300);
    void CreateGraph(std::vector<StLineInfo> mapLineInfo);
    void AddData(double key,QMap<int,double> mapData);
    void ShowTagLabels(bool b);
    void SetXrange(int id,double lower, double upper);
    void SetYrange(int id,double lower, double upper);
    void SetXLength(int w);

protected slots:
    void slotShowValueTracer(QMouseEvent*);  //显示数值游标

private:
    void InitParam();                        //初始化参数
    QColor GetUsefullColor(int i);           //获取可用颜色

private:
    QCustomPlot* customPlot;                    //曲线窗口

    //定义曲线属性信息
    struct StLineInfoAll
    {
        QPointer<QCPGraph> graph;          //图层标识
        QPointer<myQchart> vtrac;   //数值游标
        StLineInfo info;                   //曲线信息
    };

    QMap<int,StLineInfoAll> m_mapLineInfo;  //曲线属性
    QList<QColor> listDefaultColor;           //默认颜色

    int m_nXlength;                         //X轴长度
    int m_nYchanged;                        //0=表示y变化，1表示y2变化

};

#endif // PLOTBASEWIDGET_H

