/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QLineEdit *lineEditPort;
    QLabel *labelIP;
    QLineEdit *lineEditIP;
    QPushButton *buttonClose;
    QSpacerItem *horizontalSpacer;
    QLabel *labelPort;
    QPushButton *buttonSend;
    QSpacerItem *horizontalSpacer_3;
    QTextEdit *textEdit;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        gridLayout = new QGridLayout(Widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEditPort = new QLineEdit(Widget);
        lineEditPort->setObjectName(QString::fromUtf8("lineEditPort"));

        gridLayout->addWidget(lineEditPort, 1, 2, 1, 1);

        labelIP = new QLabel(Widget);
        labelIP->setObjectName(QString::fromUtf8("labelIP"));

        gridLayout->addWidget(labelIP, 0, 0, 1, 1);

        lineEditIP = new QLineEdit(Widget);
        lineEditIP->setObjectName(QString::fromUtf8("lineEditIP"));

        gridLayout->addWidget(lineEditIP, 0, 2, 1, 1);

        buttonClose = new QPushButton(Widget);
        buttonClose->setObjectName(QString::fromUtf8("buttonClose"));

        gridLayout->addWidget(buttonClose, 3, 6, 1, 1);

        horizontalSpacer = new QSpacerItem(581, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 2, 1, 4);

        labelPort = new QLabel(Widget);
        labelPort->setObjectName(QString::fromUtf8("labelPort"));

        gridLayout->addWidget(labelPort, 1, 0, 1, 2);

        buttonSend = new QPushButton(Widget);
        buttonSend->setObjectName(QString::fromUtf8("buttonSend"));

        gridLayout->addWidget(buttonSend, 3, 0, 1, 2);

        horizontalSpacer_3 = new QSpacerItem(96, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 2, 5, 1, 2);

        textEdit = new QTextEdit(Widget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout->addWidget(textEdit, 2, 2, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        labelIP->setText(QCoreApplication::translate("Widget", "\345\257\271\347\253\257IP\357\274\232", nullptr));
        lineEditIP->setText(QCoreApplication::translate("Widget", "127.0.0.1", nullptr));
        buttonClose->setText(QCoreApplication::translate("Widget", "Close", nullptr));
        labelPort->setText(QCoreApplication::translate("Widget", "\345\257\271\347\253\257port\357\274\232", nullptr));
        buttonSend->setText(QCoreApplication::translate("Widget", "Send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
