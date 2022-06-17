#pragma once

#include "../Frogs/Components/Based/BaseFrog.hpp"
#include "../Frogs/FrogsWithType.hpp"

namespace game_functions {
    auto chooseDifficulty() -> int;

    auto frogTypeToString(FrogType type) -> std::string;

    auto specialAttackTypeToString(SpecialAttackType type) -> std::string;

    auto calculateDamageMultiplier(const BaseFrog *attackingFrog,
                                   std::shared_ptr<BaseFrog> attackedFrog) -> float;

    auto createRandomFrog() -> std::shared_ptr<BaseFrog>;

    auto generateRandomSpecialAttack(const FrogType &frogType) -> std::shared_ptr<BaseSpecialAttack>;

    const std::string &generateRandomName();

    auto Battle(std::array<std::shared_ptr<BaseFrog>, 6> &frogsUserChose,
                std::array<std::shared_ptr<BaseFrog>, 4> &frogsEnemy) -> void;

}
