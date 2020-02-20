#include "widget.h"
#include "ui_widget.h"
#include <QHostAddress>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //分配空间；指定父对象 -- 自动回收内存
    udpSocket = new QUdpSocket(this);

    //绑定任何的ipv4地址
    udpSocket->bind(QHostAddress::AnyIPv4,8888);

    //加入某个组播
    //组播地址是D类地址
    udpSocket->joinMulticastGroup(QHostAddress("224.0.0.2"));
    //退出组播
    //udpSocket->leaveMulticastGroup(QHostAddress(ip));



    setWindowTitle("8888");

    //当对方成功发送数据过来，自动触发readyRead信号
    connect(udpSocket, &QUdpSocket::readyRead, this, &Widget::dealMessage);


}

void Widget::dealMessage(){
    //先读取对方发送的内容
    char buf[1024] = {0};
    QHostAddress client;    //对端ip
    quint16 port;            //对端port
    qint64 len = udpSocket->readDatagram(buf, sizeof(buf), &client, &port);

    if(len > 0){
        //字符串格式化
        QString str = QString("[%1 : %2] %3").arg(client.toString())
                .arg(port)
                .arg(buf);
        //给编辑区设置内容
        ui->textEdit->setText(str);
    }


}


Widget::~Widget()
{
    delete ui;
}


//发送数据
void Widget::on_buttonSend_clicked()
{
    //先获取对端IP、port
    QString ip = ui->lineEditIP->text();
    quint16 port = ui->lineEditPort->text().toUInt();

    //获取编辑区内容
    QString str = ui->textEdit->toPlainText();

    //给指定的IP发送数据
    udpSocket->writeDatagram(str.toUtf8(), QHostAddress(ip), port);
}


















