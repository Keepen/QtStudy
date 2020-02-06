#include "mainwindow.h"
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QDebug>
#include <QDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
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
}

MainWindow::~MainWindow()
{
}

