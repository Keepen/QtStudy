#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MyWidget; }
QT_END_NAMESPACE

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = nullptr);
    ~MyWidget();

protected:
    //键盘按下事件
    void keyPressEvent(QKeyEvent *event);

    //计时器事件
    void timerEvent(QTimerEvent* e);

    //鼠标点击事件
    void mousePressEvent(QMouseEvent* e);

    //关闭事件
    void closeEvent(QCloseEvent *event);

    //重写事件
    bool event(QEvent*);

    //重写事件过滤器
    bool eventFilter(QObject* obj, QEvent* e);

private:
    Ui::MyWidget *ui;
    int timer_id;
    int timer_id2;
};
#endif // MYWIDGET_H
