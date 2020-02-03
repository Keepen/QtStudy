#include "mainwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWidget w;


    w.show();
    return a.exec();
}

/*实现功能：两个窗口 -- 主窗口boss，子窗口bro
 * 点击一个，隐藏并显示另一个窗口
 *
 * 实现：在主窗口头文件中包含子窗口头文件 -- 主窗口成员中加入子窗口对象成员
 *
 * 问题：
 * 显示子窗口简单 -- 直接让该窗口关闭，显示其成员w的窗口即可
 * 显示主窗口不易 -- 子窗口中没有办法调用主窗口的显示函数
 *  采用信号与槽机制
 *      1）松开按钮的操作我们将其定义为 -- 向主窗口发送信号
 *      2）主窗口只需要接受这个信号，并且定义好接受该信号的槽函数即可
*/

