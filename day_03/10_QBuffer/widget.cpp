#include "widget.h"
#include "ui_widget.h"
#include <QBuffer>  //内存文件
#include <QDebug>
#include <QDataStream>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QByteArray array;
    QBuffer memFile(&array);    //创建内存文件对象
    bool isok = memFile.open(QIODevice::WriteOnly);
    if(isok == true){
        memFile.write("hello qt!!!");
        memFile.write("me, too!!!");
        memFile.close();
        qDebug() << memFile.buffer();
        qDebug() << "array:" << array;
    }

    QBuffer memFile2;
    bool is_ok = memFile2.open(QIODevice::WriteOnly);
    if(is_ok == true){
        QDataStream stream(&memFile2);
        stream << QString("do you ?") << 99;
        memFile2.close();
        qDebug() << QString(memFile2.buffer()).toUtf8().data();
    }
    memFile2.open(QIODevice::ReadOnly);
    QDataStream stream1;
    stream1.setDevice(&memFile2);
    QString str;
    int a;
    stream1 >> str >> a;
    memFile2.close();
    qDebug() << str.toUtf8().data() << a;

}

Widget::~Widget()
{
    delete ui;
}

