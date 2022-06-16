#ifndef SIGNAFFTTHREAD_H
#define SIGNAFFTTHREAD_H

#include <QObject>
#include <QThread>
#include <QVector>
class signafftthread : public QObject
{
    Q_OBJECT
public:
    explicit signafftthread(QObject *parent = nullptr);
    void simpletest();
public slots:

signals:
    void signalwave(QVector<double> x,QVector<double> y);
    void signalfftwave(QVector<double> x,QVector<double> y);
private:
    QVector<double> m_xDataVector;
    QVector<double> m_yDataVector;
};

#endif // SIGNAFFTTHREAD_H
