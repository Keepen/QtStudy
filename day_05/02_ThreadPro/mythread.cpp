#include "mythread.h"
#include <QDebug>
#include <QMessageBox>


MyThread::MyThread(QObject *parent) : QObject(parent)
{
    isStop = false;
}


void MyThread::myTimeOut(){
    while(isStop == false){
        QThread::sleep(1);
        emit mySignal();
        //QMessageBox::aboutQt(NULL);       //会报错，不能调用
        qDebug() << "子线程：" << QThread::currentThread(); //打印子线程号
        if(isStop == true){
            break;
        }
    }
}

void MyThread::setFlag(bool flag){
    isStop = flag;
}
