#include "sll_udp.h"
#include <QDebug>
#include <QHostAddress>
#include <QHostInfo>
#include <QByteArray>
SLL_UDP::SLL_UDP(QObject *parent) : QObject(parent)
{
//    port = 8080;
//    boardcastip = "239.0.0.2";
//    sll_UdpInit(port,boardcastip);
}

void SLL_UDP::sll_UdpInit(quint16 pot,QString ip)
{
    UdpSocket = new QUdpSocket();
    UdpSocket->bind(QHostAddress::AnyIPv4,pot,QAbstractSocket::ShareAddress);
    UdpSocket->joinMulticastGroup(QHostAddress(ip));
    UdpSocket->setSocketOption(UdpSocket->MulticastLoopbackOption,0);
//    connect(UdpSocket,&QUdpSocket::readyRead,this,&SLL_UDP::dealmsg);
    qDebug() << "udpthread111" ;
}
void SLL_UDP::dealmsg()
{
//    char databuf[1024] = {0};
    QByteArray udpdata ;
    QHostAddress cliaddr;
//    quint16 cliport;
    qint64 len;
    QVector<double> ChangeDoubleData;
    double temp_udp;
//    读取对方发送的数据
//    len = UdpSocket->readDatagram(databuf,sizeof(databuf),&cliaddr,&cliport);
      udpdata.resize(UdpSocket->pendingDatagramSize());
      len = UdpSocket->readDatagram(udpdata.data(),udpdata.size());

    if(len > 0 && StartRevMsg)
    {
//        QString str = QString ("[%1：%2]%3").arg(cliaddr.toString())
//                                            .arg(cliport)
//                                            .arg(databuf);
//        QString str = QString(databuf);
//        memcpy(&udpdata,databuf,5);
//        emit sll_UdpMsg(str);
//        emit sll_UdpMsg((quint8 *)udpdata.data());
        quint8 *q = (quint8 *)udpdata.data();
        for(quint16 i = 0; i < len;i = i+4){
            ChangeDoubleData.push_back(char_tofloat(q + i));
        }
       emit sll_UdpMsg(ChangeDoubleData);
//        qDebug()<< ChangeDoubleData.size();
    }
}

void SLL_UDP::dealmsgthread()
{
    qDebug() << "dealmsgthread"<< QThread::currentThreadId();
    QByteArray udpdata ;
    qint64 len;
    QVector<double> ChangeDoubleData;
    while(1)
    {
        while(UdpSocket->hasPendingDatagrams()&StartRevMsg){
        udpdata.resize(UdpSocket->pendingDatagramSize());
        len = UdpSocket->readDatagram(udpdata.data(),udpdata.size());
        quint8 *q = (quint8 *)udpdata.data();
        for(quint16 i = 0; i < len;i = i+4){
            ChangeDoubleData.push_back(char_tofloat(q + i));
        }
        emit sll_UdpMsg(ChangeDoubleData);
        ChangeDoubleData.resize(0);
//        qDebug() << "udpthread"<< QThread::currentThreadId();
        }
//        while(sendipflag) {
//            QByteArray cha;
//            cha.append(char(StartRevMsg));
//            qDebug() << "cha"<< cha.toHex();
//        //    qDebug() << "parment"<< QThread::currentThreadId();
//            UdpSocket->writeDatagram(cha,QHostAddress(boardcastip),port);
//            sendipflag = false;
//            break;
//        }
//    while(!StartRevMsg)  {
//        QThread::sleep(3);
//        qDebug() << "stopudpthread";
//        }
    }
}

void SLL_UDP::setstartfalg(bool flag)
{
    StartRevMsg = flag;
}

void SLL_UDP::ParmetConfig(quint16 pot,QString ip,bool startrevmsg)
{
    StartRevMsg = startrevmsg;
    sendipflag = startrevmsg;
    sll_UdpInit(pot,ip);
//    boardcastip = ip;
    QByteArray cha;
    cha.append(char(startrevmsg));
    qDebug() << "cha"<< cha.toHex();
//    qDebug() << "parment"<< QThread::currentThreadId();
    UdpSocket->writeDatagram(cha,QHostAddress(boardcastip),pot);
}
double SLL_UDP::char_tofloat(unsigned char *p)
{
    SIGMADATA sigmadata;
    int sigmatmp;
    unsigned char doub_tmp[4],sign_f = 0;
    double value;
    sigmadata.arraydata[3] = *(p+0);
    sigmadata.arraydata[2] = *(p+1);
    sigmadata.arraydata[1] = *(p+2);
    sigmadata.arraydata[0] = *(p+3);
    if(sigmadata.arraydata[3] > 127){
        sign_f = 1;
        sigmatmp = - sigmadata.initial;
    }
    else {
        sign_f = 0;
        sigmatmp = sigmadata.initial;
    }
    doub_tmp[0] = ((sigmatmp >> 24)& 0x00ff) ;
    doub_tmp[1] = ((sigmatmp >> 16)& 0x00ff) ;
    doub_tmp[2] = ((sigmatmp >> 8)& 0x00ff) ;
    doub_tmp[3] = ((sigmatmp >> 0)& 0x00ff) ;
    value = (double)(doub_tmp[0]) + (double)((double)doub_tmp[1]/256)
            + (double)((double)doub_tmp[2] / 256 / 256)
            + (double)((double)doub_tmp[3] / 256/256/256);
    if(sign_f)
        return (- value);
    else
        return value;
}
