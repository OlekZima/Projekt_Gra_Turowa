#pragma once

#include "Enums/SpecialAttackType.hpp"
#include "../BaseFrog.hpp"
#include <string>

class BaseFrog;

class BaseSpecialAttack {
protected:
    std::string specialAttackName_;
    int specialAttackPower_;
    int specialAttackUses_ = 0;
    int howManyTimesSpecialAttackCanBeUsed_;
    int specialAttackAgilityToAvoid_;
    SpecialAttackType specialAttackType_;
    int howManyRoundsWorking_;

public:
    [[nodiscard]] int getHowManyRoundsWorking() const;

    auto resetSpecialAttackUses() -> void;

    BaseSpecialAttack(std::string specialAttackName_, int specialAttackPower_, int specialAttackAgilityToAvoid_,
                      int howManyTimesSpecialAttackCanBeUsed_, int howManyRoundsWorking_);

    [[nodiscard]] virtual SpecialAttackType getSpecialAttackType_() const = 0;

    [[nodiscard]] int getSpecialAttackPower_() const;

    int getSpecialAttackUses_() const;

    int getHowManyTimesSpecialAttackCanBeUsed() const;

    auto useSpecialAttack()-> void;

    int getSpecialAttackAgilityToAvoid() const;

    auto getSpecialAttackName() const -> std::string;
};