#ifndef STATUSTATE_H
#define STATUSTATE_H

#include <QObject>
#include <QStatusBar>
class statustate : public QObject
{
    Q_OBJECT
public:
    explicit statustate(QObject *parent = nullptr);

public :
    void StatustateGui(QStatusBar *statustate);
signals:

};

#endif // STATUSTATE_H
