#include <string>
#include <iostream>
#include <random>
#include "../Frogs/Components/Based/BaseFrog.hpp"
#include "Functions.hpp"
#include "../Frogs/FrogsWithType.hpp"
#include "../Frogs/Components/DefensiveSpecialAttack.hpp"
#include "../Frogs/Components/OffensiveSpecialAttack.hpp"


using namespace std;

namespace game_functions {
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

    auto specialAttackTypeToString(SpecialAttackType type) -> std::string {
        switch (type) {
            case SpecialAttackType::DEFENSIVE:
                return "Defensive";
            case SpecialAttackType::OFFENSIVE:
                return "Offensive";
        }
        return "none";
    }

    const std::string &generateRandomName() {
        std::random_device rd;
        std::mt19937 gen(rd());

        auto frogNames = std::array<std::string, 22>{
                "Bulba", "Kamien", "Wiatr", "Ognie", "Lod", "Stal", "Fukasaku", "Gama", "Gamabunta", "Gamaden",
                "Gamagorō",
                "Gamahiro", "Gamaken", "Gamakichi", "Gamamaru", "Gamamichi", "Gamariki", "Gamatama", "Gamatatsu",
                "Gekomatsu", "Gerotora"
        };
        std::uniform_int_distribution<> dis(0, frogNames.size() - 1);

        return frogNames[dis(rd)];

    }

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
        frog->setFrogAgility(std::uniform_int_distribution<>(40, 70)(gen));

        return frog;
    }

    auto calculateDamageMultiplier(const BaseFrog *attackingFrog,
                                   std::shared_ptr<BaseFrog> attackedFrog) -> float {

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
            return 1 / 2;
        } else if (attackingFrogType == FrogType::WATER &&
                   (attackedFrogType == FrogType::EARTH || attackedFrogType == FrogType::FIRE)
                   || attackingFrogType == FrogType::EARTH &&
                      (attackedFrogType == FrogType::FIRE || attackedFrogType == FrogType::ICE ||
                       attackedFrogType == FrogType::STEEL)
                   || attackingFrogType == FrogType::AIR && attackedFrogType == FrogType::ICE
                   || attackingFrogType == FrogType::FIRE &&
                      (attackedFrogType == FrogType::ICE || attackedFrogType == FrogType::STEEL)
                   || attackingFrogType == FrogType::ICE && attackedFrogType == FrogType::EARTH
                   || attackingFrogType == FrogType::STEEL && attackedFrogType == FrogType::AIR) {
            return 2;
        } else {
            return 1;
        }
    }

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
                                                                        std::uniform_int_distribution<>(30,
                                                                                                        50)(gen),
                                                                        std::uniform_int_distribution<>(1, 3)(gen));
                    case 2:
                        return std::make_shared<OffensiveSpecialAttack>("Curse of Water",
                                                                        std::uniform_int_distribution<>(80,
                                                                                                        120)(gen),
                                                                        std::uniform_int_distribution<>(30,
                                                                                                        50)(gen),
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
                                                                        std::uniform_int_distribution<>(30,
                                                                                                        50)(gen),
                                                                        std::uniform_int_distribution<>(1, 3)(gen));
                    case 2:
                        return std::make_shared<OffensiveSpecialAttack>("Curse of Eath",
                                                                        std::uniform_int_distribution<>(80,
                                                                                                        120)(gen),
                                                                        std::uniform_int_distribution<>(30,
                                                                                                        50)(gen),
                                                                        std::uniform_int_distribution<>(1, 3)(gen));
                }
            }
            case FrogType::AIR: {
                switch (randomSpecialAttack) {
                    case 1:
                        return std::make_shared<DefensiveSpecialAttack>("Earth Fists",
                                                                        std::uniform_int_distribution<>(80,
                                                                                                        120)(gen),
                                                                        std::uniform_int_distribution<>(30,
                                                                                                        50)(gen),
                                                                        std::uniform_int_distribution<>(1, 3)(gen));
                    case 2:
                        return std::make_shared<OffensiveSpecialAttack>("Curse of Eath",
                                                                        std::uniform_int_distribution<>(80,
                                                                                                        120)(gen),
                                                                        std::uniform_int_distribution<>(30,
                                                                                                        50)(gen),
                                                                        std::uniform_int_distribution<>(1, 3)(gen));
                }
            }

            case FrogType::FIRE: {
                switch (randomSpecialAttack) {
                    case 1:
                        return std::make_shared<DefensiveSpecialAttack>("Earth Fists",
                                                                        std::uniform_int_distribution<>(80,
                                                                                                        120)(gen),
                                                                        std::uniform_int_distribution<>(30,
                                                                                                        50)(gen),
                                                                        std::uniform_int_distribution<>(1, 3)(gen));
                    case 2:
                        return std::make_shared<OffensiveSpecialAttack>("Curse of Eath",
                                                                        std::uniform_int_distribution<>(80,
                                                                                                        120)(gen),
                                                                        std::uniform_int_distribution<>(30,
                                                                                                        50)(gen),
                                                                        std::uniform_int_distribution<>(1, 3)(gen));
                }
            }

            case FrogType::ICE: {
                switch (randomSpecialAttack) {
                    case 1:
                        return std::make_shared<DefensiveSpecialAttack>("Earth Fists",
                                                                        std::uniform_int_distribution<>(80,
                                                                                                        120)(gen),
                                                                        std::uniform_int_distribution<>(30,
                                                                                                        50)(gen),
                                                                        std::uniform_int_distribution<>(1, 3)(gen));
                    case 2:
                        return std::make_shared<OffensiveSpecialAttack>("Curse of Eath",
                                                                        std::uniform_int_distribution<>(80,
                                                                                                        120)(gen),
                                                                        std::uniform_int_distribution<>(30,
                                                                                                        50)(gen),
                                                                        std::uniform_int_distribution<>(1, 3)(gen));
                }
            }

            case FrogType::STEEL: {
                switch (randomSpecialAttack) {
                    case 1:
                        return std::make_shared<DefensiveSpecialAttack>("Earth Fists",
                                                                        std::uniform_int_distribution<>(80,
                                                                                                        120)(gen),
                                                                        std::uniform_int_distribution<>(30,
                                                                                                        50)(gen),
                                                                        std::uniform_int_distribution<>(1, 3)(gen));
                    case 2:
                        return std::make_shared<OffensiveSpecialAttack>("Curse of Eath",
                                                                        std::uniform_int_distribution<>(80,
                                                                                                        120)(gen),
                                                                        std::uniform_int_distribution<>(30,
                                                                                                        50)(gen),
                                                                        std::uniform_int_distribution<>(1, 3)(gen));
                }
            }

        }
    }


    auto Battle(std::array<std::shared_ptr<BaseFrog>, 6> &frogsUserChose,
                std::array<std::shared_ptr<BaseFrog>, 4> &frogsEnemy) -> void {
        std::shared_ptr<BaseFrog> chosenUserFrog = frogsUserChose[0];

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

            std::cout << "Your turn!\n";
            std::cout << "Choose your action:\n";
            std::string inputForChooseFrog;

            std::cout << "1. Attack\n";
            std::cout << "2. Special Attack\n";
            std::cout << "3. Change current frog in the fight\n";
            std::cout << "4. Evolve current frog\n";

            while (inputForChooseFrog != "1" && inputForChooseFrog != "2" && inputForChooseFrog != "3" &&
                   inputForChooseFrog != "4") {
                std::cin >> inputForChooseFrog;

                if (inputForChooseFrog == "-h" || inputForChooseFrog == "--help") {
                    std::cout << "Manual: \n";
                } else if (inputForChooseFrog != "1" && inputForChooseFrog != "2" &&
                           inputForChooseFrog != "3" && inputForChooseFrog != "4") {
                    std::cout << "Wrong input!\n";
                }
            }


            int inputChecked = std::stoi(inputForChooseFrog);

            std::shared_ptr<BaseFrog> enemyFrog;

            if (frogsEnemy[0]->getFrogCurrentHp() > 0) {
                enemyFrog = frogsEnemy[0];
            } else if (frogsEnemy[1]->getFrogCurrentHp() > 0) {
                enemyFrog = frogsEnemy[1];
            } else if (frogsEnemy[2]->getFrogCurrentHp() > 0) {
                enemyFrog = frogsEnemy[2];
            } else {
                enemyFrog = frogsEnemy[3];
            }

            switch (inputChecked) {
                case 1: {
                    std::cout << "You chose Attack!\n";
                    chosenUserFrog->attackFrog(enemyFrog);
                    std::cout << "prompt\n";
                    break;
                }
                case 2: {
                    std::cout << "You chose Special Attack!\n";
                    switch (chosenUserFrog->getFrogSpecialAttack()->getSpecialAttackType_()) {
                        case SpecialAttackType::DEFENSIVE: {
                            std::cout << "You chose Defensive Attack!\n";
                            chosenUserFrog->frogUseSpecialAttack(chosenUserFrog);
                            break;
                        }
                        case SpecialAttackType::OFFENSIVE: {
                            std::cout << "You chose Offensive Attack!\n";
                            chosenUserFrog->frogUseSpecialAttack(enemyFrog);
                            break;
                        }
                    }
                    break;
                }
                case 3: {
                    if (chosenUserFrog->getExpPoints() >= chosenUserFrog->getFrogExpToTheNextLvl()) {
                        std::cout << "prompt \n";
                        std::string inputForEvolveFrog;
                        ///TODO: attributes
                        std::cout << "Choose attribute to upgrade:\n";
                        while (inputForEvolveFrog != "1" && inputForEvolveFrog != "2" &&
                               inputForEvolveFrog != "3") {
                            std::cin >> inputForEvolveFrog;
                            if (inputForEvolveFrog == "-h" || inputForEvolveFrog == "--help") {
                                std::cout << "Manual: \n";
                            } else if (inputForEvolveFrog != "1" && inputForEvolveFrog != "2" &&
                                       inputForEvolveFrog != "3") {
                                std::cout << "Wrong input!\n";
                            }
                        }
                        int inputCheckedForEvolve = std::stoi(inputForEvolveFrog);

                        switch (inputCheckedForEvolve) {
                            case 1: {
                                std::cout << "You chose to upgrade Health!\n";
                                chosenUserFrog->evolveHealth();
                                break;
                            }
                            case 2: {
                                std::cout << "You chose to upgrade Power!\n";
                                chosenUserFrog->evolvePower();
                                break;
                            }
                            case 3: {
                                std::cout << "You chose to upgrade Agility!\n";
                                chosenUserFrog->setFrogAgility(chosenUserFrog->getFrogAgility() + 15);
                                break;
                            }
                        }
                        break;
                    }
                    ///TODO: prompt
                    std::cout << "prompt \n";

                    break;
                }
                case 4: {
                    std::cout << "You chose to change current frog!\n";
                    std::string inputForChangeFrog;
                    auto flag = false;
                    int inputCheckedForChangeFrog;
                    while (!flag) {
                        std::cout << "prompt\n";

                        std::cin >> inputForChangeFrog;

                        while (inputForChangeFrog != "1" && inputForChangeFrog != "2" &&
                               inputForChangeFrog != "3" && inputForChangeFrog != "4" &&
                               inputForChangeFrog != "5" && inputForChangeFrog != "6") {
                            if (inputForChangeFrog == "-h" || inputForChangeFrog == "--help") {
                                std::cout << "Manual: \n";
                            } else if (inputForChangeFrog != "1" || inputForChangeFrog != "2" ||
                                       inputForChangeFrog != "3" || inputForChangeFrog != "4" ||
                                       inputForChangeFrog != "5" || inputForChangeFrog != "6") {
                                std::cout << "Wrong input!\n";
                            }
                        }
                        inputCheckedForChangeFrog = std::stoi(inputForChangeFrog);
                        if (frogsUserChose[inputCheckedForChangeFrog - 1]->getFrogCurrentHp() > 0) {
                            chosenUserFrog = frogsUserChose[inputCheckedForChangeFrog - 1];
                            flag = true;
                        } else {
                            /// TODO: prompt about dead frog chosen for try again
                            std::cout << "prompt\n";
                        }
                    }
                    break;
                }

            }

            std::cout << "Enemy turn!\n";
            if (frogsEnemy[0]->getFrogCurrentHp() > 0) {
                std::cout << "Enemy chose frog # 1 to attack!\n";
                if (frogsEnemy[0]->frogUseSpecialAttack(chosenUserFrog) == 0) {
                    frogsEnemy[0]->attackFrog(chosenUserFrog);
                }
            } else if (frogsEnemy[1]->getFrogCurrentHp() > 0) {
                std::cout << "Enemy chose frog # 2 to attack!\n";
                if (frogsEnemy[1]->frogUseSpecialAttack(chosenUserFrog) == 0) {
                    frogsEnemy[1]->attackFrog(chosenUserFrog);
                }

            } else if (frogsEnemy[2]->getFrogCurrentHp() > 0) {
                std::cout << "Enemy chose frog # 3 to attack!\n";
                if (frogsEnemy[2]->frogUseSpecialAttack(chosenUserFrog) == 0) {
                    frogsEnemy[2]->attackFrog(chosenUserFrog);
                }

            } else if (frogsEnemy[3]->getFrogCurrentHp() > 0) {
                if (frogsEnemy[3]->frogUseSpecialAttack(chosenUserFrog) == 0) {
                    frogsEnemy[3]->attackFrog(chosenUserFrog);
                }
            } else {
                ///TODO: prompt about dead for enemy
                std::cout << "Enemy can't attack! You killed whole team!\n" <<
                          "Round won!\n";

                for (auto frog: frogsUserChose) {
                    frog->restoreHealth();
                }

                continue;
            }

            if (frogsUserChose[0]->getFrogCurrentHp() <= 0 && frogsUserChose[1]->getFrogCurrentHp() <= 0 &&
                frogsUserChose[2]->getFrogCurrentHp() <= 0 &&
                frogsUserChose[3]->getFrogCurrentHp() <= 0 && frogsUserChose[4]->getFrogCurrentHp() <= 0 &&
                frogsUserChose[5]->getFrogCurrentHp() <= 0) {
                std::cout << "Enemy killed whole your team!\n" <<
                          "Game Over!\n";
                break;
            }


            //TODO: same shit for enemy
            if (chosenUserFrog->getFrogSpecialAttack()->getHowManyRoundsWorking() > 0) {
                if (chosenUserFrog->getFrogSpecialAttack()->getHowManyRoundsWorking() == 1) {
                    switch (chosenUserFrog->getFrogSpecialAttack()->getSpecialAttackType_()) {
                        case SpecialAttackType::DEFENSIVE: {
                            std::cout << "prompt  end of special attack bonus\n";
                            chosenUserFrog->restoreStats();
                            break;
                        }
                        case SpecialAttackType::OFFENSIVE: {
                            std::cout << "prompt  end of special attack debuff for enemy\n";
                            enemyFrog->restoreStats();
                            break;
                        }
                    }
                }
                chosenUserFrog->getFrogSpecialAttack()->setHowManyRoundsWorking(
                        chosenUserFrog->getFrogSpecialAttack()->getHowManyRoundsWorking() - 1);

            }


        }


    }


}