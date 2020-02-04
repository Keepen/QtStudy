#include "mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Boss");
    b1.setText("Close");
    b1.move(100,100);
    b1.setParent(this);

    b2.setText("Switch to Bro");
    b2.setParent(this);
    b2.move(200,100);

    //按下b1， 窗口关闭
    connect(&b1, &QPushButton::pressed, this, &MainWidget::close);

    //按下b2， 主窗口关闭，子窗口显示
    connect(&b2,&QPushButton::released, this, &MainWidget::Bro);

    //按下b，主窗口显示，子窗口关闭
    //void (SubWidget::*fun)() = &SubWidget::Switch;
    //connect(&w,fun, this, &MainWidget::Boss);

    void (SubWidget::*fun2)(int, QString) = &SubWidget::Switch;

    connect(&w, fun2, this, &MainWidget::BossDis);

    //Qt4进行连接时，
    connect(&w, SIGNAL(Switch()), this, SLOT(Boss()));
    //SIGNAL ,SLOT 不进行语法检查，只是将函数名变成字符串

    //Lambda表达式 -- 匿名函数对象
    //C++11 增加的 ， 项目文件：CONFIG += C++11
    //Qt配合信号一起使用

    QPushButton* b4 = new QPushButton(this);
    b4->setText("Lambda表达式");
    b4->move(300,400);
    int a = 10, b = 20;
    connect(b4, &QPushButton::pressed,
            // = :将外部所有局部变量、类中所有成员以值传递的方式传入
            //this：类中所有成员以值传递方式
            // &  :将外部所有局部变量以引用方式传入
            //mutable : 表示可以修改
            [=]() mutable{
                //b4->setText("lambda");
                qDebug() << "lambda";
                qDebug() << a << b;
                //w.show();
            }

            );

    resize(500,500);
}


void MainWidget::BossDis(int a, QString s){
    //toUtf8() -- > 字节数组QByteArray
    //...data() --> char*
    qDebug() << a << s.toUtf8().data();
}

void MainWidget::Boss(){
    w.hide();
    this->show();
}



void MainWidget::Bro(){
    w.show();
    this->hide();
}



MainWidget::~MainWidget()
{
}

