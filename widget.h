#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>

class Widget : public QWidget
{
    Q_OBJECT
private:
    QBrush *brush;
    QPalette  *pallete;
    QTimer *timer;
private slots:
    void changeBackgoundColor();
    void changeTitle();
    void changePosition();

signals:
    void changedBackgroundColor();
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
};
#endif // WIDGET_H
