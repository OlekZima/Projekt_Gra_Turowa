#include <iostream>
#include <utility>
#include "Enemy.hpp"

Enemy::Enemy(std::string playerName, std::array<BaseFrog *, 4> enemyFrogs) :
        enemyName(std::move(playerName)), enemyFrogs(enemyFrogs) {};


