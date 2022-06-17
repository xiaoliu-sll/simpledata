#ifndef SLL_UDP_H
#define SLL_UDP_H

#include <QObject>
#include <QUdpSocket>
#include <QString>
#include <QVector>
#include <QThread>

class SLL_UDP : public QObject
{
    Q_OBJECT
public:
    explicit SLL_UDP(QObject *parent = nullptr);
    void dealmsgthread();
    void setstartfalg(bool flag);
public slots:
    void ParmetConfig(quint16 pot,QString ip,bool startrevmsg);
signals:
    void sll_UdpMsg(QString value);
    void sll_UdpMsg(quint8 *value);
    void sll_UdpMsg(QVector<double> value);
private slots:
    void dealmsg();

private:
    QUdpSocket *UdpSocket;

    double char_tofloat(unsigned char *p);
    void sll_UdpInit(quint16 pot,QString ip);

    quint16 port = 8080;
    QString boardcastip = "239.0.0.3";
    bool StartRevMsg = false;
    bool sendipflag = false;


};
typedef union{
        int initial;
        unsigned char arraydata[4];
    }SIGMADATA;
#endif // SLL_UDP_H
