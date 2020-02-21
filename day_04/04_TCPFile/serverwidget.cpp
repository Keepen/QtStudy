#include "serverwidget.h"
#include "ui_serverwidget.h"
#include <QFileDialog>
#include <QDebug>
#include <QFileInfo>
#define cout qDebug()


ServerWidget::ServerWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ServerWidget)
{
    ui->setupUi(this);
    move(200,300);

//    tcpServer = nullptr;
//    tcpSocket = nullptr;

    //监听套接字
    tcpServer = new QTcpServer(this);
    tcpServer->listen(QHostAddress::Any, 8888);
    setWindowTitle("Server: 8888");

    //开始两个按钮都不能按， 将两个按钮都设置为无效
    ui->buttonFile->setEnabled(false);
    ui->buttonSend->setEnabled(false);

    //如果客户端成功和服务器连接，套接字会自动触发newConnection信号
    connect(tcpServer, &QTcpServer::newConnection,
    [=](){
        //取出建立好链接的套接字
        tcpSocket = tcpServer->nextPendingConnection();
        //获取对方IP、端口
        QString ip = tcpSocket->peerAddress().toString();
        quint16 port = tcpSocket->peerPort();

        QString str = QString("[%1 : %2] : Connect OK").arg(ip).arg(port);
        //显示到编辑区
        ui->textEdit->setText(str);

        //成功连接后，才能让按钮有效
        ui->buttonFile->setEnabled(true);

    });

    connect(&timer, &QTimer::timeout,
            [=](){
        //关闭定时器
        timer.stop();

        //bool isOk = file.open(QIODevice::ReadOnly);
        //发送文件
        sendData();
    }
    );

}

ServerWidget::~ServerWidget()
{
    delete ui;
}

//选择文件的按钮
void ServerWidget::on_buttonFile_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, "open", "../");
    //如果选择的文件路径有效，才进入
    if(filePath.isEmpty() == false){
        fileName.clear();
        fileSize = 0;
        //获取文件信息
        QFileInfo info(filePath);
        fileName = info.fileName();     //获取文件名
        cout << "文件名：" << fileName;
        fileSize = info.size();         //获取文件大小
        cout << "文件大小：" << fileSize;
        sendSize = 0;
        //以只读方式打开
        //指定文件名
        file.setFileName(filePath);
        cout << "文件发送路径（服务器）：" << filePath;
        //打开文件
        bool isOk = file.open(QIODevice::ReadOnly);
        if(isOk == false){
            cout << "只读方式打开文件失败！！！72";
        }
        //提示打开文件的路径
        ui->textEdit->append(filePath);

        ui->buttonFile->setEnabled(false);
        ui->buttonSend->setEnabled(true);
    }
    else{
        cout << "文件路径有误！！！91";
    }
}

//发送文件按钮
void ServerWidget::on_buttonSend_clicked()
{
    //先发送文件头信息  文件名 ## 文件大小
    QString head = QString("%1##%2").arg(fileName).arg(fileSize);
    cout << head;
    //发送头部信息
    qint64 len = tcpSocket->write(head.toUtf8());
    cout << len;
    if(len > 0){        //头部信息发送成功
        //再发送真正的文件信息
        //防止TCP粘包问题，需要通过定时器延时20ms
        timer.start(20);    //发完头部20ms后，再发送正文
    }
    else{
        cout << "头部信息发送失败！！！ 108";
        file.close();
        cout << "文件被关闭 头部信息发送失败";
        ui->buttonFile->setEnabled(true);
        ui->buttonSend->setEnabled(false);
    }

}

void ServerWidget::sendData(){
    qint64 len = 0;
    do{
        char buf[8192] = {0};   //每次发送数据的大小 -- 4KB
        len = 0;
        //向文件中读数据
        len = file.read(buf, sizeof(buf));
        //发送数据，读多少，发多少
        len = tcpSocket->write(buf, len);
        //发送数据需要累加
        sendSize += len;
        //cout << "单次发送长度: " << len;
        //cout << "已发送长度:   " << sendSize;

    }
    while(len > 0);     //每次发送的数据长度 >0时， 表示再接着发

    //是否发送文件完毕
    if(sendSize == fileSize){
        ui->textEdit->append("文件发送完毕！！！");
        file.close();
        cout << "文件被关闭 发送完毕";
        //断开客户端连接
        tcpSocket->disconnectFromHost();
        tcpSocket->close();
        ui->buttonFile->setEnabled(true);
        ui->buttonSend->setEnabled(false);
    }
#if 1
    else{
        cout << "文件发送有误！！！";
        ui->buttonFile->setEnabled(true);
        ui->buttonSend->setEnabled(false);
    }
#endif
}













