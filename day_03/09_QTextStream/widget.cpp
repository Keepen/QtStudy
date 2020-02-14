#include "widget.h"
#include "ui_widget.h"
#include <QTextStream>
#include <QFile>
#include <QDebug>
#include <QString>
#include <QFileDialog>
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
    QFile file;
    file.setFileName("../demo.txt");
    bool isok = file.open(QIODevice::WriteOnly);
    if(isok == true){
        //关联文件
        //默认编码是当前平台下的编码 -- 如【win】-> 【GB2312】
        QTextStream stream(&file);
        //指定编码,【utf8】
        stream.setCodec("UTF-8");
        stream << QString("可遇不可求") << 99;

        file.close();
    }

}


void Widget::readData(){
    QFile file;
    file.setFileName("../demo.txt");
    bool isok = file.open(QIODevice::ReadOnly);
    if(isok == true){
        //关联文件
        QTextStream stream(&file);
        //指定编码
        stream.setCodec("UTF-8");
        QString str;
        int a;
        stream >> str >> a;
        cout << str << a;
        file.close();
    }
}




void Widget::on_pushButton_clicked()
{
    QString path = QFileDialog::getOpenFileName(
                this, "open", "../");
    if(path.isEmpty() == false){
        QFile file;
        file.setFileName(path);
        bool isok = file.open(QIODevice::ReadOnly);
        if(isok == true){
            QTextStream stream(&file);
            //指定编码
            stream.setCodec("UTF-8");
            //一次性读
            QString str = stream.readAll();
            ui->textEdit->setText(str);
            file.close();
        }
    }

}
