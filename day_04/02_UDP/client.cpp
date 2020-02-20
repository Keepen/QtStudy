#include "client.h"
#include "ui_client.h"

Client::Client(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);

    udpSocket = new QUdpSocket(this);

    setWindowTitle("9000");

    QString ip = ui->lineEditIP->text();
    udpSocket->bind(QHostAddress(ip),9000);

    connect(udpSocket, &QUdpSocket::readyRead,
            [=](){
        char buf[1024] = {0};
                QHostAddress server;
                quint16 port;
                qint64 len = udpSocket->readDatagram(buf, sizeof(buf),
                               &server, &port);
                if(len > 0){
                    QString str = QString("[%1 : %2] %3")
                            .arg(server.toString())
                            .arg(port)
                            .arg(buf);
                    ui->textEdit->setText(str);
                }
            }
            );
}

Client::~Client()
{
    delete ui;
}

void Client::on_buttonSend_clicked()
{
    QString ip = ui->lineEditIP->text();
    quint16 port = ui->lineEditPort->text().toUInt();

    QString str = ui->textEdit->toPlainText();
    udpSocket->writeDatagram(str.toUtf8(), QHostAddress(ip), port);

}











