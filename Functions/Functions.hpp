#pragma once

#include "../Frogs/BaseFrog.hpp"

namespace game_functions {
    auto chooseDifficulty() -> int;

    auto generateFrogCollection() -> BaseFrog*;

    auto FrogLvlPromotion(BaseFrog *frogToUpgrade) -> void;

};
