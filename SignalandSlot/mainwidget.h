#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPushButton>

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

    void MySlot();

private:
    QPushButton button;
    QPushButton *button2;
    QPushButton *button3;
};
#endif // MAINWIDGET_H
