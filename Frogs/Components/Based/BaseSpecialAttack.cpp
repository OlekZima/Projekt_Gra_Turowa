#include <string>
#include <utility>
#include "BaseSpecialAttack.hpp"

BaseSpecialAttack::BaseSpecialAttack() {};

BaseSpecialAttack::BaseSpecialAttack(std::string specialAttackName_, int SpecialAttackPower_,
                                     int specialAttackAgilityToAvoid, int howManyTimesSpecialAttackCanBeUsed_)
        : specialAttackName_(std::move(specialAttackName_)), specialAttackPower_(SpecialAttackPower_),
          howManyTimesSpecialAttackCanBeUsed_(howManyTimesSpecialAttackCanBeUsed_) {};

BaseSpecialAttack::BaseSpecialAttack(const BaseSpecialAttack &other) {
    this->specialAttackName_ = other.specialAttackName_;
    this->specialAttackPower_ = other.specialAttackPower_;
    this->specialAttackUses_ = other.specialAttackUses_;
    this->howManyTimesSpecialAttackCanBeUsed_ = other.howManyTimesSpecialAttackCanBeUsed_;
    this->howManyRoundsWorking_ = other.howManyRoundsWorking_;
}


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
    return this->howManyTimesSpecialAttackCanBeUsed_;
}

auto BaseSpecialAttack::useSpecialAttack() -> void {
    this->specialAttackUses_++;
}

auto BaseSpecialAttack::resetSpecialAttackUses() -> void {
    this->specialAttackUses_ = 0;
}

void BaseSpecialAttack::setHowManyRoundsWorking(int howManyRoundsWorking) {
    this->howManyRoundsWorking_ = howManyRoundsWorking;
}

void BaseSpecialAttack::setSpecialAttackName(const std::string &specialAttackName) {
    this->specialAttackName_ = specialAttackName;
}

void BaseSpecialAttack::setSpecialAttackPower(int specialAttackPower) {
    this->specialAttackPower_ = specialAttackPower;
}

void BaseSpecialAttack::setHowManyTimesSpecialAttackCanBeUsed(int howManyTimesSpecialAttackCanBeUsed) {
    this->howManyTimesSpecialAttackCanBeUsed_ = howManyTimesSpecialAttackCanBeUsed;
}

int BaseSpecialAttack::getHowManyRoundsWorking() const {
    return this->howManyRoundsWorking_;
}


BaseSpecialAttack::~BaseSpecialAttack() = default;






