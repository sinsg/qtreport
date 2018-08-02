#include "saledialog.h"
#include "ui_saledialog.h"
#include "QStringList"
#include "QEvent"
#include "QDebug"
#include "QContextMenuEvent"
#include "QMenu"
#include "QComboBox"

SaleDialog::SaleDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SaleDialog)
{
    ui->setupUi(this);

    QStringList headerLabels;
    headerLabels<<"品名"<<"进仓时间"<<"颜色"<<"色号"<<"件数"<<"出仓数量"<<"进仓数量"<<"计费重量"<<"单价"<<"金额"<<"包装"<<"小计"<<"备注";
    ui->tableWidget->setColumnCount(headerLabels.count());
    ui->tableWidget->setRowCount(11);
    ui->tableWidget->setHorizontalHeaderLabels(headerLabels);

   // ui->tableWidget->item(0,9)->setFlags(Qt::ItemIsEnabled);// Qt::ItemIsEnabled   需要建立一个 Qtableitem 才可设置


    //注册事件过滤器
    ui->tableWidget->installEventFilter(this);



//tablewidget 中插入widget
//    QComboBox *boBox=new QComboBox;
//    boBox->setEditable(true);
//    ui->tableWidget->setCellWidget(0,0,boBox);
//    QTableWidget *tw=new QTableWidget;
//    tw->setColumnCount(3);
//    tw->setRowCount(3);
//    ui->tableWidget->setCellWidget(1,1,tw);



}

SaleDialog::~SaleDialog()
{
    delete ui;
}

// 事件过滤器
bool SaleDialog::eventFilter(QObject *object, QEvent *event)
{

    if (object == ui->tableWidget)
    {

        if( event->type() ==82) {   // 82  鼠标右击事件 ContextMenu



            //类型转换
           // QContextMenuEvent *cme=static_cast<QContextMenuEvent *>(event);

           //获取对象 并转换类
            //QTableWidget *tw=static_cast<QTableWidget *>(object);
            //qDebug()<<ui->tableWidget->currentIndex().row();

            //qDebug()<<"右键 "<<event<<cme->x()<<cme->y();
            this->show_menu();

        }
    }

    // 注意这里，未处理的事件，要返还给上一级的事件处理函数。
    return QWidget::eventFilter(object, event);

}

//表格菜单功能
void SaleDialog::show_menu()
{
    //设置菜单选项
    QMenu *menu = new QMenu(ui->tableWidget);
    QAction *pnew = new QAction("增加行",ui->tableWidget);
    QAction *pnew1 = new QAction("删除行",ui->tableWidget);



   connect (pnew,SIGNAL(triggered()),this,SLOT(clickaddrow()));



    connect (pnew1,SIGNAL(triggered()),this,SLOT(clickrmrow()));


    menu->addAction(pnew);
    menu->addAction(pnew1);
    menu->move (cursor ().pos ());
    menu->show ();
}

void SaleDialog::clickaddrow()
{
    qDebug()<<"增加";
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
}

void SaleDialog::clickrmrow()
{
    ui->tableWidget->removeRow(ui->tableWidget->currentRow());
}




