#include "Player.hpp"
#include <utility>

Player::Player(std::string playerName, std::array<BaseFrog *, 6> playerFrogs) : playerName(std::move(playerName)),
                                                                                playerFrogs(playerFrogs) {};

