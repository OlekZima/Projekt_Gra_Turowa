#include "BaseFrog.hpp"
#include "Components/damageMultiplier.hpp"
#include <utility>
#include <iostream>

BaseFrog::BaseFrog(const std::string &frogName, int frogMaxHealth_, int frogMaxPower_, int frogAgility) :
        frogName_(frogName), frogMaxPower_(frogMaxPower_), frogMaxHealth_(frogMaxHealth_),
        frogAgility_(frogAgility) {};

auto BaseFrog::setHealth(int health) -> void {
    this->frogHealth_ = health;
}

auto BaseFrog::getHealth() const -> int {
    return this->frogHealth_;
}

auto BaseFrog::getPower() const -> int {
    return this->frogPower_;
}

auto BaseFrog::frogAddExp(int expPoints) const -> void {
    this->frogExpPoints_ + expPoints;
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

BaseSpecialAttack *BaseFrog::getSpecialAttack() const {
    return frogSpecialAttack_;
}

auto BaseFrog::printLvlPromotion() -> void {
    std::cout << "Congratulations! Your frog " << this->frogName_ << "have reached level up! (" << this->frogLevel_
              << "!)\n";
    this->frogLevel_++;
    this->frogExpPoints_ = 0;
}

int BaseFrog::getFrogExpGive() const {
    return frogExpGive_;
}

auto BaseFrog::attackFrog(BaseFrog *enemyFrog) const -> void {
    if (enemyFrog->getFrogAgility() < frogAgility_) {
        auto damageMultiplier = calculateDamageMultiplier(this, enemyFrog);
        enemyFrog->setHealth(enemyFrog->getHealth() - frogPower_ * damageMultiplier);
        if (enemyFrog->checkIfDead()) {
            enemyFrog->declareDeadAndPrintDeadMessage();
            frogAddExp(enemyFrog->getFrogExpGive());
        }
    } else {
        std::cout << "Enemy`s " << enemyFrog->getFrogName() << " is faster than yours!\n";
    }
}

auto BaseFrog::checkIfDead() -> bool {
    if (this->frogHealth_ <= 0) {
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

bool BaseFrog::isAlive() const {
    return isAlive_;
}

auto BaseFrog::frogUseSpecialAttack(BaseFrog *frogsToUseSpecialAttack) const -> int {
    if (this->getSpecialAttack()->getSpecialAttackUses_() <
        this->getSpecialAttack()->getHowManyTimesSpecialAttackCanBeUsed()) {
        if (this->getSpecialAttack()->getSpecialAttackType_() == SpecialAttackType::DEFENSIVE) {
            frogsToUseSpecialAttack->setPower(frogsToUseSpecialAttack->getPower() +
                                              this->getSpecialAttack()->getSpecialAttackPower_());
            std::cout << "Frog " << this->getFrogName() << " used " << this->getSpecialAttack()->getSpecialAttackName()
                      << " on frog " << frogsToUseSpecialAttack->getFrogName() << " and increased his power by "
                      << this->getSpecialAttack()->getSpecialAttackPower_() << "!\n";
            this->getSpecialAttack()->useSpecialAttack();
            return 1;
        } else {
            auto damageMultiplier = calculateDamageMultiplier(this, frogsToUseSpecialAttack);
            this->getSpecialAttack()->useSpecialAttack();
            if (frogsToUseSpecialAttack->getFrogAgility() <
                this->getSpecialAttack()->getSpecialAttackAgilityToAvoid()) {
                frogsToUseSpecialAttack->setPower(frogsToUseSpecialAttack->getPower() -
                                                  this->getSpecialAttack()->getSpecialAttackPower_());
            } else {
                std::cout << "Enemy`s " << frogsToUseSpecialAttack->getFrogName() << " is faster than yours!\n";
            }
            return 1;
        }
    }
    return 0;
}

auto BaseFrog::calculateExpToTheNextLvl() const -> int {
    return this->getFrogLevel() * 15;
}

int BaseFrog::getFrogMaxHealth() const {
    return frogMaxHealth_;
}

auto BaseFrog::restoreHealth() -> void {
    this->frogHealth_ = this->getFrogMaxHealth();

}

auto BaseFrog::restoreStats() -> void {
    this->frogPower_ = this->getFrogMaxPower();

}

auto BaseFrog::restoreSpecialAttackUsedTimes() const -> void {
    this->getSpecialAttack()->resetSpecialAttackUses();
}

auto BaseFrog::getFrogMaxPower() const -> int {
    return this->frogMaxPower_;

}

auto BaseFrog::frogCheckIfOffensiveSpecialAttackIsStillWorkingOn() -> bool {
    int counter = 0;
    if (counter > this->getSpecialAttack()->getHowManyRoundsWorking()) {
        this->restoreStats();
        counter = 0;
        return false;
    } else {
        counter++;
        return true;
    }
}

auto BaseFrog::frogCheckIfDefensiveSpecialAttackIsStillWorkingOn() -> bool {
    int counter = 0;
    if (counter > this->getSpecialAttack()->getHowManyRoundsWorking()) {
        this->restoreHealth();
        counter = 0;
        return false;
    } else {
        counter++;
        return true;
    }
}

auto BaseFrog::getFrogInfo() -> std::string {
    return " [" + frogName_ + "](" +
           std::to_string(frogHealth_) + " HP | " +
           std::to_string(frogPower_) + " STR | " +
           std::to_string(frogAgility_) + " AGL | " +
           std::to_string(frogLevel_) + " LVL | " +
           std::to_string(frogExpPoints_) + " EXP)";
}

auto BaseFrog::getFrogExpPoints() -> int {
    return this->frogExpPoints_;
}

auto BaseFrog::getFrogCurrentHp() -> int {
    return this->frogHealth_;
}

auto BaseFrog::FrogSetAgility(int agilityToSet) -> void {
    this->frogAgility_ = agilityToSet;
}

int BaseFrog::FrogGetAgility() {
    return this->frogAgility_;
}

BaseFrog::~BaseFrog() {

}

BaseFrog::BaseFrog(const std::string &frogName, int frogMaxHealth_, int frogMaxPower_, int frogAgility,
                   BaseSpecialAttack *frogSpecialAttack) {
    this->frogName_ = frogName;
    this->frogMaxHealth_ = frogMaxHealth_;
    this->frogMaxPower_ = frogMaxPower_;
    this->frogAgility_ = frogAgility;
    this->frogSpecialAttack_ = frogSpecialAttack;
}

BaseFrog::BaseFrog() {}


