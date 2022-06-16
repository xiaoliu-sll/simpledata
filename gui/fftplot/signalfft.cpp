#include "signalfft.h"
#include <QHBoxLayout>

#include <QThread>
SignalFft::SignalFft(QWidget *parent) : QWidget(parent)
{
    SignalFftgui();
    qDebug() <<"fft"<< QThread::currentThread();
}

void SignalFft::SignalFftgui()
{

    signalplot = new BasePlot("signal");
    Fftplot = new BasePlot("fft");
//    Fftplot->baseplotsettitle("signal");
//    BasePlot *externplot = new BasePlot();
//    BasePlot *externplot1 = new BasePlot();
    QHBoxLayout *hboxlayout = new QHBoxLayout();

    hboxlayout->addWidget(signalplot);
    hboxlayout->addWidget(Fftplot);
//    hboxlayout->addWidget(externplot);
//    hboxlayout->addWidget(externplot1);
    hboxlayout->setStretchFactor(signalplot,1);
    hboxlayout->setStretchFactor(Fftplot,1);
//    hboxlayout->setStretchFactor(externplot,1);
//    hboxlayout->setStretchFactor(externplot1,1);
    hboxlayout->setSpacing(0);
    this->setLayout(hboxlayout);


    fft = new sllFFT(1000);
//    replottimer.start(400);
//    dataproduce.start(20);
//    connect(&dataproduce,&QTimer::timeout,this,[=]{
//        m_xDataVector.push_back(timecnt ++);
////        m_yDataVector.push_back(timecnt ++);
//        m_zDataVector.push_back(sin(((2 * 3.1415926) / 200) * timecnt));
////        if(m_zDataVector.size() > 100){
////            m_zDataVector.pop_front();
////            m_xDataVector.pop_front();
////        }
////        m_xDataVector.append(timecnt ++);//equip up describe
////        m_yDataVector.append(timecnt ++);
//    });
//    connect(&replottimer,&QTimer::timeout,this ,[=]{
//        if(m_zDataVector.size() > 1000){
//            m_zDataVector.remove(0,20);
////            m_xDataVector.remove(0,20);
//            if(m_xDataVector.size() >= 2000) m_xDataVector.remove(1000,1000);
////            qDebug()<<m_xDataVector.size();
//         }
//        fft->pushdata(m_zDataVector);
//        Fftplot->plotwave(m_xDataVector,m_zDataVector);
//    });
//    connect(fft,SIGNAL(processCompleted(QVector<double>,QVector<double>)),this,SLOT(fftslot(QVector<double>,QVector<double>)));
    sigthread = new signafftthread;
    thread = new QThread();
    sigthread->moveToThread(thread);
    thread->start();
    qRegisterMetaType<QVector<double>>("QVector<double>");
    connect(this,&SignalFft::startthread,sigthread,&signafftthread::simpletest);
    connect(sigthread,SIGNAL(signalwave(QVector<double>,QVector<double>)),this,SLOT(signalprintplot(QVector<double>, QVector<double>)));
    connect(sigthread,SIGNAL(signalfftwave(QVector<double>,QVector<double>)),this,SLOT(pushfftdata(QVector<double>, QVector<double>)));
    connect(fft,SIGNAL(processCompleted(QVector<double>,QVector<double>)),this,SLOT(fftslot(QVector<double>,QVector<double>)));
    connect(this,&QWidget::destroyed,this,&SignalFft::threaddestroy);
    emit startthread();
}

void SignalFft::fftslot(QVector<double> x,QVector<double> y)
{

    Fftplot->plotwave(x,y);
}

void SignalFft::pushfftdata(QVector<double> x, QVector<double> y)
{
//    x = x;
    fft->pushdata(y);
}

void SignalFft::signalprintplot(QVector<double> x, QVector<double> y)
{
    signalplot->plotwave(x,y);
}

void SignalFft::threaddestroy()
{
    thread->quit();
    thread->wait();
}

