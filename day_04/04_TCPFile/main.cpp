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
//服务端
//按钮：选择、发送
//  注意：
//      1.只有当连接建立好后，选择按钮才有效
//      2.当文件被成功过打开后，发送按钮才有效
//      3.每次发送完毕后，与客户端主动断开连接
//      4.发送时，防止TCP的粘包，需要先发送头部信息，再发送文件信息
//          利用定时器，发送完头部信息20ms后，再发送文件信息
//


//客户端
//  注意：
//      1.每次接收完毕，与服务端主动断开连接
//      2.所以每次发送文件前，都需要与服务端主动建立连接
//      3.先接收头部信息，再接收正文信息
