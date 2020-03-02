#include "widget.h"
#include "ui_widget.h"
#include <QSqlDatabase>
#include <QDebug>
#define cout qDebug()

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //打印Qt支持的数据库驱动
    cout << QSqlDatabase::drivers();

    //添加mysql数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("MYSQL");

    //连接数据库


}

Widget::~Widget()
{
    delete ui;
}

