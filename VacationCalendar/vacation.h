#ifndef VACATION_H
#define VACATION_H

#include <QDate>

namespace Vacations::Models
{
    class Vacation
    {
    public:
        Vacation(int id, int emp_id, const QDate &start, const QDate &end);

        int id() const;
        int emp_id() const;
        const QDate &start() const;
        const QDate &end() const;
    private:
        int m_id;
        int m_emp_id;
        QDate m_start;
        QDate m_end;
    };
}
#endif // VACATION_H
