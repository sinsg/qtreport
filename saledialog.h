#ifndef SALEDIALOG_H
#define SALEDIALOG_H

#include <QDialog>

namespace Ui {
class SaleDialog;
}

class SaleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SaleDialog(QWidget *parent = 0);
    ~SaleDialog();

    //表格事件过滤器
    bool eventFilter( QObject *object, QEvent *event );

    //表格菜单功能
    void show_menu();



private:
    Ui::SaleDialog *ui;
};

#endif // SALEDIALOG_H
