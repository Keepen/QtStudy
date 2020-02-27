#ifndef MYWIDGET_H
#define MYWIDGET_H
#include "mythread.h"       //线程头文件
#include <QWidget>
#include <QTimer>       //定时器头文件

QT_BEGIN_NAMESPACE
namespace Ui { class MyWidget; }
QT_END_NAMESPACE

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = nullptr);
    ~MyWidget();

    void dealTime();    //定时器槽函数

private slots:
    void on_pushButton_clicked();

    void dealThread();  //自定义线程结束槽函数

    void dealDestroy(); //自定义回收线程资源函数

private:
    Ui::MyWidget *ui;
    QTimer* myTimer;    //定时器变量
    MyThread* thread;    //线程对象
};
#endif // MYWIDGET_H
