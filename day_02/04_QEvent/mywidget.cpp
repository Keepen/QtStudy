#include "mywidget.h"
#include "ui_mywidget.h"
#include "mybutton.h"
#include <QDebug>
#include <QKeyEvent>
#include <QCloseEvent>
#include <QMessageBox>
#include <QEvent>
MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    timer_id = this->startTimer(1000);     //以毫秒为单位，每隔一秒触发一次定时器

    timer_id2 = this->startTimer(500);

    connect(ui->pushButton, &MyButton::clicked,
            [=](){
                qDebug() << "该按钮被按下！！！";
            }
            );
    //安装过滤器
    ui->label_2->installEventFilter(this);
    ui->label_2->setMouseTracking(true);    //设置鼠标激活 -- 不用点击
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::keyPressEvent(QKeyEvent *event){
    qDebug() << event->key();
    if(event->key() == Qt::Key_A){
        qDebug() << "Qt::Key_A";
    }
}

void MyWidget::timerEvent(QTimerEvent *e){
    if(e->timerId() == timer_id){
        static int sec = 0;
        ui->label->setText(QString("<center><h1>time out: %1</h1></center>").arg(sec++));

        //停止计时器
        if(sec == 10){
            killTimer(timer_id);
        }
    }
    else if(e->timerId() == timer_id2){
        static int sec = 0;
        ui->label_2->setText(QString("<center><h1>time out: %1</h1></center>").arg(sec++));

        //停止计时器
        if(sec == 10){
            killTimer(timer_id2);
        }
    }

}

void MyWidget::mousePressEvent(QMouseEvent* e){
    qDebug() << "ignore传递给了父组件+++++++";
}

void MyWidget::closeEvent(QCloseEvent *event){
    int ret = QMessageBox::question(this, "question", "是否关闭！！！");
    if(ret == QMessageBox::Yes){
        //关闭窗口，事件接收后，不在向下传递
        event->accept();
    }
    else{
        //不关闭窗口
        //忽略事件，事件想父组件传递
        qDebug() << "取消关闭窗口，事件继续传递！";
        event->ignore();
    }
}

bool MyWidget::event(QEvent* e){
    //事件分发
//    switch(e->type()){
//        case QEvent::Close:
//            closeEvent(e);
//        break;
//        case QEvent::MouseMove:
//            mouseMoveEvent(e);
//        break;
//    }
    if(e->type() == QEvent::Timer){
        //将定时器取消
        //返回true，事件停止传播
        //需要类型转换，
        //QTimerEvent* env = static_cast<QTimerEvent*>(e);
        //timerEvent(env);
        return true;
    }
    //按下B， 事件转发，按下其他，事件停止传播
    else if(e->type() == QEvent::KeyPress){
        QKeyEvent* env = static_cast<QKeyEvent*>(e);
        if(env->key() == Qt::Key_B){
            return QWidget::event(e);
        }
        return true;
    }
    else{
        //否则，传递给下一个
        return QWidget::event(e);
    }
}


bool MyWidget::eventFilter(QObject *obj, QEvent *e){
    if(obj == ui->label_2){
        QMouseEvent* env = static_cast<QMouseEvent*>(e);
        //判断事件
        if(e->type() == QEvent::MouseMove){
            ui->label_2->setText(QString("Mouse move:%1, %2").arg(env->x()).arg(env->y()));
            return true;
        }
        if(e->type() == QEvent::MouseButtonPress){
            ui->label_2->setText(QString("Mouse press:%1, %2").arg(env->x()).arg(env->y()));
            return true;
        }
        if(e->type() == QEvent::MouseButtonRelease){
            ui->label_2->setText(QString("Mouse release:%1, %2").arg(env->x()).arg(env->y()));
            return true;
        }
    }

    return QWidget::eventFilter(obj, e);

}

