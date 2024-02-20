#include "mainwidget.h"
#include <QPushButton>
MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowTitle("主窗口");
    b1.setParent(this);
    b1.setText("切换到子窗口");

    //w.show();

    connect(&b1, &QPushButton::released, this, &MainWidget::ChangeWin);

    connect(&w, &subwidget::mySignal, this, &MainWidget::dealSub);

    resize(400, 300);
}

void MainWidget::ChangeWin()
{
    this->hide();
    w.show();
}

void MainWidget::dealSub()
{
    w.hide();
    this->show();
}

MainWidget::~MainWidget() {}
