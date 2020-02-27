#include "mythread.h"

MyThread::MyThread(QObject *parent) : QThread(parent)
{

}

void MyThread::run(){
    //用睡觉函数来代替很复杂的数据处理所需耗时
    sleep(5);

    emit isDone();  //任务处理完毕，发送信号
}
