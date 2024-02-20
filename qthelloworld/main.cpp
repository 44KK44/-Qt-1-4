#include <QApplication>
#include <QWidget>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget w;
    w.setWindowTitle("蛋天帝独断万古");//设置窗口标题

    QPushButton button;
    button.setText(">_<");//设置按钮文本
    button.setParent(&w);//设置父窗口
    button.move(100, 100); //设置按钮位置

    QPushButton button2(&w);
    button2.setText("^_^");
    button2.move(300, 100);

    // QPushButton button;
    // button.setText(">_<");
    // button.show();

    w.show();//显示窗口

    a.exec();//进入消息循环
    return 0;
}
