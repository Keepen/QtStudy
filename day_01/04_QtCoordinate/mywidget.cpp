#include "mywidget.h"
#include <QPushButton>
MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    /*坐标系统：主窗口相对于父窗口
     * 原点：父窗口的左上角
     * +x：右
     * +y：下
    */
    move(300,300);
    resize(400,400);
    QPushButton* b = new QPushButton(this);
    b->setText("bro");
    MyButton* mb = new MyButton(this);
    mb->setText("MyButton");
    mb->move(200,200);
}

MyWidget::~MyWidget()
{
}

