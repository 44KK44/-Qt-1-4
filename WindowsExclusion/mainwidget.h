#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPushButton>
#include "subwidget.h"

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();
    void ChangeWin();
    void dealSub();

private:
    QPushButton b1;

    subwidget w;
};
#endif // MAINWIDGET_H
