#pragma once

#include "ivacationrepository.h"

#include <pqxx/pqxx>
#include <memory>

namespace repository {

class VacationRepository: public IVacationRepository {
public:
    VacationRepository(const std::shared_ptr<pqxx::connection>& connection);
    std::vector<models::Vacation> getVacationsByEmployeeId(int id) override;
    std::optional<models::Vacation> getVacationById(int id) override;
    void insertVacation(const models::Vacation& vac) override;
    std::optional<models::Vacation> updateVacation(int id, const models::Vacation& vac) override;
    void deleteVacation(int id) override;
private:
        std::shared_ptr<pqxx::connection> m_connection;
};
}
