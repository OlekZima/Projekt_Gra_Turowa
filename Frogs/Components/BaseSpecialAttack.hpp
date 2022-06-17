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
    SpecialAttackType specialAttackType_;
    int howManyRoundsWorking_;

public:

    ///CONSTRUCTORS AND DESTRUCTOR

    BaseSpecialAttack();
    BaseSpecialAttack(std::string specialAttackName_, int specialAttackPower_, int specialAttackAgilityToAvoid_,
                      int howManyTimesSpecialAttackCanBeUsed_, int howManyRoundsWorking_);

    virtual ~BaseSpecialAttack();


    ///GETTERS

    int getHowManyRoundsWorking() const;
    int getSpecialAttackPower_() const;
    int getSpecialAttackUses_() const;
    int getHowManyTimesSpecialAttackCanBeUsed() const;
    virtual SpecialAttackType getSpecialAttackType_() const = 0;
    auto getSpecialAttackName() const -> std::string;

    ///SETTERS

    void setHowManyRoundsWorking(int howManyRoundsWorking);
    void setSpecialAttackName(const std::string &specialAttackName);
    void setSpecialAttackPower(int specialAttackPower);
    void setHowManyTimesSpecialAttackCanBeUsed(int howManyTimesSpecialAttackCanBeUsed);

    ///FUNCTIONS

    auto resetSpecialAttackUses() -> void;
    auto useSpecialAttack() -> void;

};