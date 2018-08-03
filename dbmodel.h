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

private:
    QSqlDatabase *database;
    QSqlQuery *query;
};

#endif // DBMODEL_H
