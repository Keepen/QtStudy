#ifndef CLIENT_H
#define CLIENT_H

#include <QWidget>
#include <QUdpSocket>

namespace Ui {
class Client;
}

class Client : public QWidget
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = nullptr);
    ~Client();

private slots:
    void on_buttonSend_clicked();

private:
    Ui::Client *ui;
    QUdpSocket* udpSocket;
};

#endif // CLIENT_H
