#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}


//展示win上编程的要求：
//几个部分：菜单栏、工具栏、状态栏、核心控件、浮动窗口
// 需要添加几个头文件：
//1.菜单栏：
//  QMenuBar
//  QMenu
//2.工具栏：
//  QToolBar
//3.状态栏：
//  QStatusBar
//  QLabel
//4.核心控件：
//  QTextEdit
//5.浮动窗口：
//  QDockWidget

//这些函数的用法与之前的QPushButton大同小异
//定义动态对象-->指定父对象-->执行功能
