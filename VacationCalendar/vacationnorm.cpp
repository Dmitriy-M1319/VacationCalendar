#include "vacationnorm.h"

using namespace Vacations::Models;

VacationNorm::VacationNorm(int id,
                           const QString &month,
                           int vacations_count):
    m_id(id), m_month(month), m_vacations_count(vacations_count)
{

}

int VacationNorm::id() const
{
    return this->m_id;
}

const QString &VacationNorm::month() const
{
    return this->m_month;
}

int VacationNorm::vacations_count() const
{
    return this->m_vacations_count;
}
