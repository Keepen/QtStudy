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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ServerWidget
{
public:
    QTextEdit *textEditRead;
    QTextEdit *textEditWrite;
    QPushButton *buttonSend;
    QPushButton *buttonClose;

    void setupUi(QWidget *ServerWidget)
    {
        if (ServerWidget->objectName().isEmpty())
            ServerWidget->setObjectName(QString::fromUtf8("ServerWidget"));
        ServerWidget->resize(800, 600);
        textEditRead = new QTextEdit(ServerWidget);
        textEditRead->setObjectName(QString::fromUtf8("textEditRead"));
        textEditRead->setGeometry(QRect(130, 60, 521, 151));
        textEditRead->setReadOnly(true);
        textEditWrite = new QTextEdit(ServerWidget);
        textEditWrite->setObjectName(QString::fromUtf8("textEditWrite"));
        textEditWrite->setGeometry(QRect(130, 240, 521, 151));
        buttonSend = new QPushButton(ServerWidget);
        buttonSend->setObjectName(QString::fromUtf8("buttonSend"));
        buttonSend->setGeometry(QRect(60, 540, 93, 28));
        buttonClose = new QPushButton(ServerWidget);
        buttonClose->setObjectName(QString::fromUtf8("buttonClose"));
        buttonClose->setGeometry(QRect(650, 540, 93, 28));

        retranslateUi(ServerWidget);

        QMetaObject::connectSlotsByName(ServerWidget);
    } // setupUi

    void retranslateUi(QWidget *ServerWidget)
    {
        ServerWidget->setWindowTitle(QCoreApplication::translate("ServerWidget", "ServerWidget", nullptr));
        buttonSend->setText(QCoreApplication::translate("ServerWidget", "Send", nullptr));
        buttonClose->setText(QCoreApplication::translate("ServerWidget", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ServerWidget: public Ui_ServerWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERWIDGET_H
