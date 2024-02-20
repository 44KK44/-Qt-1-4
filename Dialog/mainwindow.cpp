#include "mainwindow.h"
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    QMenuBar *mBar = menuBar();
    setMenuBar(mBar);
    QMenu *file = mBar->addMenu("对话框");
    QAction *p1 = file->addAction("模态对话框");
    connect(p1, &QAction::triggered,
            [=]()
            {
                QDialog dlg;
                dlg.exec();
                qDebug() << "111";
            }
            );
    QAction *p2 = file->addAction("非模态对话框");
    connect(p2, &QAction::triggered,
            [=]()
            {
                // QDialog *dlg = new QDialog(this);
                // dlg->setAttribute(Qt::WA_DeleteOnClose);
                // dlg.show();
                // qDebug() << "222";


                // QDialog *dlg = new QDialog(this);
                // dlg->show();


                QDialog *dlg = new QDialog;
                dlg->setAttribute(Qt::WA_DeleteOnClose);
                dlg->show();
            }
            );

    QAction *p3 = file->addAction("关于对话框");
    connect(p3, &QAction::triggered,
            [=]()
            {
                QMessageBox::about(this, "about", "关于Qt");
            }
            );

    QAction *p4 = file->addAction("问题对话框");
    connect(p4, &QAction::triggered,
            [=]()
            {
                int ret = QMessageBox::question(this, "question", "Are you ok?");
                switch (ret)
                {
                case QMessageBox::Yes:
                    qDebug() << "Yes";
                    break;
                case QMessageBox::No:
                    qDebug() << "No";
                    break;
                default:
                    break;
                }
            }
            );

    QAction *p5 = file->addAction("文件对话框");
    connect(p5, &QAction::triggered,
            [=]()
            {
                QString path = QFileDialog::getOpenFileName(this, "open", "../", "source(*.cpp *.h);;Text(*.txt);;All(*.*) ");
                qDebug() << path;
            }
            );
}

MainWindow::~MainWindow() {}
