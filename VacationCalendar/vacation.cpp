#include "vacation.h"

using namespace Vacations::Models;

Vacation::Vacation(int id, int emp_id, const QDate &start, const QDate &end):
    m_id(id), m_emp_id(emp_id), m_start(start), m_end(end)
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
