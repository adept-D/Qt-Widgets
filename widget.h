#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QSplitter>
#include <QKeyEvent>
#include <QDebug>
#include <QCloseEvent>
#include "child.h"

class Widget : public QWidget
{
    Q_OBJECT
private:
    QHBoxLayout* h;
    QWidget* redWindow;
    QWidget* greenWindow;
    QSplitter* splitter;
    Child* child = nullptr;
    QVector<Child*> childs;
    bool isCheckedChildOnVector(QObject*, QVector<Child*>&);
    void setPropertyWidget(QWidget*,const QColor&);
    bool eventFilter(QObject *target, QEvent* e);
    void closeEvent(QCloseEvent* e);
signals:
    void resizeChild(int,int,int);
    void closeWidgetChild();
private slots:
    void changeMainWidgetTitle(int, int, int );
    void changeToStandartTitle();
    void popedVectorChild();
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

};
#endif // WIDGET_H
