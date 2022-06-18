#include "BaseFrog.hpp"
#include "../../../Functions/Functions.hpp"
#include <iostream>
#include <utility>

BaseFrog::BaseFrog(std::string frogName, int frogMaxHealth_, int frogMaxPower_, int frogMaxAgility_) :
        frogName_(std::move(frogName)), frogMaxPower_(frogMaxPower_), frogMaxHealth_(frogMaxHealth_),
        frogMaxAgility_(frogMaxAgility_) {

    frogCurrentHp_ = frogMaxHealth_;
    frogAgility_ = frogMaxAgility_;
    frogPower_ = frogMaxPower_;
    frogExpPoints_ = 0;
    frogLevel_ = 1;
    isAlive_ = true;
}

BaseFrog::BaseFrog(const BaseFrog &other) {
    this->frogName_ = other.frogName_;
    this->frogMaxHealth_ = other.frogMaxHealth_;
    this->frogMaxAgility_ = other.frogMaxAgility_;
    this->frogAgility_ = other.frogAgility_;
    this->frogMaxPower_ = other.frogMaxPower_;
    this->frogCurrentHp_ = other.frogCurrentHp_;
    this->frogPower_ = other.frogPower_;
    this->frogExpPoints_ = other.frogExpPoints_;
    this->frogLevel_ = other.frogLevel_;
    this->frogExpToTheNextLvl = other.frogExpToTheNextLvl;
    this->frogExpGive_ = other.frogExpGive_;
    this->frogSpecialAttack_ = other.frogSpecialAttack_;
    this->isAlive_ = other.isAlive_;
}

BaseFrog::BaseFrog() {
    frogExpPoints_ = 0;
    frogLevel_ = 1;
    isAlive_ = true;
}


BaseFrog::~BaseFrog() =
default;


auto BaseFrog::setCurrentHp(int health) -> void {
    this->frogCurrentHp_ = health;
}


auto BaseFrog::getExpPoints() const -> int {
    return this->frogExpPoints_;
}

auto BaseFrog::setPower(int power) -> void {
    this->frogPower_ = power;

}

const std::string &BaseFrog::getFrogName() const {
    return frogName_;
}

int BaseFrog::getFrogAgility() const {
    return frogAgility_;
}

int BaseFrog::getFrogLevel() const {
    return frogLevel_;
}

/**
 * funkcja
 */

auto BaseFrog::printLvlPromotion() -> void {
    std::cout << "Congratulations! Your " << this->frogName_ << "have reached level up! (" << this->frogLevel_
              << "!)\n";
    this->frogLevel_++;
    this->frogExpPoints_ = this->getFrogExpToTheNextLvl() - this->frogExpPoints_;
}

int BaseFrog::getFrogExpGive() const {
    return frogExpGive_;
}

auto BaseFrog::checkIfDead() -> bool {
    if (this->frogCurrentHp_ <= 0) {
        this->declareDeadAndPrintDeadMessage();
        return true;
    } else {
        return false;
    }
}

auto BaseFrog::declareDeadAndPrintDeadMessage() -> void {
    this->isAlive_ = false;
    std::cout << "Frog " << this->frogName_ << " is dead!\n";
}

/*bool BaseFrog::isAlive() const {
    return isAlive_;
}*/


int BaseFrog::getFrogMaxHealth() const {
    return frogMaxHealth_;
}

auto BaseFrog::restoreHealth() -> void {
    this->frogCurrentHp_ = this->getFrogMaxHealth();

}

auto BaseFrog::restoreStats() -> void {
    this->frogPower_ = this->getFrogMaxPower();
    this->frogAgility_ = this->getFrogMaxAgility();

}

auto BaseFrog::restoreSpecialAttackUsedTimes() const -> void {
    frogSpecialAttack_->resetSpecialAttackUses();
}

auto BaseFrog::getFrogMaxPower() const -> int {
    return this->frogMaxPower_;

}

auto BaseFrog::getFrogInfo() const -> std::string {
    return " [" + this->getFrogName() + "](" +
           std::to_string(this->frogCurrentHp_) + "/" + std::to_string(this->frogMaxHealth_) + " HP | " +
           std::to_string(this->frogPower_) + " STR | " +
           std::to_string(this->frogAgility_) + " AGL | " +
           std::to_string(this->frogLevel_) + " LVL | " +
           std::to_string(this->frogExpPoints_) + " EXP) " +
           game_functions::frogTypeToString(this->getFrogType()) + " type\n" +
           "Special attack: " + BaseFrog::getFrogSpecialAttack()->getSpecialAttackName() + " (" +
           std::to_string(this->getFrogSpecialAttack()->getSpecialAttackPower_()) + " STR | " +
           std::to_string(this->getFrogSpecialAttack()->getHowManyTimesSpecialAttackCanBeUsed() -
                          this->getFrogSpecialAttack()->getSpecialAttackUses_()) + " USES LEFT | " + "3 ROUNDS WORK) " +
           game_functions::specialAttackTypeToString(this->getFrogSpecialAttack()->getSpecialAttackType_()) +
           " type\n\n";
}

auto BaseFrog::getFrogExpPoints() const -> int {
    return this->frogExpPoints_;
}

auto BaseFrog::getFrogCurrentHp() const -> int {
    return this->frogCurrentHp_;
}


void BaseFrog::setFrogName(const std::string &frogName) {
    this->frogName_ = frogName;
}

void BaseFrog::setFrogMaxHealth(int frogMaxHealth) {
    this->frogMaxHealth_ = frogMaxHealth;
}

void BaseFrog::setFrogAgility(int frogAgility) {
    this->frogAgility_ = frogAgility;
}

void BaseFrog::setFrogMaxPower(int frogMaxPower) {
    this->frogMaxPower_ = frogMaxPower;
}


int BaseFrog::getFrogPower() const {
    return this->frogPower_;
}

int BaseFrog::getFrogExpToTheNextLvl() const {
    return this->frogExpToTheNextLvl;
}

auto BaseFrog::evolveHealth() -> void {
    this->frogMaxHealth_ += frogMaxHealth_ + 30;
    this->frogCurrentHp_ = frogMaxHealth_;
}

auto BaseFrog::evolvePower() -> void {
    this->frogMaxPower_ += this->frogMaxPower_ + 10;
    this->frogPower_ = this->frogMaxPower_;
}

const std::shared_ptr<BaseSpecialAttack> &BaseFrog::getFrogSpecialAttack() const {
    return this->frogSpecialAttack_;
}

void BaseFrog::setFrogSpecialAttack(const std::shared_ptr<BaseSpecialAttack> &frogSpecialAttack) {
    this->frogSpecialAttack_ = frogSpecialAttack;
}

void BaseFrog::setFrogExpPoints(int frogExpPoints) {
    frogExpPoints_ = frogExpPoints;
}

auto BaseFrog::calculateExpToTheNextLvl() -> void {
    frogExpToTheNextLvl = this->getFrogLevel() * 15;
}

void BaseFrog::setFrogExpGive() {
    frogExpGive_ = frogLevel_ + frogPower_;
}

int BaseFrog::getFrogMaxAgility() const {
    return frogMaxAgility_;
}

void BaseFrog::setFrogMaxAgility(int frogMaxAgility) {
    frogMaxAgility_ = frogMaxAgility;
}