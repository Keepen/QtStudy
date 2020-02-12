#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}

//QPixmap:  针对屏幕进行优化了，与平台相关，不能对图片进行修改
//QImage:   和平台无关，可以对图片进行修改 -- 在线程中绘图
//QPicture: 保存绘图的状态（二进制文件）
