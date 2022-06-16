#include "signafftthread.h"
//#include <QTimer>
#include <QtMath>
#include <QDebug>
signafftthread::signafftthread(QObject *parent) : QObject(parent)
{

}
void signafftthread::simpletest()
{
//    QTimer
    static quint16 timecnt;
     static quint16 deletedatatime;
     static quint16 fftcnnt;
//    timecnt.start(100);
     qDebug() << "signalthread" << QThread ::currentThread();
    while(1)
    {
        m_xDataVector.push_back(timecnt++);
        m_yDataVector.push_back(qSin(((2 * 3.1415926) / 200) * timecnt));
        deletedatatime ++;
        if(deletedatatime >= 20) {
            if(deletedatatime >= 20)
            deletedatatime = 0;
//            qDebug() << "thread" << QThread ::currentThread();
            if(m_yDataVector.size() > 1000){
                m_yDataVector.remove(0,20);
          //     m_xDataVector.remove(0,20);
                 if(m_xDataVector.size() >= 2000) {
                     timecnt = 1000;
                     m_xDataVector.remove(1000,1000);
                 }
//               qDebug() << timecnt << m_yDataVector.size();
//                qDebug() << m_yDataVector;
            }
//            emit signalwave(m_xDataVector,m_yDataVector);
//            emit signalfftwave(m_xDataVector,m_yDataVector);
        }
//        qDebug() << "signalthread";
        QThread::sleep(2);
    }

}

