#ifndef BASEPLOT_H
#define BASEPLOT_H

#include <QWidget>
#include "qwt_plot.h"
#include "qwt_plot_curve.h"
#include "qwt_plot_grid.h"
#include "qwt_plot_picker.h"
#include "qwt_plot_marker.h"
#include "qwt_plot_zoomer.h"
#include "qwt_plot_panner.h"
#include <qwt_plot_magnifier.h>
#include <QTimer>
#include <QVector>
class BasePlot : public QWidget
{
    Q_OBJECT
public:
    explicit BasePlot(QString str,QWidget *parent = nullptr);
    explicit BasePlot(QWidget *parent = nullptr);
    void plotwave(QVector<double> x,QVector<double> y);
    void plotcurve();
    void baseplotsettitle(QString str);
    void setXfixd();
    void AttachPlotCurve(QwtPlotCurve *baseplotcurve,const QPen &pen);
    void showlegend();

//   void setStyle();
signals:
private:
    QwtPlot *baseplot;
    QwtPlotCurve *basePlotCurve;
    QTimer replottimer;
    QTimer dataproduce;
    QVector<double> m_xDataVector;                  // x坐标数据
    QVector<double> m_yDataVector;                  // y坐标数据
       unsigned int timecnt = 0;
 void BasePlotInitGui(QwtPlot *basePlot,QwtPlotCurve *baseplotcurve);


};

#endif // BASEPLOT_H
