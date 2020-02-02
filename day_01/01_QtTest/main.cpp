#include "mywidget.h"

#include <QApplication>
//QApplicaion -- 应用程序类
//Qt中的头文件（库文件）包含时不要加.h
//头文件和类名一样

int main(int argc, char *argv[])
{
    //有且只有一应用程序类对象
    QApplication a(argc, argv);
    //MyWidget继承于QWidget，QWidget是一个窗口基类
    //所以MyWidget也是一个窗口类
    //w就是一个窗口
    //窗口的显示需要主动地去调用显示函数
    MyWidget w;
    w.show();
    a.exec();   //让程序一直执行,等待用户操作--等待事件的发生
    return 0;
}
