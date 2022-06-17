#pragma once

#include "../BaseFrog.hpp"
#include "OffensiveSpecialAttack.hpp"


auto calculateDamageMultiplier(const BaseFrog *attackingFrog,
                               std::shared_ptr<BaseFrog> attackedFrog) -> float;

