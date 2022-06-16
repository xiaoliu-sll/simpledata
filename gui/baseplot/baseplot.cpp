#include "baseplot.h"
#include "qwt_picker_machine.h"
#include "qwt_scale_widget.h"
#include "qwt_plot_layout.h"
#include "qwt_text.h"
#include "qwt_scale_engine.h"
#include <qwt_legend.h>
#include <qwt_symbol.h>
#include <QHBoxLayout>
#include <QPushButton>
#include <QDebug>
#include <QTouchEvent>
//#include <qwt_event_pattern.h>
BasePlot::BasePlot(QString str,QWidget *parent) : QWidget(parent)
{
    baseplot = new QwtPlot();
    baseplot->setTitle(str);

//    baseplotsettitle("QString str");
    basePlotCurve = new QwtPlotCurve("I");

    BasePlotInitGui(baseplot,basePlotCurve);
    basePlotCurve->setLegendAttribute(basePlotCurve->LegendShowLine );//show the line style
//    basePlotCurve->setLegendAttribute((basePlotCurve->LegendShowSymbol));
//   QwtPlotZoomer *zoom = new QwtPlotZoomer(baseplot->canvas());
//   zoom->setMousePattern(QwtEventPattern::MouseSelect2, Qt::LeftButton);
//mouseselect1 left -- fangda
//mouseselect2 left -- suoxiao

//    zoom->setMousePattern( QwtEventPattern::MouseSelect3, Qt::RightButton );
//    zoom->setZoomBase(true);
//      QwtPlotPanner *m_panner =new QwtPlotPanner(basePlotCurve->canvas());
//     m_panner->setMouseButton(Qt::RightButton);
//    setAutoReplot(true);
//    QwtPlotMagnifier *magnifer = new QwtPlotMagnifier(baseplot->canvas());
//    magnifer->setAxisEnabled(QwtPlot::yLeft,false);
//    magnifer->setAxisEnabled(QwtPlot::xBottom, true);
    showlegend();
}

BasePlot::BasePlot(QWidget *parent): QWidget(parent)
{
    baseplot = new QwtPlot();
    basePlotCurve = new QwtPlotCurve("I");
    BasePlotInitGui(baseplot,basePlotCurve);
}

void BasePlot::plotwave(QVector<double> x, QVector<double> y)
{
//    qDebug() << x <<y;
    basePlotCurve->setSamples(x,y);
    baseplot->replot();
}

void BasePlot::plotcurve()
{
    baseplot->replot();
}

void BasePlot::BasePlotInitGui(QwtPlot *basePlot,QwtPlotCurve *baseplotcurve)
{
//    basePlot->setTitle("fft");
//    basePlot->setAxisScale(QwtPlot::xBottom, 0, 500);
//    basePlot = new QwtPlot();
    QHBoxLayout *hlayout = new QHBoxLayout(this);
    hlayout->addWidget(basePlot);
//    hlayout->setContentsMargins(1,1,1,1);
//    this->setLayout(hlayout);
//    basePlot->setAxisAutoScale(true);
//    basePlotCurve = new QwtPlotCurve("I");
    baseplotcurve->attach(basePlot);
    baseplotcurve->setPen(QPen(Qt::blue));
    baseplotcurve->setPen(QColor(80,128,128),1.0,Qt::DashLine);

//    this->layout()->setSpacing(0);
//    this->layout()->setContentsMargins(1, 1, 1, 1);
    this->setStyleSheet(" border-radius:8px;");
    this->setStyleSheet("font-family: Palatino Linotype;");
    this->setAttribute(Qt::WA_TranslucentBackground,true); //设置窗体透明
    QSizePolicy sizepolicy;
    sizepolicy.setVerticalPolicy(QSizePolicy::Ignored);
    sizepolicy.setHorizontalPolicy(QSizePolicy::Ignored);//
    basePlot->setSizePolicy(sizepolicy);
}

void BasePlot::baseplotsettitle(QString str)
{
    baseplot->setTitle(str);
}
void BasePlot::setXfixd()
{

}
void BasePlot::AttachPlotCurve(QwtPlotCurve *baseplotcurve,const QPen &pen)
{
    baseplotcurve->attach(baseplot);
    baseplotcurve->setPen(pen);
    baseplotcurve->setLegendAttribute(basePlotCurve->LegendShowLine );//show the line style
}

void BasePlot::showlegend()
{
    QwtLegend *legend = new QwtLegend;
    baseplot->insertLegend(legend, QwtPlot::RightLegend );
}
//void BasePlot::setStyle()
//{
//    // 坐标轴颜色
//    basePlot->setStyleSheet("color: rgb(0, 0, 0)");

//    //设置曲线颜色        NoPen,
////    SolidLine,
////    DashLine,虚线
////    DotLine,虚线
////    DashDotLine,虚线
////    DashDotDotLine,
////    CustomDashLine自定义
//    basePlotCurve->setPen(QColor(33, 150, 243), 1.0, Qt::SolidLine);
////    m_pPlotCurve1->setPen(QColor(94, 76, 198), 1.0, Qt::SolidLine);

////    QwtLegend *legend = new QwtLegend;
////    legend->setDefaultItemMode( QwtLegendData::Checkable );
////    m_pPlot->insertLegend(legend, QwtPlot::TopLegend );

////    //连接槽，处理选择事件
////         connect( legend, SIGNAL( checked( const QVariant &, bool, int ) ),
////             SLOT( legendChecked( const QVariant &, bool ) ) );


////    QwtLegend *legend1 = new QwtLegend;
////    legend1->setDefaultItemMode( QwtLegendData::Checkable );
////    m_pPlot->insertLegend(legend, QwtPlot::TopLegend );
////    //连接槽，处理选择事件
////         connect( legend1, SIGNAL( checked( const QVariant &, bool, int ) ),
////             SLOT( legendChecked( const QVariant &, bool ) ) );


//    for (int axis = 0; axis < QwtPlot::axisCnt; axis++) {
//        QwtScaleWidget* scaleWidget = basePlot->axisWidget(axis);
//        scaleWidget->setMargin(0);

//        /* 隐藏坐标轴及刻度
//        m_pPlot->axisScaleDraw(axis)->enableComponent(QwtAbstractScaleDraw::Backbone, false);
//        m_pPlot->axisScaleDraw(axis)->enableComponent(QwtAbstractScaleDraw::Ticks, false);
//        */

//        // 小刻度间隔
//        basePlot->setAxisMaxMinor(QwtPlot::yLeft, 0);
//        basePlot->setAxisMaxMinor(QwtPlot::xBottom, 2);

//        // 坐标轴名称
//        QFont font("宋体", 10);
//        basePlot->axisTitle(axis).setFont(font);
//    }

//    basePlot->plotLayout()->setAlignCanvasToScales( true );

////    // 拾取器颜色
////    m_pPlotPicker->setRubberBandPen( QColor( Qt::blue ) );
////    m_pPlotPicker->setTrackerPen( QColor( Qt::gray ) );

////    // 网格
////    m_PlotGrid->setPen(QPen(QColor(40, 46, 78), 0, Qt::DashDotLine));
//}
