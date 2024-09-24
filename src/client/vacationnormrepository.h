#ifndef VACATIONNORMREPOSITORY_H
#define VACATIONNORMREPOSITORY_H

#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QVector>
#include <QDebug>
#include "vacationnorm.h"

namespace Vacations::Repositories
{
    class VacationNormRepository
    {
    public:
        VacationNormRepository();
        VacationNormRepository(const QSqlDatabase& db);
        void set_db(const QSqlDatabase& db);
        QVector<Vacations::Models::VacationNorm> get_all_normas();
    private:
        QSqlDatabase m_db;
    };
}
#endif // VACATIONNORMREPOSITORY_H
