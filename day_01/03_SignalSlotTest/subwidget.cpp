#include "subwidget.h"


SubWidget::SubWidget(QWidget *parent) : QWidget(parent)
{
    b.setParent(this);
    b.setText("Switch to Boss");
    b.move(100,150);
    this->setWindowTitle("Bro");
    this->resize(400,400);
    connect(&b, &QPushButton::released, this, &SubWidget::dealSwitch);
    connect(&b, &QPushButton::released, this, &SubWidget::dealSwitch2);
}

void SubWidget::dealSwitch(){
    emit Switch();
}

void SubWidget::dealSwitch2(){
    emit Switch(120,"我是子窗口");
}

