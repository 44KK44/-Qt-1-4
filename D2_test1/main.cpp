#include "mywidget.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "D2_test1_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    MyWidget w;
    w.show();
    //窗口出现15秒倒计时，并且在倒计时结束时关闭窗口
    QTimer::singleShot(15000, &w, SLOT(close()));

    return a.exec();
}
