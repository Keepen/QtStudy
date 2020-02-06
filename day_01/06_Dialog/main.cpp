#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}


//对话框：
//模态    -- 只能操作当前对话框
//非模态   --可以操作当前，也可以操作背景对话框

//模态
//  只需要调用exec函数

//非模态
//  由于生命周期的关系，导致对话框不显示 -- 3种解决方式
//      1.在类中为其设置成员
//      2.动态分配内存 -- 指定父对象时，导致其只在主窗口关闭时才析构，点击多次，导致内存泄漏
//      3.动态分配内存 -- 不指定父对象，设置其关闭时析构的属性
//              WA_DeleteOnClose

