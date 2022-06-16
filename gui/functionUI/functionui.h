#ifndef FUNCTIONUI_H
#define FUNCTIONUI_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QCheckBox>
#include "./gui/baseplot/baseplot.h"
#include "./gui/fftplot/sllfft.h"
#include "signafftthread.h"
#include "./network/udp/sll_udp.h"
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
class functionui : public QWidget
{
    Q_OBJECT
public:
    explicit functionui(QWidget *parent = nullptr);
private:
    void UI_init();
    QHBoxLayout *simpleratelayout();
    QVBoxLayout *rightwidget();
    QHBoxLayout *chanellayout(QCheckBox *fftbox);
    QVBoxLayout *leftwidget();
    void checkboxstyle(QCheckBox *box);

    signafftthread *sigthread;
    BasePlot *signalplot;
    BasePlot *fftplot;
     QThread *thread;
     QThread *udpthread;
     sllFFT *fft;
     SLL_UDP *sll_udp;
     QTextEdit *showtext;
     QLineEdit *ip_linedit;
     QLineEdit *port_linedit;
     QPushButton *testbutton;
     QVector<double> fftXaxis;
     QVector<double> Xaxis;
     QVector<double> Yaxis;
     QwtPlotCurve *curve;
     QwtPlotCurve *chanel2curve;
     QwtPlotCurve *chanel3curve;
     bool showchanelsign = false;
     bool showchanel1sign = false;
     bool showchanel2sign = false;


signals:
    void startthread();
    void startudpthread();
    void fftsignal(QVector<double> x, QVector<double> y);
    void tanslateipandport(quint16 port, QString ip,bool startrevmsg);
    void udpthreadstop(bool stop);
private slots:
    void signalprintplot(QVector<double> x, QVector<double> y);
    void pushfftdata(QVector<double>, QVector<double> y);
    void fftslot(QVector<double> x,QVector<double> y);
     void threaddestroy();
     void texteditshow(QString str);
     void texteditshow(quint8 *value);
     void texteditshow(QVector<double> value);
     void GetLocalIpandPort();
     void udpthreadstopfun(bool flag);
};

#endif // FUNCTIONUI_H
