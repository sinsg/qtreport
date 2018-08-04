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
    res=query->exec("CREATE TABLE salesMemo ( id int PRIMARY KEY , name varchar(30), memodate date, color int, "
                    "psc_count int, out_count float, in_count float, calc_kg float, price float, sum float,"
                    " pack float, sum_sum float, remark varchar(255),"
                    "number int ,customer varchar(40) )");
     qDebug()<< res<<query->lastError();


     //key 客户名   电话号码   地址
    query->exec("CREATE TABLE customer(id int PRIMARY KEY,customer_name varchar(40),phone_number varchar(15),"
                "address varchar(255))");



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

//获取客户当前欠款金额
// customer_name  客户名
// num 截止单号  例:(1单 -2单的 累计金额)   方便一次性打印单据
// num 为0 则获取该客户所有单据的欠款金额
int DbModel::getSum(QString customer_name, int num)
{

    int sum=0;
    if(num==0){
        query->exec("SELECT sum_sum FROM  salesMemo WHERE customer = "+customer_name);

    }else{

        query->exec("SELECT sum_sum FROM  salesMemo WHERE customer = "+customer_name+"AND number<="+num);
    }

    while(query->next()){

       sum+= query->value(0).toInt();
    }
    return sum;
}
