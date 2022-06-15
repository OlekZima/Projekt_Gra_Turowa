#include "BaseOffensiveSpecialAttack.hpp"
#include <iostream>

int BaseOffensiveSpecialAttack::getSpecialAttackAgilityToAvoid() const {
    return BaseSpecialAttack::getSpecialAttackAgilityToAvoid();
}

std::string BaseOffensiveSpecialAttack::getSpecialAttackName() const {
    return BaseSpecialAttack::getSpecialAttackName();
}

SpecialAttackType BaseOffensiveSpecialAttack::getSpecialAttackType() const {
    return specialAttackType_;
}

int BaseOffensiveSpecialAttack::getSpecialAttackDamage() {
    return specialAttackPower_;
}
