#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QString>
#include <QVector>
#include "vacation.h"

namespace Vacations::Models
{
    class Employee
    {
    public:
        Employee(int id,
                 QString first_name,
                 QString last_name,
                 QString patronymic);

        int id() const;
        const QString& first_name() const;
        const QString& last_name() const ;
        const QString& patronymic() const;
        const QVector<Vacation> &vacations() const;
        void set_vacations(const QVector<Vacation> &vacations);
        int get_vacation_days_count(int month_index) const;
        QString get_fio() const;

    private:
        int m_id;
        QString m_first_name;
        QString m_last_name;
        QString m_patronymic;
        QVector<Vacation> m_vacations;
    };
}
#endif // EMPLOYEE_H
