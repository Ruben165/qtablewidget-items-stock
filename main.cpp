#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    a.setStyle("windowsxp");
    w.show();
    return a.exec();
}

// By: 2540124633 - Lie Reubensto
