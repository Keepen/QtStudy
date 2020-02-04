#ifndef MYBUTTON_H
#define MYBUTTON_H
#include <QDebug>
#include <QWidget>
#include <QPushButton>

class MyButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyButton(QWidget *parent = nullptr);
    ~MyButton();
signals:

};

#endif // MYBUTTON_H
