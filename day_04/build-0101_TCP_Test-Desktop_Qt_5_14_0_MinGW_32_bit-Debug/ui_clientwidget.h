/********************************************************************************
** Form generated from reading UI file 'clientwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTWIDGET_H
#define UI_CLIENTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientWidget
{
public:
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEditIP;
    QPushButton *buttonConnect;
    QLabel *label_2;
    QLineEdit *lineEditPort;
    QTextEdit *textEditRead;
    QTextEdit *textEditWrite;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *buttonSend;
    QSpacerItem *horizontalSpacer;
    QPushButton *buttonClose;

    void setupUi(QWidget *ClientWidget)
    {
        if (ClientWidget->objectName().isEmpty())
            ClientWidget->setObjectName(QString::fromUtf8("ClientWidget"));
        ClientWidget->resize(454, 416);
        formLayout = new QFormLayout(ClientWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(ClientWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::SpanningRole, label);

        lineEditIP = new QLineEdit(ClientWidget);
        lineEditIP->setObjectName(QString::fromUtf8("lineEditIP"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEditIP);

        buttonConnect = new QPushButton(ClientWidget);
        buttonConnect->setObjectName(QString::fromUtf8("buttonConnect"));

        formLayout->setWidget(2, QFormLayout::FieldRole, buttonConnect);

        label_2 = new QLabel(ClientWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_2);

        lineEditPort = new QLineEdit(ClientWidget);
        lineEditPort->setObjectName(QString::fromUtf8("lineEditPort"));

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEditPort);

        textEditRead = new QTextEdit(ClientWidget);
        textEditRead->setObjectName(QString::fromUtf8("textEditRead"));

        formLayout->setWidget(4, QFormLayout::SpanningRole, textEditRead);

        textEditWrite = new QTextEdit(ClientWidget);
        textEditWrite->setObjectName(QString::fromUtf8("textEditWrite"));

        formLayout->setWidget(6, QFormLayout::SpanningRole, textEditWrite);

        widget = new QWidget(ClientWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        buttonSend = new QPushButton(widget);
        buttonSend->setObjectName(QString::fromUtf8("buttonSend"));

        horizontalLayout->addWidget(buttonSend);

        horizontalSpacer = new QSpacerItem(217, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        buttonClose = new QPushButton(widget);
        buttonClose->setObjectName(QString::fromUtf8("buttonClose"));

        horizontalLayout->addWidget(buttonClose);


        formLayout->setWidget(8, QFormLayout::SpanningRole, widget);


        retranslateUi(ClientWidget);

        QMetaObject::connectSlotsByName(ClientWidget);
    } // setupUi

    void retranslateUi(QWidget *ClientWidget)
    {
        ClientWidget->setWindowTitle(QCoreApplication::translate("ClientWidget", "Form", nullptr));
        label->setText(QCoreApplication::translate("ClientWidget", "\346\234\215\345\212\241\347\253\257ip\357\274\232", nullptr));
        lineEditIP->setText(QCoreApplication::translate("ClientWidget", "127.0.0.1", nullptr));
        buttonConnect->setText(QCoreApplication::translate("ClientWidget", "Connect", nullptr));
        label_2->setText(QCoreApplication::translate("ClientWidget", "\346\234\215\345\212\241\347\253\257port\357\274\232", nullptr));
        lineEditPort->setText(QCoreApplication::translate("ClientWidget", "8888", nullptr));
        buttonSend->setText(QCoreApplication::translate("ClientWidget", "Send", nullptr));
        buttonClose->setText(QCoreApplication::translate("ClientWidget", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClientWidget: public Ui_ClientWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTWIDGET_H
