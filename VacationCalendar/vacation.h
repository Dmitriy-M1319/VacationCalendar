#ifndef VACATION_H
#define VACATION_H

#include <QDate>

namespace Vacations::Models
{
    class Vacation
    {
    public:
        Vacation(int id, const QDate &start, const QDate &end);

        int id() const;
        const QDate &start() const;
        const QDate &end() const;
    private:
        int m_id;
        QDate m_start;
        QDate m_end;
    };
}
#endif // VACATION_H
