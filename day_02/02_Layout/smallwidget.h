#ifndef SMALLWIDGET_H
#define SMALLWIDGET_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

class SmallWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SmallWidget(QWidget *parent = nullptr);

signals:

};

#endif // SMALLWIDGET_H
