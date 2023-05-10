
#include "mainwindow.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include<QTimer>
#include<QSplashScreen>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "EletricData_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    QSplashScreen *telaSplash=new QSplashScreen;
    MainWindow w;
    telaSplash->setPixmap(QPixmap(":/spash/imgs/spash/spash.jpg"));
    telaSplash->show();

    QTimer::singleShot(1000,telaSplash,SLOT(close()));
    QTimer::singleShot(1000,&w,SLOT(show()));



    return a.exec();
}
