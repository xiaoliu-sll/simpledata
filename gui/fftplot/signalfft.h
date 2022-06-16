#ifndef SIGNALFFT_H
#define SIGNALFFT_H

#include <QWidget>
#include <QTimer>
#include "signafftthread.h"
#include "sllfft.h"
class SignalFft : public QWidget
{
    Q_OBJECT
public:
    explicit SignalFft(QWidget *parent = nullptr);

private:
    void SignalFftgui();
    QwtPlot *Plotgraf;
    QwtPlotCurve *PlotCurve;

signals:
    void startthread();
public slots:
    void fftslot(QVector<double> x,QVector<double> y);
    void pushfftdata(QVector<double> x,QVector<double> y);
    void signalprintplot(QVector<double> x,QVector<double> y);
    void threaddestroy();
public:
//    signafftthread sigfftthread;
private:
    QTimer replottimer;
    QTimer dataproduce;
    QVector<double> m_xDataVector;                  // x坐标数据
    QVector<double> m_yDataVector;                  // y坐标数据

    QVector<double> m_zDataVector;                  // y坐标数据
     unsigned int timecnt = 0;
     BasePlot *signalplot;
     BasePlot *Fftplot;

     sllFFT *fft;
     QThread *thread;
};

#endif // SIGNALFFT_H
