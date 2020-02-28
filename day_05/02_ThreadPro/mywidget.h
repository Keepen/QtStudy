#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include "mythread.h"
#include <QThread>

QT_BEGIN_NAMESPACE
namespace Ui { class MyWidget; }
QT_END_NAMESPACE

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = nullptr);
    ~MyWidget();

private slots:
    void on_buttonStart_clicked();

    void dealSignal();      //自定义信号处理函数

    void on_buttonStop_clicked();

    void dealDestroyed();
signals:

    void startThread();   //自定义信号 -- 启动子线程

private:
    Ui::MyWidget *ui;
    MyThread* myT;
    QThread* thread;

};
#endif // MYWIDGET_H
