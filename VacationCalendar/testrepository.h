#ifndef TESTREPOSITORY_H
#define TESTREPOSITORY_H

#include <QSql>
#include <QVector>
#include <QString>

#include "testdatamodel.h"

class TestRepository
{
public:
    TestRepository(QSqlDatabase *db);

    QVector<TestDataModel> select_all_rows();

private:
    QSqlDatabase *database;
};

#endif // TESTREPOSITORY_H
