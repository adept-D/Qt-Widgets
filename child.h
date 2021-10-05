#ifndef CHILD_H
#define CHILD_H

#include <QWidget>

class Child : public QWidget
{
    Q_OBJECT

public:
    explicit Child(QWidget *parent = nullptr);

private:
    QTimer* timer;
signals:
    void killed();
private slots:
    void deleteWidget();
};

#endif // CHILD_H
