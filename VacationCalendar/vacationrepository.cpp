#include "vacationrepository.h"

using namespace Vacations::Repositories;

VacationRepository::VacationRepository()
{

}

VacationRepository::VacationRepository(const QSqlDatabase& db): m_db(db)
{

}

void VacationRepository::set_db(const QSqlDatabase &db)
{
    this->m_db = db;
}

QVector<Vacations::Models::Vacation> VacationRepository::get_vacations_for_employee(int employee_id)
{
    QVector<Models::Vacation> result{};
    QSqlQueryModel query;
    query.setQuery("select id, emp_id, to_char(vacation_start, 'YYYY-MM-DD') as start,"
                   "to_char(vacation_end, 'YYYY-MM-DD') as end from vacations;");

    for(int i = 0; i < query.rowCount(); ++i)
    {
        int emp_id = query.record(i).value("emp_id").toInt();
        if(emp_id == employee_id)
        {
            int id = query.record(i).value("id").toInt();
            QDate start = QDate::fromString(query.record(i).value("start").toString(), "yyyy-MM-dd");
            QDate end = QDate::fromString(query.record(i).value("end").toString(), "yyyy-MM-dd");
            Vacations::Models::Vacation v{id, emp_id, start, end};
            result.push_back(v);
        }

    }
    return result;
}
