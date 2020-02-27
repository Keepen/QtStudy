#include "mywidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyWidget w;
    w.show();
    return a.exec();
}

//在单任务进程中
//使用线程函数--sleep可能会导致进程无法响应
//  比如此例中，点击完毕开始计时，但是由于其中有复杂的数据处理
//  导致计时器无法及时，任务完成直接将计时器结束

//采用线程解决此类问题：
//  1.将数据任务的处理放在 线程中
//  2.任务处理完毕向窗口发送信号 -- 做出关闭计时器的动作
//  3.回收线程资源 -- 当点击窗口关闭按钮时，触发信号--回收线程资源

