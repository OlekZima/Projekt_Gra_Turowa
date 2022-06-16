#include "../BaseFrog.hpp"
#include "BaseOffensiveSpecialAttack.hpp"

auto calculateDamageMultiplier(const BaseFrog *attackingFrog,
                               BaseFrog *attackedFrog) -> float {

    auto attackingFrogType = attackingFrog->getFrogType();
    auto attackedFrogType = attackedFrog->getFrogType();

    if (attackingFrogType == FrogType::EARTH && attackedFrogType == FrogType::AIR
        || attackingFrogType == FrogType::AIR &&
           (attackedFrogType == FrogType::EARTH || attackedFrogType == FrogType::STEEL)
        || attackingFrogType == FrogType::FIRE &&
           (attackedFrogType == FrogType::WATER || attackedFrogType == FrogType::EARTH)
        || attackingFrogType == FrogType::ICE &&
           (attackedFrogType == FrogType::WATER || attackedFrogType == FrogType::FIRE)
        || attackingFrogType == FrogType::STEEL && attackedFrogType == FrogType::FIRE
        || attackingFrogType == FrogType::WATER && attackedFrogType == FrogType::WATER
        || attackingFrogType == FrogType::STEEL && attackedFrogType == FrogType::STEEL
        || attackingFrogType == FrogType::ICE && attackedFrogType == FrogType::ICE) {
        return 1 / 2;
    } else if (attackingFrogType == FrogType::WATER &&
               (attackedFrogType == FrogType::EARTH || attackedFrogType == FrogType::FIRE)
               || attackingFrogType == FrogType::EARTH &&
                  (attackedFrogType == FrogType::FIRE || attackedFrogType == FrogType::ICE ||
                   attackedFrogType == FrogType::STEEL)
               || attackingFrogType == FrogType::AIR && attackedFrogType == FrogType::ICE
               || attackingFrogType == FrogType::FIRE &&
                  (attackedFrogType == FrogType::ICE || attackedFrogType == FrogType::STEEL)
               || attackingFrogType == FrogType::ICE && attackedFrogType == FrogType::EARTH
               || attackingFrogType == FrogType::STEEL && attackedFrogType == FrogType::AIR) {
        return 2;
    } else {
        return 1;
    }
}
