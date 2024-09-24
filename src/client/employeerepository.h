#ifndef EMPLOYEEREPOSITORY_H
#define EMPLOYEEREPOSITORY_H

#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QVector>
#include <QString>
#include "employee.h"

namespace Vacations::Repositories
{
    class EmployeeRepository
    {
    public:
        EmployeeRepository();
        void set_db(const QSqlDatabase& db);
        QVector<Vacations::Models::Employee> get_employees();
    private:
        QSqlDatabase m_db;
    };
}
#endif // EMPLOYEEREPOSITORY_H
