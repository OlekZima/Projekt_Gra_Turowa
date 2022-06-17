#pragma once

#include <array>
#include "Enums/SpecialAttackType.hpp"
#include "Based/BaseFrog.hpp"
#include "Based/BaseSpecialAttack.hpp"

class OffensiveSpecialAttack : public BaseSpecialAttack {
public:
    using BaseSpecialAttack::BaseSpecialAttack;

    SpecialAttackType getSpecialAttackType_() const override;

    ~OffensiveSpecialAttack() override;
};