#ifndef DBMODEL_H
#define DBMODEL_H

#include <QSqlDatabase>
#include <QSqlQuery>



class DbModel
{
public:
    DbModel();
    ~DbModel();
    bool creater();
    bool connect();

    //获取客户当前欠款金额
    int getSum(QString customer_name,int num);


private:
    QSqlDatabase *database;
    QSqlQuery *query;
};

#endif // DBMODEL_H
