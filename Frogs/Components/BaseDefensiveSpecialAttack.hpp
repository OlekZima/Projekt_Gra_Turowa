#pragma once

#include "Enums/SpecialAttackType.hpp"
#include "BaseSpecialAttack.hpp"

class BaseDefensiveSpecialAttack : BaseSpecialAttack {
protected:
    SpecialAttackType specialAttackType_ = SpecialAttackType::DEFENSIVE;
    using BaseSpecialAttack::BaseSpecialAttack;

};