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
                 QString patronymic,
                 QVector<Vacation> vacations);

        int id() const;
        const QString& first_name();
        const QString& last_name();
        const QString& patronymic();
        const QVector<Vacation> &vacations();

    private:
        int m_id;
        QString m_first_name;
        QString m_last_name;
        QString m_patronymic;
        QVector<Vacation> m_vacations;
    };
}
#endif // EMPLOYEE_H
