#include "vacationnormrepository.h"

using namespace Vacations::Repositories;

VacationNormRepository::VacationNormRepository() {}

VacationNormRepository::VacationNormRepository(const QSqlDatabase& db): m_db(db)
{

}

void VacationNormRepository::set_db(const QSqlDatabase &db)
{
    this->m_db = db;
}

QVector<Vacations::Models::VacationNorm> VacationNormRepository::get_all_normas()
{
    QVector<Models::VacationNorm> result{};
    QSqlQueryModel query;
    query.setQuery("SELECT * FROM vacation_norm");

    for(int i = 0; i < query.rowCount(); ++i)
    {
        int id = query.record(i).value("id").toInt();
        QString month = query.record(i).value("month").toString();
        int count =query.record(i).value("vacations_count").toInt();
        Models::VacationNorm norm{id, month, count};
        result.push_back(norm);
        qDebug() << norm.id() << ' ' << norm.month() << ' ' << norm.vacations_count() << '\n';
    }
    return result;
}
