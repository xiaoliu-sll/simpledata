#include "mainwindow.h"

#include <QApplication>
#include <QtSingleApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtSingleApplication app(argc, argv);
    if(app.isRunning()){
        return 0;
    }
    MainWindow w;
    w.show();
//    app.setActivationWindow(&w);
//    return app.exec();
     return a.exec();
}
