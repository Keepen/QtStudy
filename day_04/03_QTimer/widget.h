#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>   //创建定时器对象
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_buttonStart_clicked();

    void on_buttonStop_clicked();

private:
    Ui::Widget *ui;
    QTimer* myTimer;
};
#endif // WIDGET_H
