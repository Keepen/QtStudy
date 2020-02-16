/********************************************************************************
** Form generated from reading UI file 'serverwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVERWIDGET_H
#define UI_SERVERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ServerWidget
{
public:
    QGridLayout *gridLayout;
    QTextEdit *textRead;
    QTextEdit *textWrite;
    QPushButton *buttonSend;
    QSpacerItem *horizontalSpacer;
    QPushButton *buttonClose;

    void setupUi(QWidget *ServerWidget)
    {
        if (ServerWidget->objectName().isEmpty())
            ServerWidget->setObjectName(QString::fromUtf8("ServerWidget"));
        ServerWidget->resize(817, 594);
        gridLayout = new QGridLayout(ServerWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        textRead = new QTextEdit(ServerWidget);
        textRead->setObjectName(QString::fromUtf8("textRead"));
        textRead->setReadOnly(true);

        gridLayout->addWidget(textRead, 0, 1, 1, 1);

        textWrite = new QTextEdit(ServerWidget);
        textWrite->setObjectName(QString::fromUtf8("textWrite"));

        gridLayout->addWidget(textWrite, 1, 1, 1, 1);

        buttonSend = new QPushButton(ServerWidget);
        buttonSend->setObjectName(QString::fromUtf8("buttonSend"));

        gridLayout->addWidget(buttonSend, 2, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(598, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 1, 1, 1);

        buttonClose = new QPushButton(ServerWidget);
        buttonClose->setObjectName(QString::fromUtf8("buttonClose"));

        gridLayout->addWidget(buttonClose, 2, 2, 1, 1);


        retranslateUi(ServerWidget);

        QMetaObject::connectSlotsByName(ServerWidget);
    } // setupUi

    void retranslateUi(QWidget *ServerWidget)
    {
        ServerWidget->setWindowTitle(QCoreApplication::translate("ServerWidget", "ServerWidget", nullptr));
        buttonSend->setText(QCoreApplication::translate("ServerWidget", "send", nullptr));
        buttonClose->setText(QCoreApplication::translate("ServerWidget", "close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ServerWidget: public Ui_ServerWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERWIDGET_H
