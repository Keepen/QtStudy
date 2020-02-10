#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyleSheet("QLabel{color:red}");
    Widget w;

    w.show();
    return a.exec();
}


//Qt的样式表：
//利用setStyleSheet函数来进行修改
//  背景颜色、背景图片等
