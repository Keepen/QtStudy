/********************************************************************************
** Form generated from reading UI file 'client.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_H
#define UI_CLIENT_H

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

class Ui_Client
{
public:
    QGridLayout *gridLayout;
    QLabel *labelIP;
    QLineEdit *lineEditIP;
    QLabel *labelPort;
    QLineEdit *lineEditPort;
    QTextEdit *textEdit;
    QPushButton *buttonSend;
    QSpacerItem *horizontalSpacer;
    QPushButton *buttonClose;

    void setupUi(QWidget *Client)
    {
        if (Client->objectName().isEmpty())
            Client->setObjectName(QString::fromUtf8("Client"));
        Client->resize(527, 484);
        gridLayout = new QGridLayout(Client);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        labelIP = new QLabel(Client);
        labelIP->setObjectName(QString::fromUtf8("labelIP"));

        gridLayout->addWidget(labelIP, 0, 0, 1, 1);

        lineEditIP = new QLineEdit(Client);
        lineEditIP->setObjectName(QString::fromUtf8("lineEditIP"));

        gridLayout->addWidget(lineEditIP, 0, 1, 1, 1);

        labelPort = new QLabel(Client);
        labelPort->setObjectName(QString::fromUtf8("labelPort"));

        gridLayout->addWidget(labelPort, 1, 0, 1, 1);

        lineEditPort = new QLineEdit(Client);
        lineEditPort->setObjectName(QString::fromUtf8("lineEditPort"));

        gridLayout->addWidget(lineEditPort, 1, 1, 1, 1);

        textEdit = new QTextEdit(Client);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout->addWidget(textEdit, 2, 0, 1, 3);

        buttonSend = new QPushButton(Client);
        buttonSend->setObjectName(QString::fromUtf8("buttonSend"));

        gridLayout->addWidget(buttonSend, 3, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(308, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 1, 1, 1);

        buttonClose = new QPushButton(Client);
        buttonClose->setObjectName(QString::fromUtf8("buttonClose"));

        gridLayout->addWidget(buttonClose, 3, 2, 1, 1);


        retranslateUi(Client);

        QMetaObject::connectSlotsByName(Client);
    } // setupUi

    void retranslateUi(QWidget *Client)
    {
        Client->setWindowTitle(QCoreApplication::translate("Client", "Form", nullptr));
        labelIP->setText(QCoreApplication::translate("Client", "\345\257\271\347\253\257IP\357\274\232", nullptr));
        lineEditIP->setText(QCoreApplication::translate("Client", "127.0.0.1", nullptr));
        labelPort->setText(QCoreApplication::translate("Client", "\345\257\271\347\253\257port\357\274\232", nullptr));
        buttonSend->setText(QCoreApplication::translate("Client", "Send", nullptr));
        buttonClose->setText(QCoreApplication::translate("Client", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Client: public Ui_Client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
