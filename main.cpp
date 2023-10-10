#include "mainwindow.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QFile file("D:/dev sda/qt/CrudCiteUniv/assets/Diffnes.qss");
    file.open(QFile::ReadOnly);

    QString styleSheet { QString(file.readAll()) };

    a.setStyleSheet(styleSheet);

    a.setWindowIcon(QIcon(":image/assets/batiment.png"));

    w.show();
    return a.exec();
}
