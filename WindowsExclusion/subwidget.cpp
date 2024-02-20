#include "subwidget.h"

subwidget::subwidget(QWidget *parent)
    : QWidget{parent}
{
    this->setWindowTitle("子窗口");
    b.setParent(this);
    b.setText("切换到主窗口");

    connect(&b, &QPushButton::released, this, &subwidget::sendSlot);

    resize(400, 300);
}

void subwidget::sendSlot()
{
    emit mySignal();
}
