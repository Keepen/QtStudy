#ifndef SUBWIDGET_H
#define SUBWIDGET_H

#include <QWidget>
#include <QPushButton>
class SubWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SubWidget(QWidget *parent = nullptr);
    void dealSwitch();
    void dealSwitch2();
private:
    QPushButton b;

signals:
    void Switch();
    void Switch(int a, QString s);
};

#endif // SUBWIDGET_H
