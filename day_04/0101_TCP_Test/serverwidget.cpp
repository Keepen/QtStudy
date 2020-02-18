#include "serverwidget.h"
#include "ui_serverwidget.h"

ServerWidget::ServerWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ServerWidget)
{
    ui->setupUi(this);

    //先将两个指置空，防止内存泄漏
    tcpSocket = nullptr;
    tcpServer = nullptr;

    setWindowTitle("Server: 8888");

    //指定父对象，由于QT的对象树机制，可以自动回收内存
    tcpServer = new QTcpServer(this);
    tcpServer->listen(QHostAddress::Any, 8888); //IP任意，端口8888
    connect(tcpServer, &QTcpServer::newConnection,
            [=](){
        //将建立好链接的套接字拿出来进行通信
        tcpSocket = tcpServer->nextPendingConnection();

        //获取客户端的ip 和 端口地址
        QString ip = tcpSocket->peerAddress().toString();
        qint16 port = tcpSocket->peerPort();

        QString str = QString("[%1 : %2]: connect OK！！！").arg(ip).arg(port);

        ui->textEditRead->append(str);

        //接收数据
        connect(tcpSocket, &QTcpSocket::readyRead,
                [=](){
            QString data = tcpSocket->readAll();
            ui->textEditRead->append(data);
        }
        );

    }
    );


}

ServerWidget::~ServerWidget()
{
    delete ui;
}


void ServerWidget::on_buttonSend_clicked()
{
    if(tcpSocket == nullptr){
        ui->textEditRead->setText(QString("连接已断开！！！"));
        return;
    }
    //获取编辑区内容
    QString str = ui->textEditWrite->toPlainText();

    //给客户端发送数据
    tcpSocket->write(str.toUtf8().data());
}

void ServerWidget::on_buttonClose_clicked()
{
    tcpSocket->disconnectFromHost();
    tcpSocket->close();
}















