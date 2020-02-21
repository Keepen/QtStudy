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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientWidget
{
public:
    QLabel *label;
    QLineEdit *lineEditIP;
    QLineEdit *lineEditPort;
    QLabel *label_2;
    QPushButton *buttonConnect;

    void setupUi(QWidget *ClientWidget)
    {
        if (ClientWidget->objectName().isEmpty())
            ClientWidget->setObjectName(QString::fromUtf8("ClientWidget"));
        ClientWidget->resize(578, 392);
        label = new QLabel(ClientWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 20, 91, 31));
        lineEditIP = new QLineEdit(ClientWidget);
        lineEditIP->setObjectName(QString::fromUtf8("lineEditIP"));
        lineEditIP->setGeometry(QRect(170, 30, 211, 21));
        lineEditPort = new QLineEdit(ClientWidget);
        lineEditPort->setObjectName(QString::fromUtf8("lineEditPort"));
        lineEditPort->setGeometry(QRect(170, 90, 211, 21));
        label_2 = new QLabel(ClientWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 80, 91, 31));
        buttonConnect = new QPushButton(ClientWidget);
        buttonConnect->setObjectName(QString::fromUtf8("buttonConnect"));
        buttonConnect->setGeometry(QRect(430, 60, 93, 28));

        retranslateUi(ClientWidget);

        QMetaObject::connectSlotsByName(ClientWidget);
    } // setupUi

    void retranslateUi(QWidget *ClientWidget)
    {
        ClientWidget->setWindowTitle(QCoreApplication::translate("ClientWidget", "Form", nullptr));
        label->setText(QCoreApplication::translate("ClientWidget", "ServerIP:", nullptr));
        lineEditIP->setText(QCoreApplication::translate("ClientWidget", "127.0.0.1", nullptr));
        lineEditPort->setText(QCoreApplication::translate("ClientWidget", "8888", nullptr));
        label_2->setText(QCoreApplication::translate("ClientWidget", "ServerPort:", nullptr));
        buttonConnect->setText(QCoreApplication::translate("ClientWidget", "Connect", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClientWidget: public Ui_ClientWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTWIDGET_H
