#ifndef SERVERWIDGET_H
#define SERVERWIDGET_H

#include <QWidget>
#include <QTcpServer>   //用于服务端的监听
#include <QTcpSocket>   //用于服务端的通信


QT_BEGIN_NAMESPACE
namespace Ui { class ServerWidget; }
QT_END_NAMESPACE

class ServerWidget : public QWidget
{
    Q_OBJECT

public:
    ServerWidget(QWidget *parent = nullptr);
    ~ServerWidget();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_buttonSend_clicked();

    void on_buttonClose_clicked();

private:
    Ui::ServerWidget *ui;
    QTcpServer* tcpServer;
    QTcpSocket* tcpSocket;

};
#endif // SERVERWIDGET_H
