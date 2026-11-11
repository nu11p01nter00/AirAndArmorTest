#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyleSheet("* {background-color: rgb(77, 93, 83); color: white}"
                    "QPushButton {background-color: rgb(57, 73, 63); border-color: rgb(57, 73, 63)}");
    MainWindow w;
    w.show();
    //w.show();
    return QApplication::exec();
}
