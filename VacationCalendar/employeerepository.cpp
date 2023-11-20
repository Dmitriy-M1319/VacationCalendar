#include "employeerepository.h"

using namespace Vacations::Repositories;

EmployeeRepository::EmployeeRepository()
{

}

void EmployeeRepository::set_db(const QSqlDatabase &db)
{
    this->m_db = db;
}

QVector<Vacations::Models::Employee> EmployeeRepository::get_employees()
{
    QVector<Vacations::Models::Employee> result{};
    QSqlQueryModel query;
    query.setQuery("SELECT * FROM employee");

    for(int i = 0; i < query.rowCount(); ++i)
    {
        int id = query.record(i).value("id").toInt();
        QString first_name = query.record(i).value("first_name").toString();
        QString last_name = query.record(i).value("last_name").toString();
        QString patronymic = query.record(i).value("patronymic").toString();
        Models::Employee emp{id, first_name, last_name, patronymic};
        result.push_back(emp);
    }
    return result;
}
