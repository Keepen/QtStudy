#include "mywidget.h"
#include "ui_mywidget.h"
#include <QThread>
#include <QDebug>

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    myTimer = new QTimer(this);
    //分配空间
    thread = new MyThread(this);

    //只要定时器启动自动触发timeout()

    connect(myTimer, &QTimer::timeout, this, &MyWidget::dealTime);

    connect(thread, &MyThread::isDone, this, &MyWidget::dealThread);

    //当点击窗口关闭按钮时，触发回收线程资源函数
    connect(this, &MyWidget::destroyed, this, &MyWidget::dealDestroy);

}

void MyWidget::dealDestroy(){
    thread->quit();     //关闭线程

    thread->wait();     //等待线程处理完毕手头工作， 再关闭。
}

void MyWidget::dealTime(){
    static int i = 0;
    i++;
    //设置LCD的值
    ui->lcdNumber->display(i);
}


MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::dealThread(){
    qDebug() << "Done";
    myTimer->stop();    //关闭定时器
}

void MyWidget::on_pushButton_clicked()
{
    //如果定时器没有工作，才启动
    if(myTimer->isActive() == false){
        myTimer->start(100);
    }

    //启动线程来处理任务
    thread->start();



//    //非常复杂的数据处理， 耗时较长
//    QThread::sleep(5);      //睡上5秒钟

//    //处理完数据后， 关闭定时器
//    myTimer->stop();
//    qDebug() << "over";
}






