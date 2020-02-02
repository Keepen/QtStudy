#include <QApplication>
#include <QWidget>      //窗口控件基类
#include <QPushButton>  //按钮

int main(int argc, char** argv){
    QApplication app(argc, argv);
    QWidget w;
    w.setWindowTitle("WZ"); //设置标题




    /*指定父对象
     * 如果不指定父对象，对象和对象（窗口）之间相互独立，
     *  假定：a指定b为它的父对象 -- a在b的上面
     * 两种方式指定父对象：
     *  1.setParent
     *  2.通过构造函数传参
     * 指定父对象后，父对象显示，子对象默认全部显示 -- 显示窗口后，上面的按钮也全显示
    */

    //方式1：setParent
    QPushButton b;
    b.setText("OK");    //设置按钮的名字
    b.setParent(&w);    //设定父对象
    b.move(100,100);    //设定位置坐标

    //方式2：构造函数
    QPushButton b1(&w);
    b1.setText("Yes");
    b1.move(200,100);

    w.show();
    app.exec();
    return 0;
}
