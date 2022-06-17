#include "BaseFrog.hpp"
#include "../../../Functions/Functions.hpp"
#include <iostream>
#include <utility>

BaseFrog::BaseFrog(std::string frogName, int frogMaxHealth_, int frogMaxPower_, int frogAgility) :
        frogName_(std::move(frogName)), frogMaxPower_(frogMaxPower_), frogMaxHealth_(frogMaxHealth_),
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

auto BaseFrog::attackFrog(std::shared_ptr<BaseFrog> &enemyFrog) const -> void {
    if (enemyFrog->getFrogAgility() < frogAgility_) {
        auto damageMultiplier = game_functions::calculateDamageMultiplier(this, enemyFrog);
        enemyFrog->setCurrentHp(enemyFrog->getFrogCurrentHp() - frogPower_ * damageMultiplier);
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

auto BaseFrog::frogUseSpecialAttack(std::shared_ptr<BaseFrog> &frogsToUseSpecialAttack) const -> int {
    if (this->frogSpecialAttack_->getSpecialAttackUses_() <
        this->frogSpecialAttack_->getHowManyTimesSpecialAttackCanBeUsed()) {
        if (this->frogSpecialAttack_->getSpecialAttackType_() == SpecialAttackType::DEFENSIVE) {
            frogsToUseSpecialAttack->setPower(frogsToUseSpecialAttack->getFrogPower() +
                                              this->frogSpecialAttack_->getSpecialAttackPower_());

            //------------------ prompt new
            std::cout << "Frog " << this->getFrogName() << " used " << this->frogSpecialAttack_->getSpecialAttackName()
                      << " on frog " << frogsToUseSpecialAttack->getFrogName() << " and increased his power by "
                      << this->frogSpecialAttack_->getSpecialAttackPower_() << "!\n";
            this->frogSpecialAttack_->useSpecialAttack();
            return 1;
        } else {
            auto damageMultiplier = game_functions::calculateDamageMultiplier(this, frogsToUseSpecialAttack);
            frogsToUseSpecialAttack->setPower(frogsToUseSpecialAttack->getFrogPower() -
                                              this->frogSpecialAttack_->getSpecialAttackPower_() * damageMultiplier);

            std::cout << "prompt: \n";

            this->frogSpecialAttack_->useSpecialAttack();

        }
        return 1;
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
    this->frogCurrentHp_ = this->getFrogMaxHealth();

}

auto BaseFrog::restoreStats() -> void {
    this->frogPower_ = this->getFrogMaxPower();

}

auto BaseFrog::restoreSpecialAttackUsedTimes() const -> void {
    frogSpecialAttack_->resetSpecialAttackUses();
}

auto BaseFrog::getFrogMaxPower() const -> int {
    return this->frogMaxPower_;

}

auto BaseFrog::frogCheckIfOffensiveSpecialAttackIsStillWorkingOn() -> bool {
    int counter = 0;
    if (counter > frogSpecialAttack_->getHowManyRoundsWorking()) {
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
    if (counter > frogSpecialAttack_->getHowManyRoundsWorking()) {
        this->restoreHealth();
        counter = 0;
        return false;
    } else {
        counter++;
        return true;
    }
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
           std::to_string(this->getFrogSpecialAttack()->getHowManyTimesSpecialAttackCanBeUsed()) + " USES LEFT | " +
           std::to_string(this->getFrogSpecialAttack()->getHowManyRoundsWorking()) + " ROUNDS WORK)\n";
}

auto BaseFrog::getFrogExpPoints() const -> int {
    return this->frogExpPoints_;
}

auto BaseFrog::getFrogCurrentHp() const -> int {
    return this->frogCurrentHp_;
}


BaseFrog::~BaseFrog() = default;


BaseFrog::BaseFrog() = default;

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