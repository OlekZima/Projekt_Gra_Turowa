#pragma once

#include <string>
#include <memory>
#include "Components/Enums/FrogType.hpp"
#include "Components/BaseSpecialAttack.hpp"

class BaseSpecialAttack;

class BaseFrog {
protected:
    std::string frogName_;
    int frogPower_ = frogMaxPower_;
    int frogHealth_ = frogMaxHealth_;
    int frogMaxHealth_;
    int frogAgility_;
    int frogMaxPower_;
    int frogExpPoints_ = 0;
    int frogExpToTheNextLvl = calculateExpToTheNextLvl();
    int frogLevel_ = 1;
    bool isAlive_ = true;
    int frogExpGive_ = frogLevel_ * frogPower_ * 10;
    FrogType frogType_;
    BaseSpecialAttack *frogSpecialAttack_;

    //return min + rand() % (max+1 - min);

public:
    auto restoreHealth() -> void;

    auto restoreStats() -> void;

    auto restoreSpecialAttackUsedTimes() const -> void;

    auto printLvlPromotion() -> void;

    auto checkIfDead() -> bool;

    auto isAlive() const -> bool;

    int getFrogMaxHealth() const;

    auto declareDeadAndPrintDeadMessage() -> void;

    auto attackFrog(BaseFrog *enemyFrog) const -> void;

    BaseFrog(const std::string &frogName, int frogMaxHealth_, int frogMaxPower_, int frogAgility);

    BaseFrog(const std::string &frogName, int frogMaxHealth_, int frogMaxPower_, int frogAgility,
             BaseSpecialAttack *frogSpecialAttack);

    BaseFrog();

    auto frogGiveSpecialAttack(BaseSpecialAttack *baseSpecialAttack) -> void;

    auto setHealth(int health) -> void;

    auto getHealth() const -> int;

    virtual auto getFrogType() const -> FrogType = 0;

    auto getPower() const -> int;

    const std::string &getFrogName() const;

    int getFrogExpGive() const;

    int getFrogAgility() const;

    auto calculateExpToTheNextLvl() const -> int;

    int getFrogLevel() const;

    BaseSpecialAttack *getSpecialAttack() const;

    auto setPower(int power) -> void;

    auto frogCheckIfOffensiveSpecialAttackIsStillWorkingOn() -> bool;

    auto frogCheckIfDefensiveSpecialAttackIsStillWorkingOn() -> bool;

    auto getExpPoints() const -> int;

    auto frogAddExp(int expPoints) const -> void;

    auto frogUseSpecialAttack(BaseFrog *frogsToUseSpecialAttack) const -> int;

    int getFrogMaxPower() const;

    auto getFrogCurrentHp() -> int;

    auto getFrogExpPoints() -> int;

    auto FrogSetAgility(int agilityToSet) -> void;

    auto getFrogInfo() -> std::string;

    int FrogGetAgility();

    virtual ~BaseFrog();
};