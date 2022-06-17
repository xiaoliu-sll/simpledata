#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QRect>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QDebug>
#include <QTabWidget>
#include "./gui/menubar/menubar.h"
#include "./gui/statustate/statustate.h"
#include "./gui/baseplot/baseplot.h"
#include "./gui/functionUI/functionui.h"
#define UIselect   0
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    InitGui();
    QRect deskrect = QApplication::desktop()->availableGeometry();
    int weight = deskrect.width();
    int height = deskrect.height();
    this->resize(weight,height);
    this->setGeometry(0,0,weight,height);

    qDebug() << weight << height;
    this->setStyleSheet("background: rgb(250, 250, 240);");
    centralWidget()->setStyleSheet("background: rgb(230, 230, 220);");
    qDebug() <<"mainthread"<< QThread::currentThreadId();
}

MainWindow::~MainWindow()
{
    delete ui;
}

#if UIselect
void MainWindow::InitGui()
{
}
#else

void MainWindow::InitGui()
{
    menubar().MenubarGui(menuBar());
    statustate().StatustateGui(statusBar());
    functionui *baseplot = new functionui();//first widget

    QWidget *function = new QWidget();// second widget
    baseplot->setStyleSheet("background: rgb(230, 230, 220);");

    QTabWidget *maintablewidget = new QTabWidget();//table widget
    maintablewidget->setAttribute(Qt::WA_StyledBackground);
    maintablewidget->setAutoFillBackground(true);
    maintablewidget->insertTab(0,baseplot,QStringLiteral("base"));
    maintablewidget->insertTab(1, function,QStringLiteral("function"));

    QVBoxLayout *mainlayout1 = new QVBoxLayout();
    mainlayout1->addWidget(maintablewidget);
    centralWidget()->setLayout(mainlayout1);
}
#endif
