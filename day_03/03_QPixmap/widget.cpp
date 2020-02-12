#include "widget.h"
#include "ui_widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //绘图设备 大小（400 * 300）
    QPixmap pixmap(400, 300);
    QPainter p(&pixmap);
    //填充背景
    //  方式1
    //p.fillRect(0, 0, 400, 300, QBrush(Qt::white));

    //  方式2
    pixmap.fill(Qt::white);

    p.drawPixmap(0, 0, 80, 80, QPixmap("../image/naruto.png"));
    //保存图片
    pixmap.save("../pixmap.jpg");
}

Widget::~Widget()
{
    delete ui;
}

