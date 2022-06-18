#pragma once

#include "Enums/SpecialAttackType.hpp"
#include "Based/BaseSpecialAttack.hpp"

class DefensiveSpecialAttack : public BaseSpecialAttack {
public:

    using BaseSpecialAttack::BaseSpecialAttack;

    SpecialAttackType getSpecialAttackType_() const override;

    ~DefensiveSpecialAttack() override;
};