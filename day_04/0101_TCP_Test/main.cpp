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

//TCP通信的练习

//客户端先和服务端建立连接
//服务端在已经建立好连接的套接字中取出进行通信
//




