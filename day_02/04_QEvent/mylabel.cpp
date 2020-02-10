#include "mylabel.h"
#include <QMouseEvent>
#include <QDebug>

MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{
    //设定鼠标进入界面即有效 -- 否则点击才有效
    this->setMouseTracking(true);
}

void MyLabel::mousePressEvent(QMouseEvent *ev){
    int i = ev->x();
    int j = ev->y();
    //sprintf 效果等同于下面
    /*
     * QString str = QString("abc %1 bb %2").arg(123).arg("hehe");
     * str = abc 123 bb hehe
    */

    if(ev->button() == Qt::LeftButton){
        qDebug() << "left";
    }
    else if(ev->button() == Qt::RightButton){
        qDebug() << "right";
    }
    else if(ev->button() == Qt::MiddleButton){
        qDebug() << "middle";
    }
    QString text = QString("<center><h1>MousePress: (%1, %2)</h1></center>").arg(i).arg(j);
    this->setText(text);
}

void MyLabel::mouseReleaseEvent(QMouseEvent *ev){
    QString text = QString("<center><h1>MouseRelease: (%1, %2)</h1></center>").arg(ev->x()).arg(ev->y());
    this->setText(text);
}

void MyLabel::mouseMoveEvent(QMouseEvent *ev){
    //QString text = QString("<center><h1>MouseMove: (%1, %2)</h1></center>").arg(ev->x()).arg(ev->y());
    //this->setText(text);
}


void MyLabel::enterEvent(QEvent *ev){
    QString text = QString("<center><h1>MouseEnter!!!</h1></center>");
    this->setText(text);
}

void MyLabel::leaveEvent(QEvent *ev){
    QString text = QString("<center><h1>MouseLeave!!!</h1></center>");
    this->setText(text);
}

