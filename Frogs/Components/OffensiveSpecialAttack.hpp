#pragma once

#include <array>
#include "Enums/SpecialAttackType.hpp"
#include "../BaseFrog.hpp"
#include "BaseSpecialAttack.hpp"

class OffensiveSpecialAttack : public BaseSpecialAttack {
protected:
    SpecialAttackType specialAttackType_ = SpecialAttackType::OFFENSIVE;
    using BaseSpecialAttack::BaseSpecialAttack;

public:
    SpecialAttackType getSpecialAttackType_() const override;

    ~OffensiveSpecialAttack() override;
};