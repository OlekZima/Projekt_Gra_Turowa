#pragma once

#include "../Frogs/Components/Based/BaseFrog.hpp"
#include "../Frogs/FrogsWithType.hpp"

namespace game_functions {
    auto chooseDifficulty() -> int;

    auto frogTypeToString(FrogType type) -> std::string;

    auto specialAttackTypeToString(SpecialAttackType type) -> std::string;

    auto calculateDamageMultiplier(const std::shared_ptr<BaseFrog> &attackingFrog, const std::shared_ptr<BaseFrog> &attackedFrog) -> float;

    auto generateRandomNumber(int min, int max) -> int;

    auto createRandomFrog() -> std::shared_ptr<BaseFrog>;

    auto generateRandomSpecialAttack(const FrogType &frogType) -> std::shared_ptr<BaseSpecialAttack>;

    const std::string &generateRandomName();

    auto Battle(std::array<std::shared_ptr<BaseFrog>, 6> &frogsUserChose, std::array<std::shared_ptr<BaseFrog>, 4> &frogsEnemy) -> void;

    auto attackFrog(std::shared_ptr<BaseFrog> &attackingFrog, std::shared_ptr<BaseFrog> &attackedFrog) -> void;

    auto frogUseSpecialAttack(std::shared_ptr<BaseFrog> &frogToUseSpecialAttack, std::shared_ptr<BaseFrog> &frogToUseOnSA) -> int;

}