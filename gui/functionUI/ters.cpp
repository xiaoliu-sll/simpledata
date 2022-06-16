#include "ters.h"
#include <QDebug>
ters::ters(QWidget *parent) : QWidget(parent)
{

}
void ters::threaddestroy(QThread *thread)
{
    qDebug() << "thread";
    thread->quit();
    thread->wait();
}
