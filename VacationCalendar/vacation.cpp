#include "vacation.h"

using namespace Vacations::Models;

Vacation::Vacation(int id, const QDate &start, const QDate &end):
    m_id(id), m_start(start), m_end(end)
{

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
