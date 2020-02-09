#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QCompleter>
#include <QStringList>
#include <QMovie>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //获取内容
    QString str = ui->lineEdit->text();
    qDebug() << str;

    //设置内容
    ui->lineEdit->setText("987654");

    //设置内容间隙
    ui->lineEdit->setTextMargins(15,0,0,0);

    //设置内容显示方式
    //ui->lineEdit->setEchoMode(QLineEdit::Password);   //以密码模式显示
    QStringList list;
    list << "hello" << "How are you ";
    QCompleter* com  = new QCompleter(list, this);
    com->setCaseSensitivity(Qt::CaseInsensitive);
    ui->lineEdit->setCompleter(com);

    //QLabel
    ui->labelText->setText("123");

    ui->labelimage->setPixmap(QPixmap("://image/123.png"));
    //设置图片自动适应label大小
    ui->labelimage->setScaledContents(true);

    //设置动画
    QMovie* myMovie = new QMovie("://image/123.png");
    ui->labelGif->setMovie(myMovie);

    //启动动画
    myMovie->start();
    ui->labelGif->setScaledContents(true);

    //设置网址
    ui->labelUrl->setText("<h1><a href=\"https://www.baidu.com\">百度</a></h1>");
    ui->labelUrl->setScaledContents(true);
    //设置打开外部链接
    ui->labelUrl->setOpenExternalLinks(true);

    //数码管
    ui->lcdNumber->display(123);

    //进度条
    ui->progressBar->setMinimum(0);   //设置最小值
    ui->progressBar->setMaximum(100); //设置最大值
    ui->progressBar->setValue(20);   //设置当前值
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::on_change_clicked()
{
    //static int i = 0;
    //ui->stackedWidget->setCurrentIndex(++i % 3);

}
