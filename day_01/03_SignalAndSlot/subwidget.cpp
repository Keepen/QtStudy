#include "subwidget.h"

SubWidget::SubWidget(QWidget *parent) : QWidget(parent)
{
    b.setParent(this);
    this->setWindowTitle("bro");
    b.setText("Switch to boss");
    b.move(100,100);

    connect(&b, &QPushButton::released, this, &SubWidget::recvSignal);
    resize(400,400);
}

void SubWidget::recvSignal(){
    emit mySignal();
}

