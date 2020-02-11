#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QBitmap>


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

void Widget::paintEvent(QPaintEvent *event){
    QPainter p(this);

    p.drawPixmap(0, 0, QPixmap("../image/naruto.png"));

    //QBitmap
    p.drawPixmap(400,0,QBitmap("../image/naruto.png"));

    QPixmap pixmap;
    pixmap.load("../image/naruto.png");
    p.drawPixmap(300,400,pixmap);

}
