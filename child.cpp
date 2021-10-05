#include "child.h"
#include <QTimer>

Child::Child(QWidget *parent) : QWidget(parent)
{
    timer = new QTimer;
    connect(timer, &QTimer::timeout, this, &Child::deleteWidget);
    timer->start(5000);

}

void Child::deleteWidget()
{
    timer->stop();
    emit killed();
    delete this;

}



