#include "employee.h"

using namespace models;


Employee::Employee(int id, const std::string& firstName, 
            const std::string& lastName,
            const std::string& patronymic,
            std::vector<Vacation>&& vacations) : 
    m_id(id), m_firstName(firstName), m_lastName(lastName), m_patronymic(patronymic),
    m_vacations(std::move(vacations)) {}

int Employee::id() const {
    return m_id;
}

const std::string& Employee::firstName() const {
    return m_firstName;
}
    
const std::string& Employee::lastName() const {
    return m_lastName;
}

const std::string& Employee::patronymic() const {
    return m_patronymic;
}

void Employee::setFirstName(const std::string& name) {
    m_firstName = name;
}

void Employee::setLastName(const std::string& name) {
    m_lastName = name;
}

void Employee::setPatronymic(const std::string& name) {
    m_patronymic = name;
}
