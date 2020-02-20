#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QUdpSocket>


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();


    void dealMessage(); //槽函数，处理对方发送的数据

private slots:
    void on_buttonSend_clicked();

private:
    Ui::Widget *ui;
    QUdpSocket* udpSocket;
};
#endif // WIDGET_H
