#include "testrepository.h"

TestRepository::TestRepository(const QSqlDatabase &db)
{
    this->database = db;
}

QVector<TestDataModel> TestRepository::select_all_rows() {
    QSqlQuery query{this->database};
    if(query.prepare(QString("SELECT id, emp_id, to_char(vacation_start, 'YYYY-MM-DD') AS start,"
                              "to_char(vacation_end, 'YYYY-MM-DD') AS end from vacations;"))) {
        return QVector<TestDataModel>{};
    }

    QVector<TestDataModel> result{};
    query.exec();
    while (query.next()) {
        int id = query.value(0).toInt();
        QString data = query.value(1).toString();
        result.push_back(TestDataModel{id, data});
    }

    return result;
}
