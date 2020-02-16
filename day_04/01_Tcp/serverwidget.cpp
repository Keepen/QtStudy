#include "serverwidget.h"
#include "ui_serverwidget.h"

ServerWidget::ServerWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ServerWidget)
{
    ui->setupUi(this);

    tcpServer = nullptr;
    tcpSocket = nullptr;


    //监听套接字
    tcpServer = new QTcpServer(this);   //指定父对象 -- 自动回收空间

    tcpServer->listen(QHostAddress::Any, 8888);

    setWindowTitle("Server: 8888");

    connect(tcpServer, &QTcpServer::newConnection,
            [=](){
                //取出建立好链接的套接字
                tcpSocket = tcpServer->nextPendingConnection();

                //获取对方的ip， 和端口
                QString ip = tcpSocket->peerAddress().toString();
                qint16 port = tcpSocket->peerPort();
                QString tmp = QString("[%1 : %2]:connect OK").arg(ip).arg(port);

                ui->textRead->setText(tmp);

                //接受数据
                connect(tcpSocket, &QTcpSocket::readyRead,
                        [=](){
                            //从通信套接字取出内容
                            QByteArray array = tcpSocket->readAll();
                            ui->textRead->append(array);
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
        return;
    }
    //获取编辑区内容
    QString str = ui->textWrite->toPlainText();

    //给对方发送数据,使用套接字是tcpSocket
    tcpSocket->write(str.toUtf8().data());


}


void ServerWidget::on_buttonClose_clicked()
{
    //主动和客户端断开连接
    tcpSocket->disconnectFromHost();
    tcpSocket->close();
}












