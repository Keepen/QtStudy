#include "mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QDebug>
#include <QToolBar>
#include <QPushButton>
#include <QStatusBar>
#include <QLabel>
#include <QTextEdit>
#include <QDockWidget>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
//1.菜单栏
    QMenuBar* mBar = menuBar();

    //添加菜单
    QMenu* pFile = mBar->addMenu("文件");

    //添加菜单项 -- 添加动作
    QAction* pNew = pFile->addAction("新建");

    pFile->addSeparator();      //添加分割线

    connect(pNew, &QAction::triggered,
            [=](){
                qDebug() << "新建被按下！！！";
            }
            );
    QAction* pOpen = pFile->addAction("打开");
    connect(pOpen, &QAction::triggered,
            [=](){
                qDebug() << "打开被按下";
            }
            );

//2.工具栏 -- 菜单项上的快捷方式
    QToolBar* toolBar = addToolBar("toolBar");

    //工具栏添加快捷键
    toolBar->addAction(pNew);
    QPushButton* b = new QPushButton(this);
    b->setText("@");

    //添加小控件
    toolBar->addWidget(b);
    connect(b, &QPushButton::pressed,
            [=](){
                qDebug() << "按钮b被按下";
            }
            );

//3.状态栏
    QStatusBar* sBar = statusBar();
    QLabel* label = new QLabel(this);
    label->setText("Normal text file");
    sBar->addWidget(label);
    //addWidget从左向右依次添加
    sBar->addWidget(new QLabel("2",this));

    //addPermanentWidget从右向左进行添加
    sBar->addPermanentWidget(new QLabel("3",this));

//4.核心控件
    QTextEdit* textEdit = new QTextEdit(this);  //文本编辑
    setCentralWidget(textEdit);
//5.浮动窗口
    QDockWidget* dock = new QDockWidget(this);
    addDockWidget(Qt::RightDockWidgetArea, dock);

    QTextEdit* textEdit1 = new QTextEdit(this);
    dock->setWidget(textEdit1);
}

MainWindow::~MainWindow()
{
}

