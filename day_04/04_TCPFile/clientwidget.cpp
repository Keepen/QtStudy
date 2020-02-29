#include "clientwidget.h"
#include "ui_clientwidget.h"
#include <QDebug>
#include <QMessageBox>
#include <QHostAddress>
#define cout qDebug()

ClientWidget::ClientWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientWidget)
{
    ui->setupUi(this);

    tcpSocket = new QTcpSocket(this);
    isStart = false;
    ui->progressBar->setValue(0);   //为进度条设置初始值0
    recvSize = 0;
    connect(tcpSocket, &QTcpSocket::readyRead,
            [=](){

        //取出接收的内容 -- 头信息、文件内容
        QByteArray buf = tcpSocket->readAll();
        if(isStart == false){
            cout << "客户端进入接收头部！！！";
            //接收头
            isStart = true;
            //解析头部信息   QString buf == "hello##1024"
            //QString str = "hello##1024";
            //str.section("##", 0, 0);
            //初始化
            fileName = QString(buf).section("##", 0, 0);
            fileSize = QString(buf).section("##", 1, 1).toInt();
            recvSize = 0;
            //打开文件
            file.setFileName(fileName);
            bool isOk = file.open(QIODevice::WriteOnly);
            if(isOk == false){
                cout << "打开文件失败！！！";
            }
            //弹出对话框， 显示接收文件的信息
            QString str = QString("接收的文件：[%1 : %2KB]").arg(fileName).arg(fileSize / 1024);
            QMessageBox::information(this, "文件信息", str);

            //设置进度条
            ui->progressBar->setMinimum(0);                 //设置最小值
            ui->progressBar->setMaximum(fileSize / 1024);   //设置最大值
            ui->progressBar->setValue(0);                   //当前值
        }        
        else{   //文件信息

            qint64 len = file.write(buf);
            recvSize += len;
            cout << "接收数据: " <<recvSize;
            ui->progressBar->setValue(recvSize / 1024);
            if(recvSize == fileSize){
                file.close();
                cout << "文件被关闭 文件发送完毕 客户端";

                QMessageBox::information(this, "完成", "文件接收OK!!!");
                //断开与服务端的连接
                tcpSocket->disconnectFromHost();
                tcpSocket->close();
                isStart = false;
                recvSize = 0;
            }
        }
    }
    );
}

ClientWidget::~ClientWidget()
{
    delete ui;
}

void ClientWidget::on_buttonConnect_clicked()
{
    //获取服务器的ip、port
    QString ip = ui->lineEditIP->text();
    quint16 port = ui->lineEditPort->text().toInt();

    tcpSocket->connectToHost(QHostAddress(ip), port);
}










