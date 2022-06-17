#pragma once

#include "../BaseFrog.hpp"
#include "BaseOffensiveSpecialAttack.hpp"


auto calculateDamageMultiplier(const BaseFrog *attackingFrog,
                               std::shared_ptr<BaseFrog> attackedFrog) -> float;

