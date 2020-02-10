#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //针对整个窗口内的所有标签都采用此种设计方式

      this->setStyleSheet("QLabel{color:rgb(0,255,255);"
                        "background-color:rgb(200,100,204)"
                        "}");

    //针对单个标签做出设计
    //每一句后的分号注意加上 -- 否则效果可能无法出现
    ui->label->setStyleSheet("QLabel{color:rgb(0,255,255);"
                             "background-color:rgb(0,244,111);"
                             //"background-image:url(:/new/prefix1/image/desk.png)"
                             "border-image:url(:/new/prefix1/image/desk.png) 20 20 20 20 strech strech"
                             "}");

    ui->pushButton->setStyleSheet("QPushButton{"
                                  "border:2px outset blue;"
                                  "}"
                                  "QPushButton:hover{"
                                  "border-image:url(:/new/prefix1/image/desk.png);"
                                  "}"
                                  "QPushButton:pressed{"
                                  "color:rgb(0,0,200);"
                                  "}"
                                  );

}

Widget::~Widget()
{
    delete ui;
}

