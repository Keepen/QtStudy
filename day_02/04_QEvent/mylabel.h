#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = nullptr);

protected:
    //鼠标点击事件
    void mousePressEvent(QMouseEvent *ev) override;
    //鼠标松开事件
    void mouseReleaseEvent(QMouseEvent *ev) override;
    //鼠标移动事件
    void mouseMoveEvent(QMouseEvent *ev) override;
    //进入窗口区域
    void enterEvent(QEvent* ev);
    //离开窗口区域
    void leaveEvent(QEvent* ev);



signals:

};

#endif // MYLABEL_H
