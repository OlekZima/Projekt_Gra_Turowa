#pragma once

#include "../BaseFrog.hpp"
#include "BaseOffensiveSpecialAttack.hpp"


auto calculateDamageMultiplier(const BaseFrog *attackingFrog,
                               BaseFrog *attackedFrog) -> float;

