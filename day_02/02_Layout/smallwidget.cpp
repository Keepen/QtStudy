#include "smallwidget.h"
#include <QSpinBox>
#include <QSlider>
#include <QHBoxLayout>
#include <QPushButton>

SmallWidget::SmallWidget(QWidget *parent) : QWidget(parent)
{
    QSpinBox* spin = new QSpinBox(this);
    QSlider* slider = new QSlider(Qt::Horizontal,this);
    //QSlider* slider2 = new QSlider(Qt::Horizontal,this);
    //QPushButton* b = new QPushButton(this);
    //把控件添加到布局中
    QHBoxLayout* hLayout = new QHBoxLayout;
    hLayout->addWidget(spin);
    hLayout->addWidget(slider);
    slider->move(60,0);
    connect(spin, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            slider,
            &QSlider::setValue);

    connect(slider, &QSlider::valueChanged, spin, &QSpinBox::setValue);

}
