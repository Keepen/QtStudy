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
