#include "vacation.h"

using namespace Vacations::Models;

Vacation::Vacation(int id, int emp_id, const QDate &start, const QDate &end, int days_count):
    m_id(id), m_emp_id(emp_id), m_start(start), m_end(end), m_days_count(days_count)
{

}

int Vacation::emp_id() const
{
    return this->m_emp_id;
}

int Vacation::id() const
{
    return this->m_id;
}

const QDate &Vacation::start() const
{
    return this->m_start;
}

const QDate &Vacation::end() const
{
    return this->m_end;
}

int Vacation::days_count() const
{
    return this->m_days_count;
}
