#include "widget.h"
#include "client.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    Client w2;
    w2.show();
    w.show();
    return a.exec();
}

//udp通信过程

//对端ip、port
//即可发送/接收数据
//  1.动态分配空间，指定父对象
//  2.绑定IP、port
//  3.建立连接，利用槽函数/lambda表达式进行数据的处理

//  发送数据：
//      1.获取对端ip、port
//      2.获取编辑区内容
//      3.发送数据



