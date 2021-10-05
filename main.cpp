#include "widget.h"

#include <QApplication>
#include <QGridLayout>
#include <QLabel>
#include <QMouseEvent>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget* w = new Widget;

    w->setMinimumSize(768,600);

    QGridLayout* grid = new QGridLayout(w);


    {
        QWidget * plb = new QWidget;
        plb->setCursor(Qt::CrossCursor);
        plb->setStyleSheet("QWidget{background-color: yellow;}");
        grid->addWidget(plb, 0,0,1,3);
    }
    {
        QWidget * plb = new QWidget;
        plb->setCursor(Qt::WaitCursor);
        plb->setStyleSheet("QWidget{background-color: green;}");
        grid->addWidget(plb, 0,3,5,1);
    }
    {

        QWidget * plb = new QWidget;
        plb->setCursor(Qt::OpenHandCursor);
        plb->setStyleSheet("QWidget{background-color: blue;}");
        grid->addWidget(plb, 1,0,4,2);
    }
    {
        QWidget * plb = new QWidget;
        plb->setCursor(Qt::ForbiddenCursor);
        plb->setStyleSheet("QWidget{background-color: gray;}");
        grid->addWidget(plb, 1,2,2,1);
    }
    {
        QWidget * plb = new QWidget;
        plb->setCursor(Qt::WhatsThisCursor);
        plb->setStyleSheet("QWidget{background-color: gray;}");
        grid->addWidget(plb, 3,2,2,1);
    }

    w->show();
    return a.exec();
}
