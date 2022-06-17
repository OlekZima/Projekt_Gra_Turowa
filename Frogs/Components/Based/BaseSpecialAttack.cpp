#include <string>
#include <utility>
#include "BaseSpecialAttack.hpp"

BaseSpecialAttack::BaseSpecialAttack() {};

BaseSpecialAttack::BaseSpecialAttack(std::string specialAttackName_, int SpecialAttackPower_,
                                     int specialAttackAgilityToAvoid, int howManyTimesSpecialAttackCanBeUsed_,
                                     int howManyRoundsWorking_)
        : specialAttackName_(std::move(specialAttackName_)), specialAttackPower_(SpecialAttackPower_),
          howManyTimesSpecialAttackCanBeUsed_(howManyTimesSpecialAttackCanBeUsed_),
          howManyRoundsWorking_(howManyRoundsWorking_) {}

auto BaseSpecialAttack::getSpecialAttackName() const -> std::string {
    return this->specialAttackName_;
}

int BaseSpecialAttack::getSpecialAttackPower_() const {
    return this->specialAttackPower_;
}

int BaseSpecialAttack::getSpecialAttackUses_() const {
    return this->specialAttackUses_;
}

int BaseSpecialAttack::getHowManyTimesSpecialAttackCanBeUsed() const {
    return howManyTimesSpecialAttackCanBeUsed_;
}

auto BaseSpecialAttack::useSpecialAttack() -> void {
    specialAttackUses_++;
}

auto BaseSpecialAttack::resetSpecialAttackUses() -> void {
    specialAttackUses_ = 0;
}

void BaseSpecialAttack::setHowManyRoundsWorking(int howManyRoundsWorking) {
    howManyRoundsWorking_ = howManyRoundsWorking;
}

void BaseSpecialAttack::setSpecialAttackName(const std::string &specialAttackName) {
    specialAttackName_ = specialAttackName;
}

void BaseSpecialAttack::setSpecialAttackPower(int specialAttackPower) {
    specialAttackPower_ = specialAttackPower;
}

void BaseSpecialAttack::setHowManyTimesSpecialAttackCanBeUsed(int howManyTimesSpecialAttackCanBeUsed) {
    howManyTimesSpecialAttackCanBeUsed_ = howManyTimesSpecialAttackCanBeUsed;
}

int BaseSpecialAttack::getHowManyRoundsWorking()  {
    return howManyRoundsWorking_;
}

BaseSpecialAttack::~BaseSpecialAttack() {}






