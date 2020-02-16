#include "serverwidget.h"
#include "clientwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ServerWidget w;
    ClientWidget w2;


    w2.show();
    w.show();
    return a.exec();
}

//套接字编程

//1.服务端
//  两个套接字
//      1）监听套接字
//      2）通信套接字 -- 建立连接
//  用建立好连接的套接字来进行通信
//  发送：
//  接收：


//2.客户端
//  一个套接字
//      通信套接字：获取服务端的IP、端口号，建立连接
//  发送：
//  接收：

