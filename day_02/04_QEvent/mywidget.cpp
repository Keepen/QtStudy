#include "mywidget.h"
#include "ui_mywidget.h"
#include "mybutton.h"
#include <QDebug>
#include <QKeyEvent>
#include <QCloseEvent>
#include <QMessageBox>

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
        event->ignore();
    }
}
