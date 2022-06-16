#include "menubar.h"
#include <QMenu>
menubar::menubar(QObject *parent) : QObject(parent)
{

}

void menubar::MenubarGui(QMenuBar *mennubar)
{
    QMenu *menu = mennubar->addMenu("window");
    menu->addAction("save");
}
