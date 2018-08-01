#ifndef SALEWINDOW_H
#define SALEWINDOW_H

#include <QMainWindow>

namespace Ui {
class SaleWindow;
}

class SaleWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SaleWindow(QWidget *parent = 0);
    ~SaleWindow();

private:
    Ui::SaleWindow *ui;
};

#endif // SALEWINDOW_H
