#pragma once

#include "../Frogs/BaseFrog.hpp"

namespace game_functions {
    auto chooseDifficulty() -> int;

    auto frogTypeToString(FrogType type) -> std::string;

    auto specialAttackTypeToString(SpecialAttackType type) -> std::string;

    auto randomNumber(int min, int max) -> int;

    auto createRandomFrog() -> std::shared_ptr<BaseFrog>;

    auto generateRandomSpecialAttack(FrogType frogType) -> std::shared_ptr<BaseSpecialAttack>;

    const std::string &generateRandomName();

    auto Battle() -> void;

}
