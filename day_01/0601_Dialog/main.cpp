#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}


//学习了问题对话框、关于对话框、文件对话框
//调用对应函数即可
//文件对话框可以设定筛选条件，在Lambda表达式内，加限定条件即可
//
