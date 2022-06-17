#pragma once

#include "Enums/SpecialAttackType.hpp"
#include "BaseSpecialAttack.hpp"

class DefensiveSpecialAttack : public BaseSpecialAttack {
protected:
    SpecialAttackType specialAttackType_ = SpecialAttackType::DEFENSIVE;
    using BaseSpecialAttack::BaseSpecialAttack;

public:
    SpecialAttackType getSpecialAttackType_() const override;

    ~DefensiveSpecialAttack() override;
};