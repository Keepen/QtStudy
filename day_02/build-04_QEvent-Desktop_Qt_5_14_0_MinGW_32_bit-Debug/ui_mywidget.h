/********************************************************************************
** Form generated from reading UI file 'mywidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYWIDGET_H
#define UI_MYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <mybutton.h>
#include <mylabel.h>

QT_BEGIN_NAMESPACE

class Ui_MyWidget
{
public:
    MyLabel *label;
    MyLabel *label_2;
    MyButton *pushButton;

    void setupUi(QWidget *MyWidget)
    {
        if (MyWidget->objectName().isEmpty())
            MyWidget->setObjectName(QString::fromUtf8("MyWidget"));
        MyWidget->resize(800, 600);
        label = new MyLabel(MyWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(9, 286, 201, 101));
        label_2 = new MyLabel(MyWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(9, 9, 151, 71));
        pushButton = new MyButton(MyWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(9, 563, 93, 28));

        retranslateUi(MyWidget);

        QMetaObject::connectSlotsByName(MyWidget);
    } // setupUi

    void retranslateUi(QWidget *MyWidget)
    {
        MyWidget->setWindowTitle(QCoreApplication::translate("MyWidget", "MyWidget", nullptr));
        label->setText(QCoreApplication::translate("MyWidget", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("MyWidget", "TextLabel", nullptr));
        pushButton->setText(QCoreApplication::translate("MyWidget", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyWidget: public Ui_MyWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWIDGET_H
