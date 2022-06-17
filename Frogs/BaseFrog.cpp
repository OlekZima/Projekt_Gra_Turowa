#include "BaseFrog.hpp"
#include "Components/damageMultiplier.hpp"
#include "../Functions/Functions.hpp"
#include <utility>
#include <iostream>

BaseFrog::BaseFrog(const std::string &frogName, int frogMaxHealth_, int frogMaxPower_, int frogAgility) :
        frogName_(frogName), frogMaxPower_(frogMaxPower_), frogMaxHealth_(frogMaxHealth_),
        frogAgility_(frogAgility) {};

auto BaseFrog::setCurrentHp(int health) -> void {
    this->frogCurrentHp_ = health;
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


auto BaseFrog::printLvlPromotion() -> void {
    std::cout << "Congratulations! Your frog " << this->frogName_ << "have reached level up! (" << this->frogLevel_
              << "!)\n";
    this->frogLevel_++;
    this->frogExpPoints_ = 0;
}

int BaseFrog::getFrogExpGive() const {
    return frogExpGive_;
}

auto BaseFrog::attackFrog(std::shared_ptr<BaseFrog> enemyFrog) const -> void {
    if (enemyFrog->getFrogAgility() < frogAgility_) {
        auto damageMultiplier = calculateDamageMultiplier(this, enemyFrog);
        enemyFrog->setCurrentHp(enemyFrog->getFrogCurrentHp() - this->getFrogPower() * damageMultiplier);
        if (enemyFrog->checkIfDead()) {
            enemyFrog->declareDeadAndPrintDeadMessage();
            frogAddExp(enemyFrog->getFrogExpGive());
        }
    } else {
        std::cout << "Enemy`s " << enemyFrog->getFrogName() << " is faster than yours!\n";
    }
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

bool BaseFrog::isAlive() const {
    return isAlive_;
}

auto BaseFrog::frogUseSpecialAttack(std::shared_ptr<BaseFrog> frogsToUseSpecialAttack) const -> int {
    if (this->getSpecialAttack()->getSpecialAttackUses_() <
        this->getSpecialAttack()->getHowManyTimesSpecialAttackCanBeUsed()) {
        if (this->getSpecialAttack()->getSpecialAttackType_() == SpecialAttackType::DEFENSIVE) {
            frogsToUseSpecialAttack->setPower(frogsToUseSpecialAttack->getFrogPower() +
                                              this->getSpecialAttack()->getSpecialAttackPower_());

            //------------------ prompt new
            std::cout << "Frog " << this->getFrogName() << " used " << this->getSpecialAttack()->getSpecialAttackName()
                      << " on frog " << frogsToUseSpecialAttack->getFrogName() << " and increased his power by "
                      << this->getSpecialAttack()->getSpecialAttackPower_() << "!\n";
            this->getSpecialAttack()->useSpecialAttack();
            this->getSpecialAttack()->setHowManyRoundsWorking(3);
            return 1;
        } else {
            auto damageMultiplier = calculateDamageMultiplier(this, frogsToUseSpecialAttack);
            frogsToUseSpecialAttack->setPower(frogsToUseSpecialAttack->getFrogPower() -
                                              this->getSpecialAttack()->getSpecialAttackPower_() * damageMultiplier);

            std::cout << "prompt: \n";

            this->getSpecialAttack()->setHowManyRoundsWorking(3);
            this->getSpecialAttack()->useSpecialAttack();

        }
        return 1;
    }
}


auto BaseFrog::calculateExpToTheNextLvl() const -> int {
    return this->getFrogLevel() * 15;
}

int BaseFrog::getFrogMaxHealth() const {
    return frogMaxHealth_;
}

auto BaseFrog::restoreHealth() -> void {
    this->frogCurrentHp_ = this->getFrogMaxHealth();

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
    return " [" + this->getFrogName() + "](" +
           std::to_string(this->getFrogCurrentHp()) + " HP | " +
           std::to_string(this->getFrogPower()) + " STR | " +
           std::to_string(this->getFrogAgility()) + " AGL | " +
           std::to_string(this->getFrogLevel()) + " LVL | " +
           std::to_string(this->getFrogExpPoints()) + " EXP) " +
           game_functions::frogTypeToString(this->getFrogType()) + " type\n" +
           "Special attack: " + this->getSpecialAttack()->getSpecialAttackName() + " (" +
           std::to_string(this->getSpecialAttack()->getSpecialAttackPower_()) + " STR | " +
           std::to_string(this->getSpecialAttack()->getHowManyTimesSpecialAttackCanBeUsed()) + " USES LEFT | " +
           std::to_string(this->getSpecialAttack()->getHowManyRoundsWorking()) + " ROUNDS WORK)\n";
}

auto BaseFrog::getFrogExpPoints() -> int {
    return this->frogExpPoints_;
}

auto BaseFrog::getFrogCurrentHp() -> int {
    return this->frogCurrentHp_;
}


BaseFrog::~BaseFrog() {

}


BaseFrog::BaseFrog() {}

void BaseFrog::setFrogName(const std::string &frogName) {
    frogName_ = frogName;
}

void BaseFrog::setFrogMaxHealth(int frogMaxHealth) {
    frogMaxHealth_ = frogMaxHealth;
}

void BaseFrog::setFrogAgility(int frogAgility) {
    frogAgility_ = frogAgility;
}

void BaseFrog::setFrogMaxPower(int frogMaxPower) {
    frogMaxPower_ = frogMaxPower;
}


int BaseFrog::getFrogPower() const {
    return frogPower_;
}

int BaseFrog::getFrogExpToTheNextLvl() const {
    return frogExpToTheNextLvl;
}

auto BaseFrog::evolveHealth() -> void {
    this->frogMaxHealth_ += this->frogMaxHealth_ + 30;
    this->frogCurrentHp_ = this->frogMaxHealth_;
}

auto BaseFrog::evolvePower() -> void {
    this->frogMaxPower_ += this->frogMaxPower_ + 10;
    this->frogPower_ = this->frogMaxPower_;
}

auto BaseFrog::frogGiveSpecialAttack(std::shared_ptr<BaseSpecialAttack> baseSpecialAttack) -> void {
    this->frogSpecialAttack_ = baseSpecialAttack;
}

std::shared_ptr<BaseSpecialAttack> BaseFrog::getSpecialAttack() const {
    return std::shared_ptr<BaseSpecialAttack>();
}


