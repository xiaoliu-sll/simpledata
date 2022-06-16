#include "functionui.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QIcon>
#include <QLabel>
#include <QAction>
#include <QMenu>
#include <QComboBox>
#include <QCheckBox>
#include <QFrame>
#include <QGraphicsDropShadowEffect>
#include <QColor>
#include <QTimer>
functionui::functionui(QWidget *parent) : QWidget(parent)
{
    for(quint16 i =0 ;i < 1000;i++){
         Xaxis.append(i);
    }
    for(quint16 i =0 ;i < 50;i++){
         fftXaxis.append(i);
    }
    UI_init();
}

void functionui::UI_init()
{
    QGraphicsDropShadowEffect *shadow_effect = new QGraphicsDropShadowEffect(this);
        shadow_effect->setOffset(-10, 10);
        //阴影颜色
        shadow_effect->setColor(Qt::gray);
        //阴影半径
        shadow_effect->setBlurRadius(100);

//        QWidget *leftwidget = new QWidget();
//        leftwidget->setLayout(leftlayout);
////        leftwidget->setStyleSheet("border: 1px solid green;");
//        QHBoxLayout *lflayout = new QHBoxLayout();
//        lflayout->addWidget(leftwidget);
    QFrame *frame = new QFrame();
    frame->setFrameShape(frame->Box);
    frame->setFrameShadow(QFrame::Raised);
//    frame->setMidLineWidth(3);
    frame->setLineWidth(1);
//    frame->setFrameStyle(QFrame::Panel | QFrame::Sunken);
//    frame->setGraphicsEffect(shadow_effect);
//    frame->setFrameRect(QRect(20,20,60,60));
//    frame->setStyleSheet("background-color:cyan;");
    frame->setLayout(leftwidget());
//    frame->setStyleSheet("border-radius:1px;""border: 1px solid rgb(0,255,255);");
//    frame->setLineWidth(10);

//main layouot
//main layout
    QFrame *widget2 = new QFrame();
    widget2->setLayout( rightwidget());
    widget2->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    widget2->setLineWidth(1);
//    centralWidget()->setStyleSheet("background: rgb(120, 120, 12);");
//    widget1->setStyleSheet("background: rgb(50, 120, 12);");" border-width: 0px;"
//    widget2->setStyleSheet("background: rgb(70, 200, 12);""border: 2px solid white;");
//    widget2->setStyleSheet(("border: 10px solid red"));
    QHBoxLayout *hlayout = new QHBoxLayout(this);
    hlayout->addWidget(frame,1);
    hlayout->addWidget(widget2,3);
    hlayout->setSpacing(5);
//    hlayout->setStretchFactor(frame,1);
//    hlayout->setStretchFactor(widget2,3);

}
QVBoxLayout *functionui::leftwidget()
{
    //select layout
    QLabel *protoco = new QLabel("Potoco Select");
/*    realise the button menu method
    QPushButton *buttonmenu = new QPushButton();
    QMenu *menu_potoco = new QMenu();
    QAction *udp_potoco = new QAction("UDP",buttonmenu);
    QAction *tcpclic_potoco = new QAction("tcp_clict",buttonmenu);
    QAction *tcpserver_potoco = new QAction("tcp_server",buttonmenu);

    menu_potoco->addAction(udp_potoco);
    menu_potoco->addAction(tcpclic_potoco);
    menu_potoco->addAction(tcpserver_potoco);
    menu_potoco->setStyleSheet("background: rgb(120, 120, 12);");
    buttonmenu->setMenu(menu_potoco);
*/
    QComboBox *potoco_select = new QComboBox();
    potoco_select->addItem("UDP");
    potoco_select->addItem("TCP_SERVER");
    potoco_select->addItem("TCP_CLICK");

//    buttonmenu->addAction(udp_potoco);
    QHBoxLayout *selct_layout = new QHBoxLayout();
    selct_layout->addWidget(protoco);
     selct_layout->addWidget(potoco_select);
//     selct_layout->setSpacing(20);
     selct_layout->setStretchFactor(protoco,1);
     selct_layout->setStretchFactor(potoco_select,1);

    //ip and port ui
    QLabel *ip_label = new QLabel("IP");
    ip_label->setAlignment(Qt::AlignCenter);
    QLabel *port_label = new QLabel("PORT");
    port_label->setAlignment(Qt::AlignCenter);
    ip_linedit = new QLineEdit("239.0.0.2");//local physical ip:192.168.3.99
    port_linedit = new QLineEdit("8080");
/* test qrc usage
    QPushButton *button = new QPushButton();
    button->setIcon(QIcon(":/icon/redclose.png"));
*/
// ip & port layout
    QHBoxLayout *ip_port_layout = new QHBoxLayout();
    ip_port_layout->addWidget(ip_label);
    ip_port_layout->addWidget(ip_linedit);
    ip_port_layout->addWidget(port_label);
    ip_port_layout->addWidget(port_linedit);
    ip_port_layout->setSpacing(1);
    ip_port_layout->setStretchFactor(ip_label,1);
    ip_port_layout->setStretchFactor(ip_linedit,4);
    ip_port_layout->setStretchFactor(port_label,1);
    ip_port_layout->setStretchFactor(port_linedit,2);
    //simple rate
    QHBoxLayout *ratesimple = new QHBoxLayout();
    ratesimple = simpleratelayout();

//test pushbutton size
    testbutton = new QPushButton("RUN",this);
    testbutton->setIcon(QIcon(":/icon/redclose.png"));
//    testbutton->sizeHint();
//    testbutton->setChecked(true);
    testbutton->setAutoExclusive(true);
    testbutton->setCheckable(true);
    testbutton->setStyleSheet("QPushButton:checked{background-color: green;}");

    QHBoxLayout *testlayout = new QHBoxLayout();
    testlayout->addWidget(testbutton);
    testlayout->setAlignment(Qt::AlignHCenter);
//    testlayout->setStretch(0,2);
//    testlayout->setSpacing(20);
//    testlayout->setContentsMargins(50,0,50,0);
//    testlayout->setStretchFactor(testbutton,1);



//ui -- left layout
//ui -- left layout
//    QWidget *blank = new QWidget(this);
    showtext = new QTextEdit(this);
//    showtext->setPlainText("162");
//    showtext->setText("sheuhf");
    QVBoxLayout *leftlayout = new QVBoxLayout(this);
    leftlayout->addLayout(selct_layout);
    leftlayout->addLayout(ip_port_layout);
    leftlayout->addLayout(ratesimple);
//  leftlayout->addLayout(channellayout);
    leftlayout->addLayout(testlayout);
    leftlayout->addWidget(showtext);

    leftlayout->setStretchFactor(selct_layout,1);
    leftlayout->setStretchFactor(ip_port_layout,1);
    leftlayout->setStretchFactor(ratesimple,1);
//  leftlayout->setStretchFactor(channellayout,1);
    leftlayout->setStretchFactor(testlayout,1);
    leftlayout->setStretchFactor(showtext,1);
    leftlayout->setSpacing(5);
    leftlayout->setContentsMargins(0,5,0,0);
//    connect(testbutton,SIGNAL(clicked()),this,SLOT(threaddestroy()));
    connect(testbutton,SIGNAL(clicked()),this,SLOT(GetLocalIpandPort()));

    return leftlayout;
}
#include <QDebug>

QVBoxLayout *functionui::rightwidget()
{
    QWidget *widget = new QWidget;


    signalplot = new BasePlot("signal");
    fftplot = new BasePlot("fft");

    QHBoxLayout *selectplot = new QHBoxLayout();
    QCheckBox *fftbox = new QCheckBox("addfft");
    selectplot = chanellayout(fftbox);
    QVBoxLayout *vboxlayout = new QVBoxLayout;
    vboxlayout->addLayout(selectplot);
    vboxlayout->addWidget(signalplot);
     vboxlayout->addWidget(fftplot);

     fftplot->hide();


// the model of thread with slot
    sigthread = new signafftthread;
    sll_udp = new SLL_UDP;
    thread = new QThread(this);
    udpthread = new QThread(this);

    sll_udp->moveToThread(udpthread);
    sigthread->moveToThread(thread);
//    qDebug() <<"mainthread"<< QThread::currentThreadId();
    qRegisterMetaType<QVector<double>>("QVector<double>");
    qRegisterMetaType<quint16>("quint16");
    qRegisterMetaType<QString>("QString");
    qRegisterMetaType<bool>("bool");
    connect(this,&functionui::startthread,sigthread,&signafftthread::simpletest);
//    connect(sigthread,SIGNAL(signalwave(QVector<double>,QVector<double>)),this,SLOT(signalprintplot(QVector<double>, QVector<double>)));
    connect(this,&functionui::startudpthread,sll_udp,&SLL_UDP::dealmsgthread);
    fft = new sllFFT(1000);
    connect(this,SIGNAL(fftsignal(QVector<double>,QVector<double>)),this,SLOT(pushfftdata(QVector<double>, QVector<double>)));
    connect(fft,SIGNAL(processCompleted(QVector<double>,QVector<double>)),this,SLOT(fftslot(QVector<double>,QVector<double>)));
//    connect(this,SIGNAL(tanslateipandport(quint16,QString,bool)),sll_udp,SLOT(ParmetConfig(quint16,QString,bool)));
    connect(this,SIGNAL(destroyed()),this,SLOT(threaddestroy()));
    connect(this,SIGNAL(udpthreadstop(bool)),this,SLOT(udpthreadstopfun(bool)));

    connect(sll_udp,SIGNAL(sll_UdpMsg(QString)),this,SLOT(texteditshow(QString)));
//    connect(sll_udp,SIGNAL(sll_UdpMsg(quint8*)),this,SLOT(texteditshow(quint8*)));
    connect(sll_udp,SIGNAL(sll_UdpMsg(QVector<double>)),this,SLOT(texteditshow(QVector<double>)));
    emit startthread();
//    emit startudpthread();

    thread->start();

//    delete fftplot;
    return vboxlayout;
}
QHBoxLayout *functionui::simpleratelayout()
{
    QLabel *ratelabel = new QLabel("SimpleRate");
    ratelabel->setAlignment(Qt::AlignCenter);
    QComboBox *SimpleRate = new QComboBox();

   QStringList stringlist = {"1000","2000","3000"};

    SimpleRate->addItems(stringlist);
    QLineEdit *simpleline = new QLineEdit("1000");

    QHBoxLayout *simplelayout = new QHBoxLayout();
    simplelayout->addWidget(ratelabel);
    simplelayout->addWidget(simpleline);
    simplelayout->setStretchFactor(ratelabel,1);
    simplelayout->setStretchFactor(simpleline,1);

    return simplelayout;
}


QHBoxLayout *functionui::chanellayout(QCheckBox *fftbox)
{
      QHBoxLayout *returnlayout = new QHBoxLayout();
        QHBoxLayout *channellayout = new QHBoxLayout();
    // channel layout
        QCheckBox *chanelbox = new QCheckBox("chanel 1");
        checkboxstyle(chanelbox);
        channellayout->addWidget(chanelbox);
        channellayout->setAlignment(Qt::AlignRight);
        QHBoxLayout *addfftlayout = new QHBoxLayout;
//        fftbox = new QCheckBox();
        checkboxstyle(fftbox);
        addfftlayout->addWidget(fftbox);
        addfftlayout->setAlignment(Qt::AlignRight);

//    returnlayout->addLayout(channellayout);
//    returnlayout->addLayout(addfftlayout);

    QCheckBox *chanel2box = new QCheckBox("chanel 2");
    QCheckBox *chanel3box = new QCheckBox("chanel 3");

    checkboxstyle(chanel2box);
    checkboxstyle(chanel3box);
    returnlayout->addWidget(chanelbox);
    returnlayout->addWidget(chanel2box);
    returnlayout->addWidget(chanel3box);
    returnlayout->addWidget(fftbox);
    returnlayout->setAlignment(Qt::AlignLeft);


   connect(fftbox,&QCheckBox::stateChanged,this ,[=]{
       if(!fftbox->isChecked()) fftplot->hide();
       else fftplot->show();
   });
    connect(chanel3box,&QCheckBox::stateChanged,this ,[=]{
        if(chanel3box->isChecked()){
            curve = new QwtPlotCurve("curve");
            signalplot->AttachPlotCurve(curve,QPen(Qt::red));
            curve->show();
            showchanel1sign = true;
            qDebug() << "curve chanel1 show";
        }
        else {
            showchanel1sign = false;
            curve->hide();
            delete  curve;
            qDebug() << "curve chanel1 hide";
        }
    });
    connect(chanel2box,&QCheckBox::stateChanged,this ,[=]{
        if(chanel2box->isChecked()){
            chanel2curve = new QwtPlotCurve("chanel 2");
            signalplot->AttachPlotCurve(chanel2curve,QPen(Qt::green));
            chanel2curve->show();
            showchanel2sign = true;
            qDebug() << "curve chanel2 show";
        }
        else {
            showchanel2sign = false;
            chanel2curve->hide();
            delete  chanel2curve;
            qDebug() << "curve chanel2 hide";
        }
    });

    connect(chanelbox,&QCheckBox::stateChanged,this ,[=]{
        if(chanelbox->isChecked()){
            chanel3curve = new QwtPlotCurve("chanel 1");
            signalplot->AttachPlotCurve(chanel3curve,QPen(Qt::blue));
            chanel3curve->show();
            showchanelsign = true;
            qDebug() << "curve chanel show";
        }
        else {
            showchanelsign = false;
            chanel3curve->hide();
            delete  chanel3curve;
            qDebug() << "curve chanel hide";
        }
    });
     chanelbox->setChecked(true);
     chanel2box->setChecked(true);
     chanel3box->setChecked(true);
    return returnlayout;
}



void functionui::checkboxstyle(QCheckBox *box)
{
    box->setStyleSheet("QCheckBox::indicator {width: 22px; height: 22px;}"
                       "QCheckBox::indicator:checked {image: url(:/icon/redselct.jpg);}");
}

void functionui::signalprintplot(QVector<double> x, QVector<double> y)
{
    signalplot->plotwave(x,y);
}

void functionui::pushfftdata(QVector<double>, QVector<double> y)
{
    fft->pushdata(y);
}

void functionui::fftslot(QVector<double> x, QVector<double> y)
{
    fftplot->plotwave(fftXaxis,y);
}

void functionui::threaddestroy()
{
    qDebug() << "testbutton";
    thread->quit();
    thread->wait();
}

void functionui::texteditshow(QString str)
{
    showtext->insertPlainText(str);
    showtext->insertPlainText("\n");
}

void functionui::texteditshow(quint8 *value)
{
    qDebug() << *value;
    QString str;
    for(quint16 i = 0; i < 5; i ++){
        str.append(*(value+i));
    }
    showtext->insertPlainText(str);
    showtext->insertPlainText("\n");
}
void functionui::texteditshow(QVector<double> value)
{
    Yaxis.append(value);
    if(Yaxis.size() >= 980)
        Yaxis.remove(0,20);
   emit fftsignal(Xaxis, Yaxis);
//    qDebug() << Yaxis.size();
    if(showchanel1sign) curve->setSamples(Xaxis,Yaxis);
    if(showchanel2sign) chanel2curve->setSamples(Xaxis,Yaxis);
    if(showchanelsign) chanel3curve->setSamples(Xaxis,Yaxis);
//   signalplot->plotwave(Xaxis,Yaxis);
    signalplot->plotcurve();
}

void functionui::GetLocalIpandPort()
{

    static bool flag = 0;

    if(flag == 0)
    {
        flag = 1;
        QString ip_str = ip_linedit->text();
        quint16 port = port_linedit->text().toInt();

        testbutton->setStyleSheet("QPushButton:checked{background-color: red;}");
        sll_udp->ParmetConfig(port,ip_str,flag);
        udpthread->start();
        emit startudpthread();
        qDebug() << "translate ip and  port" ;
    }
    else{
        flag = 0;
//        QString ip_str = ip_linedit->text();
//        quint16 port = port_linedit->text().toInt();
        emit udpthreadstop(flag);
    }
}

void functionui::udpthreadstopfun(bool flag)
{
    sll_udp->setstartfalg(flag);
    udpthread->quit();
//    udpthread->wait();
}
