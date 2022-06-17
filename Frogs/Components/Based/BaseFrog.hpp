#pragma once

#include <string>
#include <memory>
#include "../Enums/FrogType.hpp"
#include "BaseSpecialAttack.hpp"

class BaseSpecialAttack;

class BaseFrog {
protected:
    std::string frogName_;
    int frogMaxHealth_;
    int frogCurrentHp_;
    int frogAgility_;
    int frogMaxPower_;
    int frogPower_;
    int frogExpPoints_ = 0;
    int frogExpToTheNextLvl = calculateExpToTheNextLvl();
    int frogLevel_ = 1;
    bool isAlive_ = true;
    int frogExpGive_ = frogLevel_ * frogPower_ * 10;
    FrogType frogType_;
    std::shared_ptr<BaseSpecialAttack> frogSpecialAttack_;

public:
    ///CONSTRUCTORS AND DESTRUCTOR

    BaseFrog();

    BaseFrog(std::string frogName, int frogMaxHealth_, int frogMaxPower_, int frogAgility);

    virtual ~BaseFrog();

    ///GETTERS

    int getFrogMaxHealth() const;

    auto getFrogCurrentHp() const -> int;

    int getFrogMaxPower() const;

    int getFrogPower() const;

    int getFrogAgility() const;

    int getFrogLevel() const;

    auto getFrogExpPoints() const -> int;

    int getFrogExpToTheNextLvl() const;

    const std::string &getFrogName() const;

    int getFrogExpGive() const;

    auto getExpPoints() const -> int;


    auto getFrogInfo() const -> std::string;

    virtual auto getFrogType() const -> FrogType = 0;

    ///SETTERS



    void setFrogName(const std::string &frogName);

    void setFrogMaxHealth(int frogMaxHealth);

    void setFrogAgility(int frogAgility);

    void setFrogMaxPower(int frogMaxPower);

    auto setCurrentHp(int health) -> void;

    auto setPower(int power) -> void;


    ///METHODS

    auto evolvePower() -> void;

    auto evolveHealth() -> void;

    auto restoreHealth() -> void;

    auto restoreStats() -> void;

    auto restoreSpecialAttackUsedTimes() const -> void;

    auto printLvlPromotion() -> void;

    auto checkIfDead() -> bool;

    auto isAlive() const -> bool;

    auto declareDeadAndPrintDeadMessage() -> void;

    auto attackFrog(std::shared_ptr<BaseFrog> &enemyFrog) const -> void;

    auto calculateExpToTheNextLvl() const -> int;

    auto frogAddExp(int expPoints) const -> void;

    auto frogUseSpecialAttack(std::shared_ptr<BaseFrog> &frogsToUseSpecialAttack) const -> int;

    auto frogCheckIfOffensiveSpecialAttackIsStillWorkingOn() -> bool;

    auto frogCheckIfDefensiveSpecialAttackIsStillWorkingOn() -> bool;

    const std::shared_ptr<BaseSpecialAttack> &getFrogSpecialAttack() const;

    void setFrogSpecialAttack(const std::shared_ptr<BaseSpecialAttack> &frogSpecialAttack);
};