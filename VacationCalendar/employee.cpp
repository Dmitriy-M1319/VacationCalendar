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

const QString &Employee::first_name()
{
    return this->m_first_name;
}

const QString &Employee::last_name()
{
    return this->m_last_name;
}

const QString &Employee::patronymic()
{
    return this->m_patronymic;
}

const QVector<Vacation> &Employee::vacations()
{
    return this->m_vacations;
}

void Employee::set_vacations(const QVector<Vacation> &vacations)
{
    this->m_vacations = vacations;
}
