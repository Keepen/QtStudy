#include "mainwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWidget w;
    w.show();
    return a.exec();
}


/*复习上节课的连个窗口显示隐藏的功能
 * 信号可以重载：根据参数的不同做出不同的行为
 * 重载信号可以采取的调用方式：
 *  1）Qt4中只要信号都用signals关键字声明，槽函数都用slots声明，那么会有匹配项
 *  2）利用函数指针来调用
 * Lambda表达式：将信号所出发的行为全部写到Lambda表达式内部，
 * 不再专门写信号于槽函数
*/
