#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "saledialog.h"
#include "datadialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    SaleDialog *saleDialog=new SaleDialog(this);
    saleDialog->exec();

}

void MainWindow::on_pushButton_2_clicked()
{
   DataDialog *dataDialog =new DataDialog(this);
   dataDialog->exec();
}
