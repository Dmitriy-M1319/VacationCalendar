#include "vacationrepository.h"
#include <format>

using namespace repository;

VacationRepository::VacationRepository(const std::shared_ptr<pqxx::connection>& connection) :
    m_connection(connection) {}

std::vector<models::Vacation> VacationRepository::getVacationsByEmployeeId(int id) {
    pqxx::work selectTransaction(*m_connection);
    std::string query = std::format("SELECT * FROM vacations WHERE emp_id={}", id);

    pqxx::result res = selectTransaction.exec(query);
    selectTransaction.commit();

    std::vector<models::Vacation> result;
    for(auto &row: res) {
        auto [id, empId, start, end,daysCount] = row.as<int, int, std::string, std::string, int>();
        result.emplace_back(id, empId, start, end,daysCount);
    }
   
    return result;
}

std::optional<models::Vacation> VacationRepository::getVacationById(int id) {
    pqxx::work selectTransaction(*m_connection);
    std::string query = std::format("SELECT * FROM vacations WHERE id={}", id);

    pqxx::row res = selectTransaction.exec1(query);
    selectTransaction.commit();

    if(res.num() == -1) {
        return std::nullopt;
    } else {
        auto [id, empId, start, end,daysCount] = res.as<int, int, std::string, std::string, int>();
        return models::Vacation(id, empId, start, end,daysCount);
    }
}

void VacationRepository::insertVacation(const models::Vacation& vac) {
    pqxx::work insertTransaction(*m_connection);
    std::string query = std::format("INSERT INTO vacations(emp_id, start, end, count) VALUES({}, \"{}\", \"{}\", {}",
            vac.employeeId(), vac.startDate(), vac.endDate(), vac.daysCount());

    insertTransaction.exec(query);
    insertTransaction.commit();
}

std::optional<models::Vacation> VacationRepository::updateVacation(int id, const models::Vacation& vac) {
    pqxx::work updateTransaction(*m_connection);
    std::string query = std::format("UPDATE vacations SET emp_id={}, start=\"{}\", end=\"{}\", count={} WHERE id={}",
            vac.employeeId(), vac.startDate(), vac.endDate(), vac.daysCount(), id);

    updateTransaction.exec(query);
    updateTransaction.commit();
    return vac;
}

void VacationRepository::deleteVacation(int id) {
    pqxx::work deleteTransaction(*m_connection);
    std::string query = std::format("DELETE FROM vacations WHERE id={}", id);

    deleteTransaction.exec(query);
    deleteTransaction.commit();
}
