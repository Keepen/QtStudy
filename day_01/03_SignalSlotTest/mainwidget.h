#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QDebug>
#include "subwidget.h"
class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();
public slots:
    void Bro();     //自定义槽函数 -- 显示子窗口，隐藏主窗口
    void Boss();    //自定义槽函数 -- 接受子窗口发送的信号，显示主窗口，隐藏子窗口
    void BossDis(int a, QString s); //接受子窗口发送的第二种信号
private:
    QPushButton b1;
    QPushButton b2;
    SubWidget w;
};
#endif // MAINWIDGET_H
