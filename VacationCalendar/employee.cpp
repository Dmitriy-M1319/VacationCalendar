#include "employee.h"

using namespace Vacations::Models;

Employee::Employee(int id,
                   QString first_name,
                   QString last_name,
                   QString patronymic):
    m_id(id),
    m_first_name(first_name),
    m_last_name(last_name),
    m_patronymic(patronymic)
{

}

int Employee::id() const
{
    return this->m_id;
}

const QString &Employee::first_name() const
{
    return this->m_first_name;
}

const QString &Employee::last_name() const
{
    return this->m_last_name;
}

const QString &Employee::patronymic() const
{
    return this->m_patronymic;
}

const QVector<Vacation> &Employee::vacations() const
{
    return this->m_vacations;
}

void Employee::set_vacations(const QVector<Vacation> &vacations)
{
    this->m_vacations = vacations;
}

int Employee::get_vacation_days_count(int month_index) const
{
    foreach (const Vacation& vac, m_vacations)
    {
        if(vac.start().month() == month_index || vac.end().month() == month_index)
            return vac.days_count();
    }
    return 0;
}
