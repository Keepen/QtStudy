#include "widget.h"
#include "ui_widget.h"
#include <QFile>
#include <QFileDialog>
#include <QFileInfo>
#include <QDebug>
#include <QDateTime>
#include <QDataStream>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_buttonRead_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, "open", "../");
    if(path.isEmpty() == false){
        //文件对象
        QFile file(path);

        //打开文件
        bool isok = file.open(QIODevice::ReadOnly);
        if(isok == true){
#if 0
            //读文件
            //默认只识别utf-8编码
            QByteArray array = file.readAll();

            //显示到编辑区
            //ui->textEdit->setText(QString(array));
            ui->textEdit->setText(array);   //内部自动做字节到字符串的转换
#endif
            //按行读
            QByteArray array;
            while(file.atEnd() == false){
                //读一行
                array += file.readLine();
            }
            ui->textEdit->setText(array);
        }
        //关闭文件
        file.close();

        QFileInfo info(path);
        qDebug() << "文件名字   :" << info.fileName();
        qDebug() << "文件后缀   :" << info.suffix();
        qDebug() << "文件大小   :" << info.size() << "B";
        qDebug() << "文件创建时间:" <<
                info.birthTime().toString("yyyy-MM-dd hh:mm:ss");
    }
}



void Widget::on_buttonWrite_clicked()
{
    QString path = QFileDialog::getSaveFileName(this, "save", "../", "TXT(*.txt)");
    if(path.isEmpty() == false){
        QFile file; //创建文件对象
        //关联文件名字
        file.setFileName(path);

        //打开文件， 只写方式
        bool isok = file.open(QIODevice::WriteOnly);
        if(isok == true){
            //获取编辑区内容
            QString str = ui->textEdit->toPlainText();
            //写文件，显示也以utf8显示
            //方式1.
            //  QString -> QByteArray
            file.write(str.toUtf8());
            //方式2.
            //  QString -> C++string -> char*
            //file.write(str.toStdString().data());

            //转换为本地平台编码 -- 如：win -- ANSI
            file.write(str.toLocal8Bit());

        }
        file.close();
    }

}








