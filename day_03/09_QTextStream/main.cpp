#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}

//写文本时
//  和向数据流中写数据一样


//读文本时
//  需要注意不能按照之前DataStream那样读
//  必须按照文本方式进行读，否则会把文本中的字符与数字同意当作字符处理
