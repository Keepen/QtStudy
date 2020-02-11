#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}

//了解绘图：
//利用PixMap进行绘图
//  当有动态需要时，需要进行对窗口的重绘
//  当窗口状态改变时，需要进行重绘（点击了某个按钮等）

//绘图的两种方式：
//void paintEvent(QPaintEvent*)函数的重写，
//  1.QPainter p(this) -- 指定当前画家的操作对象是本窗口
//  2.QPainter p;
//      p.begin(this);
//      ...绘图操作
//      p.end();

//重绘刷新函数update() -- 即调用了paintEvent函数
//  所以更新函数不可以写在paintEvent函数内，会引发无穷递归
