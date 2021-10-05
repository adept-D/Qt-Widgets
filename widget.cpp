#include "widget.h"
#include <QApplication>
#include <QScreen>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    brush = new QBrush;
    pallete = new QPalette;
    timer = new QTimer();

    brush->setTextureImage(QImage(":/img/img/1.jpg"));
    pallete->setBrush(QPalette::Window,*brush);

    this->setPalette(*pallete);

    connect(timer, &QTimer::timeout, this, &Widget::changeBackgoundColor);

    timer->setInterval(10000);
    timer->start();

}

void Widget::changeBackgoundColor(){
    pallete->setBrush(QPalette::Window,Qt::blue);
    this->setPalette(*pallete);
   // timer->stop();
    disconnect(timer,&QTimer::timeout,this,&Widget::changeBackgoundColor);
    QTimer::singleShot(5000,this,&Widget::changeTitle);
   // emit changedBackgroundColor();
}

void Widget::changeTitle(){

    this->setWindowTitle(QObject::tr("Первая лабораторная работа"));
    QTimer::singleShot(5000,this,&Widget::changePosition);
}

void Widget::changePosition(){
    QSize s = QApplication::primaryScreen()->geometry().size();


    this->setGeometry(s.width()-600,s.height()-400,600,400);
}

Widget::~Widget()
{
    timer->deleteLater();
    delete brush;
    delete pallete;
}

