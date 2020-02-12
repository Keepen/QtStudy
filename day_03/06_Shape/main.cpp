#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}

//不规则图形
//  1.去除窗口边框
//  2.移动，需要将坐标统一 -- 坐标差值 == 点击坐标 - 窗口左上角的坐标
//  3.移动时，将当前点击坐标 - 插值即可得到理想的效果
