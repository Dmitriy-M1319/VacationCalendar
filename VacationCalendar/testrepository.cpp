#include "testrepository.h"

TestRepository::TestRepository(QSqlDatabase *db)
{
    this->database = db;
}

QVector<TestDataModel> TestRepository::select_all_rows() {
    QSqlQuery *query = new QSqlQuery(this->database);
    if(query->prepare(QString("SELECT id, data FROM test_table"))) {
        delete query;
        return QVector<TestDataModel{};
    }

    QVector<TestDataModel> result{};
    query->exec();
    while (query->next()) {
        result.push_back(TestDataModel(query->value(0).toInt(),
                                       query->value(1).toString()));
    }

    delete query;
    return result;
}
