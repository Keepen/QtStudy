#ifndef MAINWIDGET_H
#define MAINWIDGET_H
#include <QWidget>
#include <QPushButton>
#include "subwidget.h"  //子窗口的头文件

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

    void mySlot();  //自定义槽函数
    void bro();     //自定义槽函数 -- 显示子窗口
    void boss();    //自定义槽函数 -- 接收子窗口发送来的信号，显示主窗口，隐藏子窗口

private:
    QPushButton b1;
    QPushButton* b2;
    QPushButton b3;
    SubWidget w;
};
#endif // MAINWIDGET_H
