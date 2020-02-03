#ifndef SUBWIDGET_H
#define SUBWIDGET_H

#include <QWidget>
#include <QPushButton>
class SubWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SubWidget(QWidget *parent = nullptr);

    void recvSignal();   //自定义槽函数 -- 接受子窗口的信号
private:
    QPushButton b;
signals:
    /*信号必须有signals关键字声明
     * 信号没有返回值，但可以有参数
     * 信号就是函数的声明，只需要声明，无需定义
     * 使用：emit mySignals();
    */

    void mySignal();    //自定义信号
};

#endif // SUBWIDGET_H
