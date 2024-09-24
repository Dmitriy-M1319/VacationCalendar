#ifndef TESTREPOSITORY_H
#define TESTREPOSITORY_H

#include <QSql>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QVector>
#include <QString>
#include <QVariant>

#include "testdatamodel.h"

class TestRepository
{
public:
    TestRepository(const QSqlDatabase &db);

    QVector<TestDataModel> select_all_rows();

private:
    QSqlDatabase database;
};

#endif // TESTREPOSITORY_H
