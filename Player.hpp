#pragma once

#include <array>
#include "Frogs/BaseFrog.hpp"

class Player {
protected:
    std::string playerName;
    std::array<BaseFrog *, 6> playerFrogs;

    Player(std::string playerName, std::array<BaseFrog *, 6> playerFrogs);
};
