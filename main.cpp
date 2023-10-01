#include "mainwindow.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
//    QFile file("D:/dev sda/qt/CrudCiteUniv/assets/AMOLED.qss");
//    QFile file("D:/dev sda/qt/CrudCiteUniv/assets/Aqua.qss");
//    QFile file("D:/dev sda/qt/CrudCiteUniv/assets/ConsoleStyle.qss");
//    QFile file("D:/dev sda/qt/CrudCiteUniv/assets/ElegantDark.qss");
//    QFile file("D:/dev sda/qt/CrudCiteUniv/assets/MacOs.qss");
//    QFile file("D:/dev sda/qt/CrudCiteUniv/assets/ManjaroMix.qss");
//    QFile file("D:/dev sda/qt/CrudCiteUniv/assets/MaterialDark.qss");
//    QFile file("D:/dev sda/qt/CrudCiteUniv/assets/NeonButtons.qss");
//    QFile file("D:/dev sda/qt/CrudCiteUniv/assets/Ubuntu.qss");
    QFile file("D:/dev sda/qt/CrudCiteUniv/assets/Diffnes.qss");
//    QFile file("D:/dev sda/qt/CrudCiteUniv/assets/Wstartpage/Wstartpage.qss");
    file.open(QFile::ReadOnly);

    QString styleSheet { QString(file.readAll()) };

    a.setStyleSheet(styleSheet);

    w.show();
    return a.exec();
}
