#include "employeerepository.h"

using namespace repository;

EmployeeRepository::EmployeeRepository(const std::shared_ptr<pqxx::connection>& connection,
        const std::shared_ptr<IVacationRepository>& vacRepo) :
    m_connection(connection), m_vacRepo(vacRepo) {}

std::vector<models::Employee> EmployeeRepository::getAllEmployees() {
    pqxx::work selectTransaction(*m_connection);
    std::string query = "SELECT * FROM vacations";

    pqxx::result res = selectTransaction.exec(query);
    selectTransaction.commit();

    std::vector<models::Employee> result;
    for(auto &row: res) {
        auto [id, firstName, lastName, patronymic] = row.as<int, std::string, std::string, std::string>();
        auto vacations = m_vacRepo->getVacationsByEmployeeId(id);
        result.emplace_back(id, firstName, lastName, patronymic, std::move(vacations));
    }
   
    return result;
}

std::optional<models::Employee> EmployeeRepository::getEmployeeById(int id) {
    pqxx::work selectTransaction(*m_connection);
    std::string query = std::format("SELECT * FROM employees WHERE id={}", id);

    pqxx::row res = selectTransaction.exec1(query);
    selectTransaction.commit();

    if(res.num() == -1) {
        return std::nullopt;
    } else {
        auto [id, firstName, lastName, patronymic] = res.as<int, std::string, std::string, std::string>();
        auto vacations = m_vacRepo->getVacationsByEmployeeId(id);
        return models::Employee(id, firstName, lastName, patronymic, std::move(vacations));
    }
}

void EmployeeRepository::insertEmployee(const models::Employee& emp) {
    pqxx::work insertTransaction(*m_connection);
    std::string query = std::format("INSERT INTO employees(first_name, last_name, patronymic) VALUES(\"{}\", \"{}\", {}",
            emp.firstName(), emp.lastName(), emp.patronymic());

    insertTransaction.exec(query);
    insertTransaction.commit();
}

std::optional<models::Employee> EmployeeRepository::updateEmployee(int id, const models::Employee& emp) {
    pqxx::work updateTransaction(*m_connection);
    std::string query = std::format("UPDATE employeees SET first_name=\"{}\",, last_name=\"{}\", patronymic=\"{}\", WHERE id={}",
            emp.firstName(), emp.lastName(), emp.patronymic(), id);

    updateTransaction.exec(query);
    updateTransaction.commit();
    return emp;
}

void EmployeeRepository::deleteEmployee(int id) {
    pqxx::work deleteTransaction(*m_connection);
    std::string query = std::format("DELETE FROM employees WHERE id={}", id);

    deleteTransaction.exec(query);
    deleteTransaction.commit();
}
