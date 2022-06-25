#include <string>
#include <iostream>
#include <random>
#include "../Frogs/Components/Based/BaseFrog.hpp"
#include "Functions.hpp"
#include "../Frogs/Components/DefensiveSpecialAttack.hpp"
#include "../Frogs/Components/OffensiveSpecialAttack.hpp"

using namespace std;
namespace game_functions {
    /**
     * @brief This function is used to choose the difficulty of the game. Return represents the difficulty.
     * @return int
     */
    auto chooseDifficulty() -> int {
        std::string option;
        while (option != "1" && option != "2" && option != "3") {
            cout << '\n' << "Choose level of difficulty" << '\n';
            cout << "(1) Easy" << '\n';
            cout << "(2) Medium" << '\n';
            cout << "(3) Hard" << '\n';

            cout << "\nInput:";
            cin >> option;
            if (option == "--help" || option == "-h") {
                cout << "Here you can choose difficulty level, that will change your game experience\n" <<
                     "1. Easy -- you will have 4 battles to win\n" <<
                     "2. Medium -- you will have 6 battles to win\n" <<
                     "3. Hard -- you will have 8 battles to win\n" <<
                     "To make a choice input number of level of difficulty\n" <<
                     "or input --help or -h to see this help\n\n";
            } else if (option != "1" && option != "2" && option != "3") {
                cout << "Wrong input!\n";
            }
        }
        int optionNumber = std::stoi(option);
        return optionNumber;
    }

    /**
     * @brief This function is used to get enum FrogType as string
     * @return std::string
     * @param FrogType
     */
    auto frogTypeToString(FrogType type) -> std::string {
        switch (type) {

            case FrogType::WATER:
                return "Water";
            case FrogType::EARTH:
                return "Earth";
            case FrogType::AIR:
                return "Air";
            case FrogType::FIRE:
                return "Fire";
            case FrogType::ICE:
                return "Ice";
            case FrogType::STEEL:
                return "Steel";
        }
        return "none";
    }

    /**
     * @brief This function is used to get enum SpecialAttackType as string
     * @return std::string
     * @param SpecialAttackType
     */
    auto specialAttackTypeToString(SpecialAttackType type) -> std::string {
        switch (type) {
            case SpecialAttackType::DEFENSIVE:
                return "Defensive";
            case SpecialAttackType::OFFENSIVE:
                return "Offensive";
        }
        return "none";
    }

    /**
     * @brief This function is used to generate random name as string
     * @return std::string
     */
    const std::string &generateRandomName() {
        std::random_device rd;
        std::mt19937 gen(rd());

        auto frogNames = std::array<std::string, 21>{
                "Bulba", "Kamien", "Wiatr", "Ognie", "Lod", "Stal", "Fukasaku", "Gama", "Gamabunta", "Gamaden",
                "Gamagorō",
                "Gamahiro", "Gamaken", "Gamakichi", "Gamamaru", "Gamamichi", "Gamariki", "Gamatama", "Gamatatsu",
                "Gekomatsu", "Gerotora"
        };
        std::uniform_int_distribution<> dis(0, frogNames.size() - 1);

        return frogNames[dis(rd)];
    }

/**
 * @brief This function is used to generate random frog
 * @return std::shared_ptr<BaseFrog>
 */
    auto createRandomFrog() -> std::shared_ptr<BaseFrog> {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 6);
        int randomFrog = dis(gen);

        std::shared_ptr<BaseFrog> frog;
        switch (randomFrog) {
            case 1: {
                frog = std::make_shared<WaterFrog>();
                frog->setFrogSpecialAttack(generateRandomSpecialAttack(frog->getFrogType()));
                break;
            }
            case 2: {
                frog = std::make_shared<EarthFrog>();

                frog->setFrogSpecialAttack(generateRandomSpecialAttack(frog->getFrogType()));
                break;
            }
            case 3: {
                frog = std::make_shared<AirFrog>();

                frog->setFrogSpecialAttack(generateRandomSpecialAttack(frog->getFrogType()));
                break;
            }
            case 4: {
                frog = std::make_shared<FireFrog>();

                frog->setFrogSpecialAttack(generateRandomSpecialAttack(frog->getFrogType()));
                break;
            }
            case 5: {
                frog = std::make_shared<IceFrog>();

                frog->setFrogSpecialAttack(generateRandomSpecialAttack(frog->getFrogType()));
                break;
            }
            case 6: {
                frog = std::make_shared<SteelFrog>();

                frog->setFrogSpecialAttack(generateRandomSpecialAttack(frog->getFrogType()));
                break;
            }
        }

        frog->setFrogName(generateRandomName());
        frog->setFrogMaxHealth(std::uniform_int_distribution<>(200, 250)(gen));
        frog->setCurrentHp(frog->getFrogMaxHealth());
        frog->setFrogMaxPower(std::uniform_int_distribution<>(50, 80)(gen));
        frog->setPower(frog->getFrogMaxPower());
        frog->setFrogMaxAgility(std::uniform_int_distribution<>(40, 70)(gen));
        frog->setFrogAgility(frog->getFrogMaxAgility());

        return frog;
    }

    /**
     * @brief This function is used to check, what is the efficiency of the attack
     * @param std::shared_ptr<BaseFrog> attackingFrog
     * @param std::shared_ptr<BaseFrog> attackedFrog
     * @return float
     */

    auto calculateDamageMultiplier(const std::shared_ptr<BaseFrog> &attackingFrog,
                                   const std::shared_ptr<BaseFrog> &attackedFrog) -> float {

        auto attackingFrogType = attackingFrog->getFrogType();
        auto attackedFrogType = attackedFrog->getFrogType();

        if (attackingFrogType == FrogType::EARTH && attackedFrogType == FrogType::AIR
            || attackingFrogType == FrogType::AIR &&
               (attackedFrogType == FrogType::EARTH || attackedFrogType == FrogType::STEEL)
            || attackingFrogType == FrogType::FIRE &&
               (attackedFrogType == FrogType::WATER || attackedFrogType == FrogType::EARTH)
            || attackingFrogType == FrogType::ICE &&
               (attackedFrogType == FrogType::WATER || attackedFrogType == FrogType::FIRE)
            || attackingFrogType == FrogType::STEEL && attackedFrogType == FrogType::FIRE
            || attackingFrogType == FrogType::WATER && attackedFrogType == FrogType::WATER
            || attackingFrogType == FrogType::STEEL && attackedFrogType == FrogType::STEEL
            || attackingFrogType == FrogType::ICE && attackedFrogType == FrogType::ICE) {
            return 0.5;
        } else if (attackingFrogType == FrogType::WATER &&
                   (attackedFrogType == FrogType::EARTH || attackedFrogType == FrogType::FIRE)
                   || attackingFrogType == FrogType::EARTH &&
                      (attackedFrogType == FrogType::FIRE || attackedFrogType == FrogType::ICE ||
                       attackedFrogType == FrogType::STEEL)
                   || attackingFrogType == FrogType::AIR && attackedFrogType == FrogType::ICE
                   || attackingFrogType == FrogType::FIRE &&
                      (attackedFrogType == FrogType::ICE || attackedFrogType == FrogType::STEEL)
                   || attackingFrogType == FrogType::ICE && attackedFrogType == FrogType::EARTH
                   || attackingFrogType == FrogType::STEEL && attackedFrogType == FrogType::AIR ||
                   attackingFrogType == FrogType::STEEL && attackedFrogType == FrogType::WATER) {
            return 2;
        } else {
            return 1;
        }
    }

    /**
     * @brief This function is used to generate random special attack
     * @param frogType
     * @return std::shared_ptr<BaseSpecialAttack>
     */

    auto generateRandomSpecialAttack(const FrogType &frogType) -> std::shared_ptr<BaseSpecialAttack> {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 2);
        int randomSpecialAttack = dis(gen);

        std::shared_ptr<BaseSpecialAttack> specialAttack;

        switch (frogType) {
            case FrogType::WATER: {
                switch (randomSpecialAttack) {
                    case 1:
                        return std::make_shared<DefensiveSpecialAttack>("Water Fists",
                                                                        std::uniform_int_distribution<>(80,
                                                                                                        120)(gen),
                                                                        std::uniform_int_distribution<>(1, 3)(gen));
                    case 2:
                        return std::make_shared<OffensiveSpecialAttack>("Curse of Water",
                                                                        std::uniform_int_distribution<>(80,
                                                                                                        120)(gen),
                                                                        std::uniform_int_distribution<>(1, 3)(gen));
                }
                break;
            }
            case FrogType::EARTH: {
                switch (randomSpecialAttack) {
                    case 1:
                        return std::make_shared<DefensiveSpecialAttack>("Earth Fists",
                                                                        std::uniform_int_distribution<>(80,
                                                                                                        120)(gen),
                                                                        std::uniform_int_distribution<>(1, 3)(gen));
                    case 2:
                        return std::make_shared<OffensiveSpecialAttack>("Curse of Earth",
                                                                        std::uniform_int_distribution<>(80,
                                                                                                        120)(gen),
                                                                        std::uniform_int_distribution<>(1, 3)(gen));
                }
            }
            case FrogType::AIR: {
                switch (randomSpecialAttack) {
                    case 1:
                        return std::make_shared<DefensiveSpecialAttack>("Air Fists",
                                                                        std::uniform_int_distribution<>(80,
                                                                                                        120)(gen),
                                                                        std::uniform_int_distribution<>(1, 3)(gen));
                    case 2:
                        return std::make_shared<OffensiveSpecialAttack>("Curse of Air",
                                                                        std::uniform_int_distribution<>(80,
                                                                                                        120)(gen),
                                                                        std::uniform_int_distribution<>(1, 3)(gen));
                }
            }

            case FrogType::FIRE: {
                switch (randomSpecialAttack) {
                    case 1:
                        return std::make_shared<DefensiveSpecialAttack>("Fire Fists",
                                                                        std::uniform_int_distribution<>(80,
                                                                                                        120)(gen),
                                                                        std::uniform_int_distribution<>(1, 3)(gen));
                    case 2:
                        return std::make_shared<OffensiveSpecialAttack>("Curse of Fire",
                                                                        std::uniform_int_distribution<>(80,
                                                                                                        120)(gen),
                                                                        std::uniform_int_distribution<>(1, 3)(gen));
                }
            }

            case FrogType::ICE: {
                switch (randomSpecialAttack) {
                    case 1:
                        return std::make_shared<DefensiveSpecialAttack>("Ice Fists",
                                                                        std::uniform_int_distribution<>(80,
                                                                                                        120)(gen),
                                                                        std::uniform_int_distribution<>(1, 3)(gen));
                    case 2:
                        return std::make_shared<OffensiveSpecialAttack>("Curse of Ice",
                                                                        std::uniform_int_distribution<>(80,
                                                                                                        120)(gen),
                                                                        std::uniform_int_distribution<>(1, 3)(gen));
                }
            }

            case FrogType::STEEL: {
                switch (randomSpecialAttack) {
                    case 1:
                        return std::make_shared<DefensiveSpecialAttack>("Steel Fists",
                                                                        std::uniform_int_distribution<>(80,
                                                                                                        120)(gen),
                                                                        std::uniform_int_distribution<>(1, 3)(gen));
                    case 2:
                        return std::make_shared<OffensiveSpecialAttack>("Curse of Steel",
                                                                        std::uniform_int_distribution<>(80,
                                                                                                        120)(gen),
                                                                        std::uniform_int_distribution<>(1, 3)(gen));
                }
            }
        }
        return specialAttack;
    }

    /**
        * @brief This function is used to generate random number
        * @return int
        * @param int, int
        */
    auto generateRandomNumber(int min, int max) -> int {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(min, max);
        return dis(gen);
    }

    /**
     * @brief This function is used to start the battle between two teams
     * @return void
     * @param std::array<std::shared_ptr<BaseFrog>, 6> &frogsUserChose, std::array<std::shared_ptr<BaseFrog>, 4> &frogsEnemy
     */
    auto Battle(std::array<std::shared_ptr<BaseFrog>, 6> &frogsUserChose,
                std::array<std::shared_ptr<BaseFrog>, 4> &frogsEnemy) -> void {
        std::shared_ptr<BaseFrog> usersFrog = frogsUserChose[0];

        std::shared_ptr<BaseFrog> enemyFrog;
        bool flagToEnemy = false;

        while (((frogsUserChose[0])->getFrogCurrentHp() > 0 &&
                (frogsUserChose[1])->getFrogCurrentHp() > 0 &&
                (frogsUserChose[2])->getFrogCurrentHp() > 0 &&
                (frogsUserChose[3])->getFrogCurrentHp() > 0 &&
                (frogsUserChose[4])->getFrogCurrentHp() > 0 &&
                (frogsUserChose[5])->getFrogCurrentHp() > 0) ||
               (frogsEnemy[0]->getFrogCurrentHp() > 0 &&
                frogsEnemy[1]->getFrogCurrentHp() > 0 &&
                frogsEnemy[2]->getFrogCurrentHp() > 0 &&
                frogsEnemy[3]->getFrogCurrentHp() > 0)) {

            for (auto &frog: frogsUserChose) {
                frog->setFrogExpGive();
                frog->calculateExpToTheNextLvl();
            }

            for (auto &frog: frogsEnemy) {
                frog->setFrogExpGive();
                frog->calculateExpToTheNextLvl();
            }
//TODO: fixed health
            if (!flagToEnemy) {
                if (frogsEnemy[0]->getFrogCurrentHp() > 0) {
                    enemyFrog = frogsEnemy[0];
                } else if (frogsEnemy[1]->getFrogCurrentHp() > 0) {
                    enemyFrog = frogsEnemy[1];
                } else if (frogsEnemy[2]->getFrogCurrentHp() > 0) {
                    enemyFrog = frogsEnemy[2];
                } else if (frogsEnemy[3]->getFrogCurrentHp() > 0) {
                    enemyFrog = frogsEnemy[3];
                }
            }

            std::cout << "Your turn!\n";
            std::cout << "Choose your action:\n\n";
            std::string inputForChooseFrog;

            std::cout << "Your Frog:\n";
            std::cout << usersFrog->getFrogInfo();

            std::cout << "Enemy Frog:\n";
            std::cout << enemyFrog->getFrogInfo();

            std::cout << "1. Attack\n";
            std::cout << "2. Special Attack\n";
            std::cout << "3. Change current frog in the fight\n";
            std::cout << "4. Evolve current frog\n";

            while (inputForChooseFrog != "1" && inputForChooseFrog != "2" && inputForChooseFrog != "3" &&
                   inputForChooseFrog != "4") {
                std::cin >> inputForChooseFrog;

                if (inputForChooseFrog == "-h" || inputForChooseFrog == "--help") {
                    std::cout
                            << "Battle moment! You need to choose your action by typing one of the number on the left from action \n"
                            << "To see this message again type `--help` or `-h`\n\n";
                } else if (inputForChooseFrog != "1" && inputForChooseFrog != "2" &&
                           inputForChooseFrog != "3" && inputForChooseFrog != "4") {
                    std::cout << "Wrong input!\n";
                }
            }


            int inputChecked = std::stoi(inputForChooseFrog);

            switch (inputChecked) {
                case 1: {
                    std::cout << "You chose Attack!\n";
                    attackFrog(usersFrog, enemyFrog);
                    //fixed start TODO:
                    if (enemyFrog->getFrogCurrentHp() <= 0) {
                        if (frogsEnemy[0]->getFrogCurrentHp() > 0) {
                            enemyFrog = frogsEnemy[0];
                        } else if (frogsEnemy[1]->getFrogCurrentHp() > 0) {
                            enemyFrog = frogsEnemy[1];
                        } else if (frogsEnemy[2]->getFrogCurrentHp() > 0) {
                            enemyFrog = frogsEnemy[2];
                        } else if (frogsEnemy[3]->getFrogCurrentHp() > 0) {
                            enemyFrog = frogsEnemy[3];
                        }
                        std::cout << "Enemy Frog is dead!\n";
                        std::cout << "Enemy Frog is replaced by " << enemyFrog->getFrogName() << " !\n";
                    }
                    ///---------------------------------------------------
                    break;
                }
                case 2: {
                    std::cout << "You chose Special Attack!\n";
                    switch (usersFrog->getFrogSpecialAttack()->getSpecialAttackType_()) {
                        case SpecialAttackType::DEFENSIVE: {
                            usersFrog->restoreStats();
                            frogUseSpecialAttack(usersFrog, usersFrog);
                            break;
                        }
                        case SpecialAttackType::OFFENSIVE: {
                            enemyFrog->restoreStats();
                            frogUseSpecialAttack(usersFrog, enemyFrog);
                            break;
                        }
                    }
                    std::cout << "3 rounds left for special attack effect to end!\n";
                    break;
                }
                case 4: {
                    usersFrog->calculateExpToTheNextLvl();
                    if (usersFrog->getExpPoints() >= usersFrog->getFrogExpToTheNextLvl()) {
                        std::cout << "Your are trying to evolve!\n";
                        std::string inputForEvolveFrog;
                        std::cout << "1. Upgrade Health\n";
                        std::cout << "2. Upgrade Power\n";
                        std::cout << "3. Upgrade Agility\n";
                        std::cout << "Choose attribute to upgrade:\n";
                        while (inputForEvolveFrog != "1" && inputForEvolveFrog != "2" &&
                               inputForEvolveFrog != "3") {
                            std::cin >> inputForEvolveFrog;
                            if (inputForEvolveFrog == "-h" || inputForEvolveFrog == "--help") {
                                std::cout
                                        << "It is a evolve menu. Now you need to type number that represents a attribute you want to upgrade. This upgrade is permanent and you can't change it, but you can try to evolve again, when your frog will have enough exp points \n"
                                        << "To see this message again type `--help` or `-h`\n\n";
                            } else if (inputForEvolveFrog != "1" && inputForEvolveFrog != "2" &&
                                       inputForEvolveFrog != "3") {
                                std::cout << "Wrong input!\n";
                            }
                        }
                        int inputCheckedForEvolve = std::stoi(inputForEvolveFrog);

                        switch (inputCheckedForEvolve) {
                            case 1: {
                                std::cout << "You chose to upgrade Health!\n";
                                usersFrog->evolveHealth();
                                std::cout << usersFrog->getFrogInfo() << "\n";
                                break;
                            }
                            case 2: {
                                std::cout << "You chose to upgrade Power!\n";
                                usersFrog->evolvePower();
                                std::cout << usersFrog->getFrogInfo() << "\n";
                                break;
                            }
                            case 3: {
                                std::cout << "You chose to upgrade Agility!\n";
                                usersFrog->setFrogAgility(usersFrog->getFrogAgility() + 15);
                                std::cout << usersFrog->getFrogInfo() << "\n";
                                break;
                            }
                        }
                        break;
                    }
                    std::cout << "You don't have enough exp points to upgrade, sad! You are losing your round D:\n\n";
                    break;
                }
                case 3: {
                    std::cout << "You chose to change current frog!\n";
                    std::string inputForChangeFrog;
                    auto flag = false;
                    int inputCheckedForChangeFrog;
                    while (!flag) {
                        std::cout << "Type a number of frog you want to change:\n\n";

                        for (int i = 0; i < 6; ++i) {
                            std::cout << i + 1 << ". " << frogsUserChose[i]->getFrogInfo();
                        }
                        while (inputForChangeFrog != "1" && inputForChangeFrog != "2" &&
                               inputForChangeFrog != "3" && inputForChangeFrog != "4" &&
                               inputForChangeFrog != "5" && inputForChangeFrog != "6") {
                            std::cin >> inputForChangeFrog;
                            if (inputForChangeFrog == "-h" || inputForChangeFrog == "--help") {
                                std::cout
                                        << "You can change your current frog to another if you want or you have to to win! \n"
                                        << "To see this message again type `--help` or `-h`\n\n";
                            } else if (inputForChangeFrog != "1" && inputForChangeFrog != "2" &&
                                       inputForChangeFrog != "3" && inputForChangeFrog != "4" &&
                                       inputForChangeFrog != "5" && inputForChangeFrog != "6") {
                                std::cout << "Wrong input!\n";
                            }
                        }
                        inputCheckedForChangeFrog = std::stoi(inputForChangeFrog);
                        if (frogsUserChose[inputCheckedForChangeFrog - 1]->getFrogCurrentHp() > 0) {
                            usersFrog->restoreStats();
                            usersFrog = frogsUserChose[inputCheckedForChangeFrog - 1];
                            flag = true;
                        } else {
                            std::cout << "You can't choose a frog that is dead!\n" <<
                                      "Take another one!\n";
                        }
                    }
                    break;
                }
            }

            std::cout << "\nEnemy turn!\n\n";

            switch (generateRandomNumber(1, 4)) {
                case 1: {
                    std::cout << "Enemy chose Attack!\n";
                    if (enemyFrog->getFrogCurrentHp() <= 0) {
                        flagToEnemy = false;
                        break;
                    }
                    attackFrog(enemyFrog, usersFrog);
                    break;
                }
                case 2: {
                    std::cout << "Enemy chose Special Attack!\n";
                    switch (enemyFrog->getFrogSpecialAttack()->getSpecialAttackType_()) {
                        case SpecialAttackType::DEFENSIVE: {
                            enemyFrog->restoreStats();
                            frogUseSpecialAttack(enemyFrog, enemyFrog);
                            break;
                        }
                        case SpecialAttackType::OFFENSIVE: {
                            usersFrog->restoreStats();
                            frogUseSpecialAttack(enemyFrog, usersFrog);
                            break;
                        }
                    }
                    std::cout << "3 rounds left for special attack effect to end!\n";
                    break;
                }
                case 3: {
                    std::cout << "Enemy chose to change current frog!\n";
                    switch (generateRandomNumber(1, 4)) {
                        case 1: {
                            enemyFrog->restoreStats();
                            //TODO: BYło TAK ŻE NAJPIERW WYBIERAł, A PóŻNIEJ SPRAWDZAł
                            if (frogsEnemy[0]->getFrogCurrentHp() > 0) {
                                enemyFrog = frogsEnemy[0];
                                std::cout << "Enemy chose to change current frog to Frog: \n"
                                          << enemyFrog->getFrogInfo()
                                          << "\n";
                                flagToEnemy = true;
                            } else {
                                std::cout << "Enemy tried to change frog to dead frog! Bruh! He is losing his move\n\n";
                            }
                            break;
                        }
                        case 2: {
                            enemyFrog->restoreStats();
                            //TODO: BYło TAK ŻE NAJPIERW WYBIERAł, A PóŻNIEJ SPRAWDZAł

                            if (frogsEnemy[1]->getFrogCurrentHp() > 0) {
                                enemyFrog = frogsEnemy[1];
                                std::cout << "Enemy chose to change current frog to Frog: \n"
                                          << enemyFrog->getFrogInfo()
                                          << "\n";
                                flagToEnemy = true;
                            } else {
                                std::cout << "Enemy tried to change frog to dead frog! Bruh! He is losing his move\n\n";
                            }
                            break;
                        }
                        case 3: {
                            enemyFrog->restoreStats();
                            //TODO: BYło TAK ŻE NAJPIERW WYBIERAł, A PóŻNIEJ SPRAWDZAł

                            if (frogsEnemy[2]->getFrogCurrentHp() > 0) {
                                enemyFrog = frogsEnemy[2];
                                std::cout << "Enemy chose to change current frog to Frog: \n"
                                          << enemyFrog->getFrogInfo()
                                          << "\n";
                                flagToEnemy = true;
                            } else {
                                std::cout << "Enemy tried to change frog to dead frog! Bruh! He is losing his move\n\n";
                            }
                            break;
                        }
                        case 4: {
                            enemyFrog->restoreStats();
                            //TODO: BYło TAK ŻE NAJPIERW WYBIERAł, A PóŻNIEJ SPRAWDZAł

                            if (frogsEnemy[3]->getFrogCurrentHp() > 0) {
                                enemyFrog = frogsEnemy[3];
                                std::cout << "Enemy chose to change current frog to Frog: \n"
                                          << enemyFrog->getFrogInfo()
                                          << "\n";
                                flagToEnemy = true;
                            } else {
                                std::cout << "Enemy tried to change frog to dead frog! Bruh! He is losing his move\n\n";
                            }
                            break;
                        }
                    }
                    break;
                }
                case 4: {
                    std::cout << "Enemy chose to evolve!\n";
                    enemyFrog->calculateExpToTheNextLvl();
                    if (enemyFrog->getExpPoints() >= enemyFrog->getFrogExpToTheNextLvl()) {
                        switch (generateRandomNumber(1, 3)) {
                            case 1: {
                                std::cout << "Enemy chose to upgrade Health!\n";
                                enemyFrog->evolveHealth();
                                break;
                            }
                            case 2: {
                                std::cout << "Enemy chose to upgrade Power!\n";
                                enemyFrog->evolvePower();
                                break;
                            }
                            case 3: {
                                std::cout << "Enemy chose to upgrade Agility!\n";
                                enemyFrog->setFrogAgility(enemyFrog->getFrogAgility() + 5);
                                break;
                            }
                        }
                        std::cout << enemyFrog->getFrogInfo() << "\n";
                    } else {
                        std::cout << "Enemy don't have enough exp points to evolve he is losing round!\n";
                    }
                }
            }

            if (frogsUserChose[0]->getFrogCurrentHp() <= 0 && frogsUserChose[1]->getFrogCurrentHp() <= 0 &&
                frogsUserChose[2]->getFrogCurrentHp() <= 0 &&
                frogsUserChose[3]->getFrogCurrentHp() <= 0 && frogsUserChose[4]->getFrogCurrentHp() <= 0 &&
                frogsUserChose[5]->getFrogCurrentHp() <= 0) {
                std::cout << "Enemy killed whole your team!\n" <<
                          "Game Over!\n";
                break;
            }
            //fixed start TODO:
            if (frogsEnemy[0]->getFrogCurrentHp() <= 0 && frogsEnemy[1]->getFrogCurrentHp() <= 0 &&
                frogsEnemy[2]->getFrogCurrentHp() <= 0 &&
                frogsEnemy[3]->getFrogCurrentHp() <= 0) {
                std::cout << "You killed whole enemy team!\n" <<
                          "Next Battle is coming!\n";
                break;
            }
            ///---------------------------------------------------
            std::cout << "End of the round!\n";
            if (usersFrog->getFrogSpecialAttack()->getHowManyRoundsWorking() > 0) {
                if (usersFrog->getFrogSpecialAttack()->getHowManyRoundsWorking() == 1) {
                    switch (usersFrog->getFrogSpecialAttack()->getSpecialAttackType_()) {
                        case SpecialAttackType::DEFENSIVE: {
                            std::cout << "Frog no longer have attack bonus\n";
                            usersFrog->restoreStats();
                            usersFrog->getFrogSpecialAttack()->setHowManyRoundsWorking(0);
                            break;
                        }
                        case SpecialAttackType::OFFENSIVE: {
                            std::cout << "Frog no longer have attack debuff\n";
                            enemyFrog->restoreStats();
                            usersFrog->getFrogSpecialAttack()->setHowManyRoundsWorking(0);
                            break;
                        }
                    }
                }
                usersFrog->getFrogSpecialAttack()->setHowManyRoundsWorking(
                        usersFrog->getFrogSpecialAttack()->getHowManyRoundsWorking());
                std::cout << usersFrog->getFrogName() << " have "
                          << usersFrog->getFrogSpecialAttack()->getHowManyRoundsWorking()
                          << " rounds left to the end of effect of special attack\n";
            }
            if (enemyFrog->getFrogSpecialAttack()->getHowManyRoundsWorking() > 0) {
                if (enemyFrog->getFrogSpecialAttack()->getHowManyRoundsWorking() == 1) {
                    switch (enemyFrog->getFrogSpecialAttack()->getSpecialAttackType_()) {
                        case SpecialAttackType::DEFENSIVE: {
                            std::cout << "Frog no longer have attack bonus\n";
                            enemyFrog->restoreStats();
                            enemyFrog->getFrogSpecialAttack()->setHowManyRoundsWorking(0);
                            break;
                        }
                        case SpecialAttackType::OFFENSIVE: {
                            std::cout << "Frog no longer have attack debuff\n";
                            usersFrog->restoreStats();
                            enemyFrog->getFrogSpecialAttack()->setHowManyRoundsWorking(0);
                            break;
                        }
                    }
                }
                enemyFrog->getFrogSpecialAttack()->setHowManyRoundsWorking(
                        enemyFrog->getFrogSpecialAttack()->getHowManyRoundsWorking());
                std::cout << enemyFrog->getFrogName() << " have "
                          << enemyFrog->getFrogSpecialAttack()->getHowManyRoundsWorking()
                          << " rounds left to the end of effect of special attack\n";
            }
        }
    }

/**
 * @brief This function is used to reduce the HP of the frog
 * @param attackingFrog
 * @param attackedFrog
 * @return void
 */

//TODO: ADDED REFERENCES
    auto attackFrog(std::shared_ptr<BaseFrog> &attackingFrog, std::shared_ptr<BaseFrog> &attackedFrog) -> void {
        if (attackedFrog->getFrogAgility() <= attackingFrog->getFrogAgility()) {
            if (attackingFrog->getFrogPower() > 0) {
                auto damageMultiplier = calculateDamageMultiplier(attackingFrog, attackedFrog);
                attackedFrog->setCurrentHp(
                        attackedFrog->getFrogCurrentHp() - attackingFrog->getFrogPower() * damageMultiplier);

                std::cout << attackingFrog->getFrogName() << " attacked " << attackedFrog->getFrogName() << " with "
                          << (int) (attackingFrog->getFrogPower() * damageMultiplier) << " damage.\n";

                std::cout << attackedFrog->getFrogInfo();

                if (attackedFrog->checkIfDead()) {
                    attackingFrog->restoreStats();
                    attackingFrog->setFrogExpPoints(attackedFrog->getFrogExpGive());
                }
            } else {
                std::cout << attackingFrog->getFrogName() << " tried to attack " << attackedFrog->getFrogName()
                          << " but he is not strong enough!\n\n";
            }
        } else {
            std::cout << attackingFrog->getFrogName() << " tried to attack " << attackedFrog->getFrogName()
                      << " but he is too fast!\n\n";
        }
    }

    /**
 * @brief This function is used to reduce the Agility and Power of the frog
 * @param frogToUseSpecialAttack
 * @param frogToUseOnSA
 * @return int
 */

    auto frogUseSpecialAttack(std::shared_ptr<BaseFrog> &frogToUseSpecialAttack,
                              std::shared_ptr<BaseFrog> &frogToUseOnSA) -> int {
        if (frogToUseSpecialAttack->getFrogSpecialAttack()->getSpecialAttackUses_() <
            frogToUseSpecialAttack->getFrogSpecialAttack()->getHowManyTimesSpecialAttackCanBeUsed()) {

            if (frogToUseSpecialAttack->getFrogSpecialAttack()->getSpecialAttackType_() ==
                SpecialAttackType::DEFENSIVE) {

                frogToUseOnSA->setPower(
                        frogToUseOnSA->getFrogPower() +
                        frogToUseSpecialAttack->getFrogSpecialAttack()->getSpecialAttackPower_());

                frogToUseOnSA->setFrogAgility(
                        frogToUseOnSA->getFrogAgility() +
                        frogToUseSpecialAttack->getFrogSpecialAttack()->getSpecialAttackPower_());

                std::cout << "Frog " << frogToUseSpecialAttack->getFrogName() << " used "
                          << frogToUseSpecialAttack->getFrogSpecialAttack()->getSpecialAttackName()
                          << " on frog " << frogToUseOnSA->getFrogName() << " and increased his power by "
                          << frogToUseSpecialAttack->getFrogSpecialAttack()->getSpecialAttackPower_() << "!\n";
                frogToUseSpecialAttack->getFrogSpecialAttack()->useSpecialAttack();

                frogToUseSpecialAttack->getFrogSpecialAttack()->setHowManyRoundsWorking(3);

                return 1;
            } else {

                frogToUseOnSA->setPower(frogToUseOnSA->getFrogPower() -
                                        (frogToUseSpecialAttack->getFrogSpecialAttack()->getSpecialAttackPower_()));

                frogToUseOnSA->setFrogAgility(frogToUseOnSA->getFrogAgility() -
                                              frogToUseSpecialAttack->getFrogSpecialAttack()->getSpecialAttackPower_());

                std::cout << "Frog " << frogToUseSpecialAttack->getFrogName() << " reduced "
                          << frogToUseOnSA->getFrogName()
                          << "'s power by "
                          << frogToUseSpecialAttack->getFrogSpecialAttack()->getSpecialAttackPower_()
                          << "!\n";

                frogToUseSpecialAttack->getFrogSpecialAttack()->useSpecialAttack();
                frogToUseSpecialAttack->getFrogSpecialAttack()->setHowManyRoundsWorking(3);


            }
            return 1;
        }
        std::cout << "Something went wrong!\n";
        return 0;
    }
}