#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QMouseEvent>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //去除窗口的边框
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());

    //把窗口背景设置为透明
    setAttribute(Qt::WA_TranslucentBackground);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *){
    QPainter p(this);
    p.drawPixmap(0, 0, QPixmap("../image/mask.png"));

}

void Widget::mouseMoveEvent(QMouseEvent *e){
    //按下左键
    if(e->buttons() == Qt::LeftButton){
        move(e->globalPos() - p);
        //相当于让当前点击的坐标回归到窗口左上角，
        //接下来移动就是按照窗口左上角为坐标原点进行移动
    }
}

void Widget::mousePressEvent(QMouseEvent *e){
    if(e->button() == Qt::RightButton){
        close();
    }
    else if(e->button() == Qt::LeftButton){
        //求坐标差值
        //当前点击坐标 - 窗口左上角坐标
        p = e->globalPos() - this->frameGeometry().topLeft();
    }
}








