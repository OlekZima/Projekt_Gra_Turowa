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
    int frogMaxAgility_;
    int frogMaxPower_;
    int frogPower_;
    int frogExpPoints_;
    int frogExpToTheNextLvl;
    int frogLevel_;
    bool isAlive_;
    int frogExpGive_;
    FrogType frogType_;
    std::shared_ptr<BaseSpecialAttack> frogSpecialAttack_;

public:
    ///CONSTRUCTORS AND DESTRUCTOR
    BaseFrog();
    BaseFrog(const BaseFrog &other);
    BaseFrog(std::string frogName, int frogMaxHealth_, int frogMaxPower_, int frogAgility);
    virtual ~BaseFrog();

//    bool isAlive() const;

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
    int getFrogMaxAgility() const;
    const std::shared_ptr<BaseSpecialAttack> &getFrogSpecialAttack() const;

    ///SETTERS
    void setFrogName(const std::string &frogName);
    void setFrogMaxHealth(int frogMaxHealth);
    void setFrogAgility(int frogAgility);
    void setFrogMaxPower(int frogMaxPower);
    auto setCurrentHp(int health) -> void;
    auto setPower(int power) -> void;
    void setFrogExpPoints(int frogExpPoints);
    void setFrogMaxAgility(int frogMaxAgility);
    void setFrogExpGive();
    void setFrogSpecialAttack(const std::shared_ptr<BaseSpecialAttack> &frogSpecialAttack);
    void setFrogLevel(int frogLevel);

    ///METHODS
    auto evolvePower() -> void;
    auto evolveHealth() -> void;
    auto restoreHealth() -> void;
    auto restoreStats() -> void;
    auto restoreSpecialAttackUsedTimes() const -> void;
    auto printLvlPromotion() -> void;
    auto checkIfDead() -> bool;
    auto declareDeadAndPrintDeadMessage() -> void;
    auto calculateExpToTheNextLvl() -> void;

};