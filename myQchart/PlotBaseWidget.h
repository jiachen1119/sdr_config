#ifndef PLOTBASEWIDGET_H
#define PLOTBASEWIDGET_H

#include <QWidget>
#include "qcustomplot.h"
#include "myQchart.h"


//曲线属性
struct StLineInfo
{
    QString name;   //曲线名称
    QColor c;       //曲线颜色

    StLineInfo(){c = Qt::transparent;}
};


class PlotBaseWidget : public QWidget
{
Q_OBJECT
public:
    explicit PlotBaseWidget(QWidget *parent = 0,int w = 400,int h = 300);

    /**
     * @brief 设置曲线信息
     * @param mapLineInfo 曲线信息，键值用于标识每条曲线
     */
    void CreateGraph(QMap<int,StLineInfo> mapLineInfo);

    /**
     * @brief 添加数据
     * @param key 键值
     * @param mapData 数据内容，键为数据类型标识，值为key对应的值
     */
    void AddData(double key,QMap<int,double> mapData);

    /**
     * @brief 设置游标标签的显示和隐藏
     * @param b 显示/隐藏
     */
    void ShowTagLabels(bool b);

    /**
     * @brief 设置数值游标的显示和隐藏
     * @param b 显示/隐藏
     */
    //void ShowValueTracer(bool b);

    /**
     * @brief 设置X轴范围
     * @param id 用于区别下侧X轴和上侧X轴，0-下侧，1上侧
     * @param lower 小值
     * @param upper 大值
     */
    void SetXrange(int id,double lower, double upper);

    /**
     * @brief 设置Y轴范围
     * @param id 用于区别左侧Y轴和右侧Y轴，0-左侧，1右侧
     * @param lower 小值
     * @param upper 大值
     */
    void SetYrange(int id,double lower, double upper);

    /**
     * @brief 设置X轴窗口长度（动态曲线使用）
     * @param w 窗口长度
     */
    void SetXLength(int w);



protected slots:
    void slotShowValueTracer(QMouseEvent*);  //显示数值游标

private:
    void InitParam();                        //初始化参数
    QColor GetUsefullColor(int i);           //获取可用颜色

private:
    QCustomPlot* m_plot;                    //曲线窗口

    //定义曲线属性信息
    struct StLineInfoAll
    {
        QPointer<QCPGraph> graph;          //图层标识
        QPointer<myQchart> tag;     //游标
        QPointer<myQchart> vtrac;   //数值游标
        StLineInfo info;                   //曲线信息
        StLineInfoAll(){graph = 0; tag = 0;vtrac = 0;}
    };

    QMap<int,StLineInfoAll> m_mapLineInfo;  //曲线属性
    QList<QColor> m_listColorDef;           //默认颜色

    int m_nXlength;                         //X轴长度
    int m_nYchanged;                        //0=表示y变化，1表示y2变化

};

#endif // PLOTBASEWIDGET_H

