#pragma once

#include "employee.h"

#include <optional>
#include <vector>

#include <vector>
#include <optional>

namespace repository {

/**
 * Интерфейс репозитория для моделей работника
 */
class IEmployeeRepository {
public:
    virtual std::vector<models::Employee> getAllEmployees() = 0;
    virtual std::optional<models::Employee> getEmployeeById(int id) = 0;
    virtual void insertEmployee(const models::Employee& emp) = 0;
    virtual std::optional<models::Employee> updateEmployee(int id, const models::Employee& vac) = 0;
    virtual void deleteEmployee(int id) = 0;
    virtual ~IEmployeeRepository();
};
}
