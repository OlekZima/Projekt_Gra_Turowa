#pragma once

#include "Enums/SpecialAttackType.hpp"
#include "Based/BaseSpecialAttack.hpp"

class DefensiveSpecialAttack :public BaseSpecialAttack {
protected:
    SpecialAttackType specialAttackType_ = SpecialAttackType::DEFENSIVE;

public:
    using BaseSpecialAttack::BaseSpecialAttack;
    SpecialAttackType getSpecialAttackType_() const override;

    ~DefensiveSpecialAttack() override;
};