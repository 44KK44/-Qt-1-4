#ifndef SUBWIDGET_H
#define SUBWIDGET_H

#include <QWidget>
#include <QPushButton>

class subwidget : public QWidget
{
    Q_OBJECT
public:
    explicit subwidget(QWidget *parent = nullptr);

    void sendSlot();
signals:
    void mySignal();

private:
    QPushButton b;
};

#endif // SUBWIDGET_H
