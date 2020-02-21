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
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ServerWidget
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *buttonFile;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *buttonSend;
    QSpacerItem *horizontalSpacer_5;
    QTextEdit *textEdit;

    void setupUi(QWidget *ServerWidget)
    {
        if (ServerWidget->objectName().isEmpty())
            ServerWidget->setObjectName(QString::fromUtf8("ServerWidget"));
        ServerWidget->resize(437, 413);
        gridLayout = new QGridLayout(ServerWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer = new QSpacerItem(312, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 3);

        label = new QLabel(ServerWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(28);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 3, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(311, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 4, 1, 3);

        horizontalSpacer_4 = new QSpacerItem(207, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 2, 0, 1, 1);

        buttonFile = new QPushButton(ServerWidget);
        buttonFile->setObjectName(QString::fromUtf8("buttonFile"));

        gridLayout->addWidget(buttonFile, 2, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(144, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 2, 2, 1, 2);

        buttonSend = new QPushButton(ServerWidget);
        buttonSend->setObjectName(QString::fromUtf8("buttonSend"));

        gridLayout->addWidget(buttonSend, 2, 5, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(206, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 2, 6, 1, 1);

        textEdit = new QTextEdit(ServerWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout->addWidget(textEdit, 1, 0, 1, 7);


        retranslateUi(ServerWidget);

        QMetaObject::connectSlotsByName(ServerWidget);
    } // setupUi

    void retranslateUi(QWidget *ServerWidget)
    {
        ServerWidget->setWindowTitle(QCoreApplication::translate("ServerWidget", "ServerWidget", nullptr));
        label->setText(QCoreApplication::translate("ServerWidget", "Server", nullptr));
        buttonFile->setText(QCoreApplication::translate("ServerWidget", "Choose", nullptr));
        buttonSend->setText(QCoreApplication::translate("ServerWidget", "Send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ServerWidget: public Ui_ServerWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERWIDGET_H
