#include "mywidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyWidget w;
    w.show();
    return a.exec();
}


/*  1.坐标系统：本窗口的坐标系统是父窗口
 *  2.内存回收机制：由于按钮等是动态分配的，故需要回收--系统自动回收
 *      1）系统内建立了对象树 -- 继承关系的树
 *      2）析构时从子到父依次析构
 *      3）注意：必须是直接或间接继承于QObject
*/
