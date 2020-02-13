#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}

//Qt文件操作：读 / 写文件
//需要注意的是：
//  1.平台的编码：默认只识别utf8编码
//  2.char* 和 QString 可以通过QByteArray进行转换
