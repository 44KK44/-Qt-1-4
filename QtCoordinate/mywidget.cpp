#include "mywidget.h"
#include <QPushButton>
#include "mybutton.h"

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    //对于主窗口，坐标系统相对于屏幕左上角
    move(900,500);
    this->resize(400,300);

    QPushButton *btn = new QPushButton(this);
    btn->move(175,90);
    btn->setText("^_^");
    btn->resize(50,120);

    QPushButton *btn2 = new QPushButton(btn);
    btn2->move(10,10);
    btn2->setText("@_@");
    btn2->resize(30,30);

    MyButton *btn3 = new MyButton(this);
    btn3->move(175,150);
    btn3->setText("MyButton");
}

MyWidget::~MyWidget() {}
