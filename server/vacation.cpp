#include "vacation.h"

using namespace models;

Vacation::Vacation(int id, int emp_id, const std::string& start, 
            const std::string& end, int daysCount): m_id(id), m_employeeId(emp_id), m_startDate(start), m_endDate(end), m_daysCount(daysCount) {}

int Vacation::id() const {
    return m_id;
}

int Vacation::employeeId() const {
    return m_employeeId;
}

const std::string& Vacation::startDate() const {
    return m_startDate;
}

const std::string& Vacation::endDate() const {
    return m_endDate;
}

int Vacation::daysCount() const {
    return m_daysCount;
}

void Vacation::setEmployeeId(int id) {
    m_employeeId = m_id;
}

void Vacation::setStartDate(const std::string& date) {
    m_startDate = date;
}

void Vacation::setEndDate(const std::string& date) {
    m_endDate = date;
}

void Vacation::setDaysCount(int count) {
    m_daysCount = count;
}
