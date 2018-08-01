#include "mainwindow.h"
#include <QApplication>
#include "salewindow.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    SaleWindow sale;
    sale.show();


    return a.exec();
}
