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


return true;

}

bool DbModel::connect()
{
    database=new QSqlDatabase;
    database->addDatabase("sqlite");
    database->setDatabaseName("data.db");
    if(!database->open()){
        return false;
    }
   return true;
}
