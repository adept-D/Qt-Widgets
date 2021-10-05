#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    h = new QHBoxLayout;
    greenWindow = new QWidget;
    redWindow = new QWidget;
    splitter = new QSplitter;

    setPropertyWidget(greenWindow,Qt::green);
    setPropertyWidget(redWindow,Qt::red);

    greenWindow->installEventFilter(this);
    redWindow->installEventFilter(this);

    splitter->setOrientation(Qt::Horizontal);
    splitter->addWidget(greenWindow);
    splitter->addWidget(redWindow);

    h->addWidget(splitter);

    connect(this,SIGNAL(resizeChild(int,int,int)),this,SLOT(changeMainWidgetTitle(int,int,int)));
    connect(this,&Widget::closeWidgetChild,this,&Widget::changeToStandartTitle);

    this->setLayout(h);
}

void Widget:: setPropertyWidget(QWidget* w, const QColor &color){
    QPalette palette;
    palette.setColor(QPalette::Background,color);
    w->setCursor(Qt::PointingHandCursor);
    w->setAutoFillBackground(true);
    w->setPalette(palette);
}

bool Widget::eventFilter(QObject *target, QEvent *e){
    qDebug() << e->type() << "\n";
    if(target == greenWindow && e->type() == QEvent::MouseButtonRelease ){
            QMouseEvent *key = static_cast<QMouseEvent *>(e);
            if(key->button() == Qt::MouseButton::LeftButton ){
                child = new Child;
                connect(child,&Child::killed,this,&Widget::popedVectorChild);
                child->installEventFilter(this);
                childs.push_back(child);
                child->show();
                return true;
            }

    }
    else if(target == redWindow && e->type() == QEvent::MouseButtonRelease ){
        QMouseEvent *key = static_cast<QMouseEvent *>(e);
        if(key->button() == Qt::MouseButton::LeftButton){
            if(childs.size() - 1 >= 0){
               delete childs.at(childs.size() - 1); //->deleteLater()
                childs.pop_back();
                emit closeWidgetChild();
                return true;
            }else{
                return false;
            }
        }
    }
     else if( isCheckedChildOnVector(target, childs) ){
         QWidget* w = (QWidget*)target;
         emit resizeChild(w->geometry().width(), w->geometry().height(),w->geometry().width() * w->geometry().height());
         if(e->type() == QEvent::UpdateRequest ){
             QCloseEvent *key = static_cast<QCloseEvent *>(e);
             if(key->isAccepted()){
                 emit closeWidgetChild();
             }
         }
         return true;
    }

    return false;
}

bool Widget:: isCheckedChildOnVector(QObject* child,  QVector<Child *> &childs){
    for(int i=0; i < childs.size();i++){
        QString makeStr = typeid (childs.at(i)).name();
        makeStr.remove(0,1);
        if(QString(typeid (*child).name()) == makeStr.toStdString().c_str()){

            return true;
        }
    }

    return false;
}

void Widget:: changeToStandartTitle(){
    this->setWindowTitle("task3");
}

void Widget::popedVectorChild()
{
    if(childs.size() > 0){
        childs.pop_back();
    }
}



void Widget:: closeEvent(QCloseEvent* e){

    if (e->isAccepted()){
        for(int i = childs.size() - 1; i > -1; i--){
          delete childs.at(i);
        }
        Widget::close();
    }
}

void Widget::changeMainWidgetTitle(int w, int h, int square){
    QString titleText = "W: " + QString::number(w) + " " + "H: " + QString::number(h) + " " + "S = " + QString::number(square);
    this->setWindowTitle(titleText);

}



Widget::~Widget()
{

}

