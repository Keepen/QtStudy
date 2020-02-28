#include "mywidget.h"
#include "ui_mywidget.h"
#include <QDebug>
#define cout qDebug()

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    //动态分配空间，不能指定父对象
    myT = new MyThread;

    //创建子线程
    thread = new QThread(this);

    //把自定义的线程加入到子线程中
    myT->moveToThread(thread);

    connect(myT, &MyThread::mySignal, this, &MyWidget::dealSignal);

    cout << "主线程：" << QThread::currentThread(); //打印主线程号

    connect(this, &MyWidget::startThread, myT, &MyThread::myTimeOut);

    connect(this, &MyWidget::destroyed, this, &MyWidget::dealDestroyed);

    //线程处理函数内部不允许操作图形界面


}
MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::dealDestroyed(){
    on_buttonStop_clicked();
    delete myT;
}


void MyWidget::dealSignal(){
    static int i = 0;
    ++i;
    ui->lcdNumber->display(i);
}


void MyWidget::on_buttonStart_clicked()
{
    if(thread->isRunning() == true){
        return;
    }

    //启动线程，但是没有启动线程处理函数
    thread->start();
    myT->setFlag(false);
    //不能直接调用线程处理函数
    //直接调用会导致 -- 线程处理函数和主线程在同一个线程中， 任务无法执行
    //只能通过信号与槽进行调用

    emit startThread();
}


void MyWidget::on_buttonStop_clicked()
{
    if(thread->isRunning() == false){
        return;
    }
    myT->setFlag(true);
    thread->quit();
    thread->wait();
}






