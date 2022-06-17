#include <string>
#include <utility>
#include "BaseSpecialAttack.hpp"

BaseSpecialAttack::BaseSpecialAttack(std::string specialAttackName_, int SpecialAttackPower_,
                                     int specialAttackAgilityToAvoid, int howManyTimesSpecialAttackCanBeUsed_,
                                     int howManyRoundsWorking_)
        : specialAttackName_(std::move(specialAttackName_)), specialAttackPower_(SpecialAttackPower_),
          specialAttackAgilityToAvoid_(specialAttackAgilityToAvoid),
          howManyTimesSpecialAttackCanBeUsed_(howManyTimesSpecialAttackCanBeUsed_),
          howManyRoundsWorking_(howManyRoundsWorking_) {}

auto BaseSpecialAttack::getSpecialAttackName() const -> std::string {
    return this->specialAttackName_;
}

int BaseSpecialAttack::getSpecialAttackPower_() const {
    return specialAttackPower_;
}

int BaseSpecialAttack::getSpecialAttackUses_() const {
    return specialAttackUses_;
}

int BaseSpecialAttack::getSpecialAttackAgilityToAvoid() const {
    return this->specialAttackAgilityToAvoid_;
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

int BaseSpecialAttack::getHowManyRoundsWorking() const {
    return howManyRoundsWorking_;
}

void BaseSpecialAttack::setHowManyRoundsWorking(int howManyRoundsWorking) {
    howManyRoundsWorking_ = howManyRoundsWorking;
}



