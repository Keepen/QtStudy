#ifndef CLIENTWIDGET_H
#define CLIENTWIDGET_H

#include <QWidget>
#include <QTcpSocket>   //客户端只需要通信套接字即可

namespace Ui {
class ClientWidget;
}

class ClientWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ClientWidget(QWidget *parent = nullptr);
    ~ClientWidget();

private slots:
    void on_buttonClose_clicked();

    void on_buttonSend_clicked();

    void on_buttonConnect_clicked();

private:
    Ui::ClientWidget *ui;
    QTcpSocket* tcpSocket;
};

#endif // CLIENTWIDGET_H
