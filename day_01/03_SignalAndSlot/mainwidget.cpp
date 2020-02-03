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

    /*自定义槽
     * Qt5：任意的成员函数，普通全局函数，静态函数
     * 槽函数需要和信号一致（返回值，参数）
     * 由于信号么有返回值，故槽函数一定没有返回值
    */

    connect(b2, &QPushButton::released, this, &MainWidget::mySlot); //当抬起b2按钮时，按钮设置为123
    connect(b2, &QPushButton::pressed, &b1, &QPushButton::close);   //当按下b2，b1消失


    //接下来设计两个窗口，两个窗口上均有按钮，按下一个隐藏自己显示另一个窗口
    setWindowTitle("boss");
    b3.setParent(this);
    b3.setText("Switch to bro");
    b3.move(150,200);

    //松开boss窗口的Switch to bro按钮时， 子窗口显示，主窗口消失
    connect(&b3, &QPushButton::released, this, &MainWidget::bro);

    //处理子窗口发送来的信号
    //松开bro窗口的Switch to boss按钮时， 主窗口显示，主窗口消失
    connect(&w, &SubWidget::mySignal, this, &MainWidget::boss);
    resize(400,400);
}

void MainWidget::boss(){
    this->show();
    w.close();
}

void MainWidget::bro(){
    this->close();
    w.show();
}

void MainWidget::mySlot(){
    b2->setText("123");
}

MainWidget::~MainWidget()
{
}

