#include "widget.h"
#include "ui_widget.h"
#include <QDataStream>
#include <QTextStream>
#include <QFile>
#include <QDebug>

#define cout qDebug() << "[" << __FILE__ << ":" << __LINE__ << "]"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    writeData();
    readData();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::writeData(){
    //创建文件对象
    QFile file("../test.txt");

    //打开文件，只写方式
    bool isok = file.open(QIODevice::WriteOnly);
    if(isok == true){
        //创建数据流，和file文件关联
        //向数据流中写数据，相当于向文件内写数据
        QDataStream stream(&file);
        stream << QString("input str") << 250;
        file.close();
    }
}


void Widget::readData(){
    QFile file("../test.txt");

    //打开文件，只读方式
    bool isok = file.open(QIODevice::ReadOnly);
    if(isok == true){
        //关联文件
        //向数据流中读数据，相当于向文件中读数据
        QDataStream stream(&file);

        //读的时候，按写的顺序取数据
        QString str;
        int a;
        stream >> str >> a;
        //qDebug() << str << a;

        cout << str << a;
        file.close();
    }
}
















