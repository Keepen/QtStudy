#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

//利用ui进行设计
//利用可视化编辑来替代之前的函数操作
//常用控件的使用
