#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QImage>
#include <QThread>
#include "mythread.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    //重写绘图事件
    void paintEvent(QPaintEvent *event);

    void getImage(QImage);        //自定义槽函数接收图像

    void dealClose();             //自定义槽函数 -- 释放线程

private:
    Ui::Widget *ui;
    QImage image;
    MyThread* myT;      //自定义线程对象
    QThread* thread;    //子线程
};
#endif // WIDGET_H









