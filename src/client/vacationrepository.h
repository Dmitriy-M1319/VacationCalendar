#ifndef VACATIONREPOSITORY_H
#define VACATIONREPOSITORY_H

#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QVector>
#include <QDebug>
#include "vacation.h"

namespace Vacations::Repositories {

    class VacationRepository
    {
    public:
        VacationRepository();
        VacationRepository(const QSqlDatabase& db);
        void set_db(const QSqlDatabase& db);
        QVector<Vacations::Models::Vacation> get_vacations_for_employee(int employee_id);
    private:
        QSqlDatabase m_db;
    };

}

#endif // VACATIONREPOSITORY_H
