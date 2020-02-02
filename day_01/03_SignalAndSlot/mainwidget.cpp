#include "mainwidget.h"
#include <QPushButton>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    b1.setParent(this);
    b1.setText("Yes");
    b1.move(100, 100);

    b2 = new QPushButton(this);
    b2->setText("OK");
    b2->move(400,100);

    connect(&b1, &QPushButton::pressed,this, &MainWidget::close);
    /* &b1:信号发出者，指针类型
     * &QpushButton::pressed：处理的信号， （&发送者的类名::信号名）
     * this：信号接收者
     * &MainWidget::close：接收者的槽函数
    */
}

MainWidget::~MainWidget()
{
}

