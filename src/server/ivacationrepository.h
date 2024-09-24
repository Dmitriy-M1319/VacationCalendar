#pragma once

#include "vacation.h"

#include <vector>
#include <optional>

namespace repository {

/**
 * Интерфейс репозитория для моделей отпуска
 */
class IVacationRepository {
public:
    virtual std::vector<models::Vacation> getVacationsByEmployeeId(int id) = 0;
    virtual std::optional<models::Vacation> getVacationById(int id) = 0;
    virtual void insertVacation(const models::Vacation& vac) = 0;
    virtual std::optional<models::Vacation> updateVacation(int id, const models::Vacation& vac) = 0;
    virtual void deleteVacation(int id) = 0;
    virtual ~IVacationRepository();
};
}
