#pragma once

#include "iemployeerepository.h"
#include "ivacationrepository.h"

#include <pqxx/pqxx>
#include <memory>

namespace repository {

class EmployeeRepository: public IEmployeeRepository {
public:
    EmployeeRepository(const std::shared_ptr<pqxx::connection>& connection,
            const std::shared_ptr<IVacationRepository>& vacRepo);
    std::vector<models::Employee> getAllEmployees() override;
    std::optional<models::Employee> getEmployeeById(int id) override;
    void insertEmployee(const models::Employee& emp) override;
    std::optional<models::Employee> updateEmployee(int id, const models::Employee& vac) override;
    void deleteEmployee(int id) override;
private:
    std::shared_ptr<pqxx::connection> m_connection;
    std::shared_ptr<IVacationRepository> m_vacRepo;
};
}
