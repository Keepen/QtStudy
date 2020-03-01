#include "widget.h"
#include "ui_widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //自定义线程对象分配空间， 不可以指定父对象
    myT = new MyThread;

    //创建子线程
    thread = new QThread(this);

    //把自定义的线程加入到自从线程中去
    myT->moveToThread(thread);

    //启动子线程，但是没有启动线程处理函数
    thread->start();

    //线程处理函数必须通过 signal - slot进行操作
    connect(ui->pushButton, &QPushButton::clicked, myT, &MyThread::drawImage);
    connect(myT, &MyThread::updataImage, this, &Widget::getImage);

    connect(this, &Widget::destroyed, this, &Widget::dealClose);
}

void Widget::dealClose(){
    thread->quit();
    thread->wait();
}

void Widget::getImage(QImage temp){
    image = temp;
    update();   //更新窗口， 间接调用paintevent

}



void Widget::paintEvent(QPaintEvent *event){
    QPainter p(this);       //指定绘图设备是窗口
    p.drawImage(50, 50, image);

}



Widget::~Widget()
{
    delete myT;
    delete ui;
}


