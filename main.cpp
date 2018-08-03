#include "mainwindow.h"
#include <QApplication>
#include "salewindow.h"
#include "dbmodel.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    DbModel db;
    db.connect();
    db.creater();


    return a.exec();
}
