#pragma once

#include <array>
#include "Enums/SpecialAttackType.hpp"
#include "../BaseFrog.hpp"
#include "BaseSpecialAttack.hpp"

class BaseOffensiveSpecialAttack : BaseSpecialAttack {
protected:
    std::string baseOffensiveSpecialAttackName_;
    SpecialAttackType specialAttackType_ = SpecialAttackType::OFFENSIVE;
    using BaseSpecialAttack::BaseSpecialAttack;

public:

    int getSpecialAttackAgilityToAvoid() const;

    std::string getSpecialAttackName() const;

    SpecialAttackType getSpecialAttackType() const;


    int getSpecialAttackDamage();
};