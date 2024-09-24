#pragma once

#include "vacation.h"
#include <string>
#include <vector>

namespace models {

class Employee {
public:
    Employee(int id, const std::string& firstName, 
            const std::string& lastName,
            const std::string& patronymic,
            std::vector<Vacation>&& vacations);

    int id() const;
    const std::string& firstName() const;
    const std::string& lastName() const;
    const std::string& patronymic() const;
    const std::vector<Vacation>& vacations() const;

    void setFirstName(const std::string& name);
    void setLastName(const std::string& name);
    void setPatronymic(const std::string& name);
private:
    int m_id;
    std::string m_firstName;
    std::string m_lastName;
    std::string m_patronymic;
    std::vector<Vacation> m_vacations;
};
}
