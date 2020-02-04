#include "mybutton.h"

MyButton::MyButton(QWidget *parent) : QPushButton(parent)
{

}


MyButton::~MyButton(){
    qDebug() << "mybutton delete!!!";
}
