#include "mybutton.h"
#include <QMouseEvent>
#include <QDebug>

MyButton::MyButton(QWidget *parent) : QPushButton(parent)
{

}

void MyButton::mousePressEvent(QMouseEvent *e){
    //左键按下 -- 处理
    if(e->button() == Qt::LeftButton){
        qDebug() << "左键被按下！！！";
        /*
         * 事件被接收后，不会再向下传递
         * 事件忽略，事件继续向下传递
         * e->ignore(); -- 此时，事件传递给了父组件，而不是父类
        */
        //e->ignore();
    }
    //不做处理
    else{
        QPushButton::mousePressEvent(e);    //事件的忽略
    }
}
