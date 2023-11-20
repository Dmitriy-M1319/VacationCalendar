#ifndef VACATIONNORM_H
#define VACATIONNORM_H

#include <QString>

namespace Vacations::Models
{
    class VacationNorm
    {
    public:
        VacationNorm(int id,
                     const QString &month,
                     int vacations_count);
        int id() const;
        const QString &month() const;
        int vacations_count() const;
    private:
        int m_id;
        QString m_month;
        int m_vacations_count;
    };
}
#endif // VACATIONNORM_H
