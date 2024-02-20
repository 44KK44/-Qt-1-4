#include "mainwidget.h"
#include <QPushButton>


MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    button.setParent(this);
    button.setText("click to close");
    button.move(100, 100);

    button2 = new QPushButton(this);
    button2->setText("T_T");
    button2->move(250, 100);

    connect(&button, &QPushButton::pressed, this, &MainWidget::close);

    connect(button2, &QPushButton::released, this, &MainWidget::close);

    //自定义槽
    //槽函数一定没有返回值

    button3 = new QPushButton(this);
    button3->setText("切换内容");
    button3->move(400, 100);

    connect(button3, &QPushButton::released, this, &MainWidget::MySlot);
    connect(button3, &QPushButton::released, &button, &QPushButton::hide);


}

void MainWidget::MySlot()
{
    button3->setText("123");
}

MainWidget::~MainWidget() {}
