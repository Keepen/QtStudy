#include "clientwidget.h"
#include "ui_clientwidget.h"
#include <QHostAddress>

ClientWidget::ClientWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientWidget)
{
    ui->setupUi(this);

    //将指针先置空
    tcpSocket = nullptr;

    setWindowTitle("Client");

    tcpSocket = new QTcpSocket(this);
    connect(tcpSocket, &QTcpSocket::connected,
            [=](){
        ui->textEditRead->append("Connected OK!!!");

    }
    );

    //接收数据
    connect(tcpSocket, &QTcpSocket::readyRead,
            [=](){
        QString str = tcpSocket->readAll();
        ui->textEditRead->append(str);
    }
    );

}

ClientWidget::~ClientWidget()
{
    delete ui;
}

void ClientWidget::on_buttonClose_clicked()
{
    tcpSocket->disconnectFromHost();
}

void ClientWidget::on_buttonSend_clicked()
{
    if(tcpSocket == nullptr){
        ui->textEditRead->setText("Disonnect!!!");
        return;
    }
    QString str = ui->textEditWrite->toPlainText();

    tcpSocket->write(str.toUtf8().data());
}

void ClientWidget::on_buttonConnect_clicked()
{
    QString ip = ui->lineEditIP->text();
    qint16 port = ui->lineEditPort->text().toInt();

    tcpSocket->connectToHost(QHostAddress(ip), port);

}
