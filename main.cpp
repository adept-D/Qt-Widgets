#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget* w = new Widget;
    w->setMinimumSize(768,640);
    w->show();
    return a.exec();
}
