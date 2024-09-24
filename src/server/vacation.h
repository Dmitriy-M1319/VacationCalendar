#pragma once

#include <string>

namespace models {

class Vacation {
public:
    Vacation(int id, int emp_id, const std::string& start, 
            const std::string& end, int daysCount);

    int id() const;
    int employeeId() const;
    const std::string& startDate() const;
    const std::string& endDate() const;
    int daysCount() const;

    void setEmployeeId(int id);
    void setStartDate(const std::string& date);
    void setEndDate(const std::string& date);
    void setDaysCount(int count);

private:
    int m_id;
    int m_employeeId;
    std::string m_startDate;
    std::string m_endDate;
    int m_daysCount;
};
}
