#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}

//QPixmap于QImage之间的转换
//  都利用画家来进行绘图
//  pixmap.toImage()    -- 转换为image
//  fromImage(...)      -- 转换为Pixmap
//  在调用相应的函数，drawPixmap 或者 drawImage
