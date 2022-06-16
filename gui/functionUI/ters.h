#ifndef TERS_H
#define TERS_H

#include <QWidget>
#include <QThread>
class ters : public QWidget
{
    Q_OBJECT
public:
    explicit ters(QWidget *parent = nullptr);
public slots:
    void threaddestroy(QThread *thread);
signals:

};

#endif // TERS_H
