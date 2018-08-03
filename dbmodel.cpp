#include "dbmodel.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

DbModel::DbModel()
{


}

DbModel::~DbModel()
{

}

bool DbModel::creater()
{

   // "品名"<<"进仓时间"<<"颜色"<<"色号"<<"件数"<<"出仓数量"<<"进仓数量"<<"计费重量"<<"单价"<<"金额"<<"包装"<<"小计"<<"备注";
    bool res;
    res=query->exec("CREATE TABLE salesMemo ( id int PRIMARY KEY, name varchar(30), memodate date, color int, psc_count int, out_count float, in_count float, calc_kg float, price float, sum float, pack float, sum_sum float, remark varchar(255) )");


    qDebug()<< res;

    return res;

}

bool DbModel::connect()
{
    database=new QSqlDatabase;
    *database=QSqlDatabase::addDatabase("QSQLITE");
    database->setDatabaseName("data.db");

    if(!database->open()){
        qDebug() << "数据库打开失败:" << database->lastError();
        return false;
    }
    query=new QSqlQuery(*database);
   return true;
}
