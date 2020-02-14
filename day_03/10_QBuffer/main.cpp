#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}

//对内存文件的读写
//与前面数据流，文本流操作相似
//  不过Buffer本身就是内存文件，所以不必再定义文件
