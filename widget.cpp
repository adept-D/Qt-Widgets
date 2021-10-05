#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setMouseTracking(true);
}

void Widget::mouseMoveEvent(QMouseEvent* e){
    QPoint p = e->pos();
    QString makeText = "X: " + QString::number(p.x()) + " " + "Y: " + QString::number(p.y());

    this->setWindowTitle(makeText);
}

Widget::~Widget()
{
}

