#include "mywidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyWidget w;
    w.show();
    return a.exec();
}

//学习事件的定义以及事件触发的行为
//类似于中断 -- 软件中断、硬件中断

//事件的传递：
//  1.当事件被接收后，事件不再向下传递  e->accept();
//  2.当忽略事件，事件传递到其父组件   e->ignore();


//event函数：
//我们将事件的处理可以只放在event函数内部，对需要转换的类型进行强制类型转换即可
//不在需要重写所有事件的函数了。
//通过e->type()来判断此时是什么事件
//只需要重写event函数，event函数返回值是bool
//  1.true代表事件不再传播
//  2.false代表事件继续传播


//事件过滤器
//对特定事件进行操作或者忽略
//可以将事件的处理都放在事件过滤器函数中


