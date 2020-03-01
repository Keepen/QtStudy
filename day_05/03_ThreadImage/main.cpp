#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}

//点击按钮完成绘图操作 -- 在线程中完成
//  1.自定义线程对象
//  2.在主窗口中为声明的线程对象分配空间，自定义的对象不能指定父对象 --
//              会导致两个任务在同一个线程中，任务崩溃
//  3.按下按钮 -- 主窗口向子类发送信号 -- 画图
//  4.子类又向主窗口发送信号得到子线程绘图结果后刷新窗口内容
//  5.在最后，关闭窗口的时候 -- 释放线程资源
//  6.尤其注意的是 -- 自定义线程对象没有指定父对象， 需要手动释放资源



