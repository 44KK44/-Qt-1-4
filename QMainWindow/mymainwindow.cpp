#include "mymainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QDebug>
#include <QToolBar>
#include <QPushButton>
#include <QStatusBar>
#include <QLabel>
#include <QTextEdit>
#include <QDockWidget>

MyMainWindow::MyMainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->resize(600, 400);
    this->setWindowTitle("44KK44的QT学习之旅");

    //菜单栏
    QMenuBar *mBar = menuBar();

    //添加菜单
    QMenu *pFile = mBar->addMenu("文件");

    //添加菜单项，添加动作
    QAction *pNew = pFile->addAction("新建");
    connect(pNew, &QAction::triggered,
            [=]()
            {
                qDebug() << "新建被按下";
            });

    pFile->addSeparator(); //添加分割线

    QAction *pOpen = pFile->addAction("打开");
    connect(pOpen, &QAction::triggered,
            [=]()
            {
                qDebug() << "打开被按下";
            });

    //工具栏，菜单栏的快捷方式
    QToolBar *toolBar = addToolBar("toolBar");

    //工具栏添加快捷键
    toolBar->addAction(pNew);
    toolBar->addAction(pOpen);

    QPushButton *b = new QPushButton(this);
    b->setText("^_^");

    //添加小控件
    toolBar->addWidget(b);

    connect(b, &QPushButton::clicked,
            [=]()
            {
                b->setText("T_T");
            });

    //状态栏
    QStatusBar *sBar = statusBar();

    QLabel *label = new QLabel(this);
    label->setText("Normal text file");
    sBar->addWidget(label);
    sBar->addWidget(new QLabel("status#2", this));

    sBar->addPermanentWidget(new QLabel("status#3", this));

    //核心控件
    QTextEdit *tEdit = new QTextEdit(this);
    setCentralWidget(tEdit);

    //浮动窗口
    QDockWidget *dock = new QDockWidget(this);
    addDockWidget(Qt::RightDockWidgetArea, dock);
    QTextEdit *dtEdit = new QTextEdit(this);
    dock->setWidget(dtEdit);

}

MyMainWindow::~MyMainWindow() {}
