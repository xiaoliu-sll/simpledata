#ifndef MENUBAR_H
#define MENUBAR_H

#include <QObject>
#include <QMenuBar>

class menubar : public QObject
{
    Q_OBJECT
public:
    explicit menubar(QObject *parent = nullptr);
public :
        void MenubarGui(QMenuBar *mennubar);
signals:

};

#endif // MENUBAR_H
