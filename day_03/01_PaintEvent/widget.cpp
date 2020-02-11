#include "widget.h"
#include "ui_widget.h"
#include <QEvent>
#include <QPainter>
#include <QPaintDevice>
#include <QPen>
#include <QColor>
#include <QRgb>
#include <QBrush>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    x = 0;  //设定x坐标初始值为0
}

Widget::~Widget()
{
    delete ui;
}


void Widget::paintEvent(QPaintEvent *){
    //1.QPainter p(this);
    //2.绘图操作在begin 和 end 之间展开
    QPainter p;
    p.begin(this);  //指定当前窗口为绘图设备

    /*绘图操作
     * p.drawXXX();
    */

    //画背景图
    //p.drawPixmap(0,0,width(),height(),QPixmap("../image/desk.png"));
    //p.drawPixmap(rect(), QPixmap("../image/desk.png"));

    //定义画笔
    QPen pen;
    pen.setWidth(5);    //设置线宽
    //pen.setColor(Qt::red);
    pen.setColor(QColor(100, 190, 100));    //rgb设置颜色
    pen.setStyle(Qt::DashLine);         //设置线条风格

    //把画笔交给画家
    p.setPen(pen);
    //画直线
    p.drawLine(50, 50, 450, 50);
    p.drawLine(50, 50, 50, 450);

    //创建画刷对象
    QBrush brush;
    brush.setColor(QColor(20,20,20));
    brush.setStyle(Qt::Dense1Pattern);
    //画刷交给画家
    p.setBrush(brush);

    //画矩形
    p.drawRect(80, 80, 300, 300);

    //画圆
    p.drawEllipse(150, 150, 100, 100);

    //画笑脸
    p.drawPixmap(x, 250, 80, 80, QPixmap("../image/naruto.png"));

    p.end();

}





void Widget::on_pushButton_clicked()
{
    x += 20;
    if(x > width()){
        x = 0;
    }

    //刷新窗口，窗口重绘
    update();   //简介调用paintEvent

}
