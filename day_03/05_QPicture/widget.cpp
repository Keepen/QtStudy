#include "widget.h"
#include "ui_widget.h"
#include <QPicture>
#include <QPainter>
#include <QImage>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPicture picture;
    QPainter p;
    p.begin(&picture);

    //绘图
    p.drawPixmap(0, 0, 80, 80, QPixmap("../image/kakaxi.png"));
    p.drawLine(50, 50, 150, 50);

    p.end();
    //Picture保存的是二进制文件
    picture.save("../picture.png");
}

Widget::~Widget()
{
    delete ui;
}


void Widget::paintEvent(QPaintEvent *event){
    /*
     * QPicture pic;
    pic.load("../picture.png"); //加载文件

    QPainter p(this);
    p.drawPicture(0, 0, pic);
    */
    QPainter p(this);
    QPixmap pixmap;
    pixmap.load("../image/kakaxi.png");

    //QPixmap --> QImage
    QImage tmp = pixmap.toImage();
    p.drawImage(0, 0, tmp);

    QImage image;
    image.load("../image/kakaxi.png");

    //QImage --> QPixmap
    QPixmap tmpPixmap = QPixmap::fromImage(image);
    p.drawPixmap(400, 0, tmpPixmap);

}
