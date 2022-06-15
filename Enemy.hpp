#pragma once

#include <string>
#include <vector>
#include <array>
#include "Frogs/BaseFrog.hpp"

class Enemy {
protected:
    std::string enemyName;
    std::array<BaseFrog *, 4> enemyFrogs;

public:
    Enemy(std::string playerName, std::array<BaseFrog *, 4> enemyFrogs);
};