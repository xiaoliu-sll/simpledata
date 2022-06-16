#include "statustate.h"
#include <QLabel>
statustate::statustate(QObject *parent) : QObject(parent)
{

}

void statustate::StatustateGui(QStatusBar *statustate)
{
    QLabel *leftlabel = new QLabel("this is my state");
    statustate->addWidget(leftlabel);
    QLabel *per3 = new QLabel("Ready3");
    QLabel *per2 = new QLabel("Ready2");
//    statustate->addWidget(per3);
    statustate->addPermanentWidget(per2);
    statustate->addPermanentWidget(per3);
    statustate->setStyleSheet(QString("QStatusBar::item{border: 0px}"));
}
