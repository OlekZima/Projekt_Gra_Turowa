#pragma once

#include <array>
#include "Enums/SpecialAttackType.hpp"
#include "Based/BaseFrog.hpp"
#include "Based/BaseSpecialAttack.hpp"

class OffensiveSpecialAttack : public BaseSpecialAttack {
protected:
    SpecialAttackType specialAttackType_ = SpecialAttackType::OFFENSIVE;

public:
    using BaseSpecialAttack::BaseSpecialAttack;
    SpecialAttackType getSpecialAttackType_() const override;

    ~OffensiveSpecialAttack() override;
};