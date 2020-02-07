#include "mainwindow.h"
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QDebug>
#include <QDialog>
#include <QMessageBox>
#include <QFileDialog>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(400,400);
    QMenuBar* mBar = menuBar();
    setMenuBar(mBar);   //设置菜单栏
    QMenu* menu = mBar->addMenu("对话框");
    QAction* p1 = menu->addAction("模态对话框");
    connect(p1,&QAction::triggered,
            [=](){
                QDialog dlg;
                dlg.exec();
                qDebug() << "模态对话框被触发！！！"    ;
            }
            );
    QAction* p2 = menu->addAction("非模态对话框");

    connect(p2,&QAction::triggered,
            [=](){
                QDialog dlg;        //由于生命周期的关系 -- 导致其不显示
                dlg.show();
                QDialog* dlg2 = new QDialog(this);
                dlg2->show();       //但是指定父对象动态分配内存的方式 -- 每次点击都会动态分配，
                                    //而主函数结束时才会析构，导致内存泄漏
                //QDialog* dlg3 = new QDialog;
                //dlg2->setAttribute(Qt::WA_DeleteOnClose);   //关闭对话框时析构
                //dlg2->show();

                qDebug() << "非模态对话框被触发！！！"    ;
            }
            );

    //关于对话框
    QAction* p3 = menu->addAction("关于对话框");
    connect(p3,&QAction::triggered,
            [=](){
                QMessageBox::about(this, "关于对话框", "关于qt");

            }
            );

    //问题对话框
    QAction* p4 = menu->addAction("问题对话框");
    connect(p4,&QAction::triggered,
            [=](){
                int ret = QMessageBox::question(this, "问题对话框","are you ok?");
                if(ret == QMessageBox::Yes)
                    qDebug() << "i am good!!!";
                if(ret == QMessageBox::No)
                    qDebug() << "i am bad!!!";
            }
            );

    //文件对话框
    QAction* p5 = menu->addAction("文件对话框");
    connect(p5,&QAction::triggered,
            [=](){
                QString path = QFileDialog::getOpenFileName(
                            this,
                            "open",
                            "../",
                            "souce(*.cpp *.h);;"
                            "Text(*.txt);;"
                            "all(*.*)");
                qDebug() << path;
            }
            );
}

MainWindow::~MainWindow()
{
}

