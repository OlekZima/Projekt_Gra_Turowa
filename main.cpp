#include <iostream>
#include <array>
#include <random>
#include <memory>
#include "./Frogs/FrogsWithType.hpp"
#include "./Functions/Functions.hpp"

auto randomNumber(int min, int max) -> int;

auto createRandomFrog() -> std::shared_ptr<BaseFrog>;

auto generateUsersFrog() -> std::array<BaseFrog *, 15>;

auto generateEnemyFrogs(float statsCof) -> std::array<BaseFrog *, 4>;

auto makeFrogsForUser() -> std::array<BaseFrog *, 15>;

BaseSpecialAttack *generateRandomSpecialAttack();

const std::string &generateRandomName();

auto main() -> int {

    std::cout << "Welcome to the Game of Frogs, User!\n";
    std::string input;
    int difficulty = 0;


    while (input != "1" && input != "2") {
        std::cout << "Do you want to play?\n";
        std::cout << "Choose (1) to start the game\n" <<
                  "Choose (2) to exit\n";
        std::cin >> input;

        if (input == "--help" || input == "-h") {
            std::cout << "Here you can choose to start the game or exit\n\n" <<
                      "To start the game input (1)\n" <<
                      "To exit input (2)\n\n";
        } else if (input != "1" && input != "2") {
            std::cout << "Wrong input!\n";
        }
    }
    int inputNumber = std::stoi(input);

    if (inputNumber == 1) {

        std::string inputForChooseFrogs;

        auto frogs = std::array<std::shared_ptr<BaseFrog>, 15>{};

        for (int i = 0; i < 15; ++i) {
            frogs[i] = createRandomFrog();
        }

        difficulty = game_functions::chooseDifficulty();

        std::array<std::shared_ptr<BaseFrog>, 6> frogsUserChose{};

        int counter = 0;

        for (int i = 0; i < frogs.size(); ++i) {
            std::cout << "Frog # " << i + 1 << frogs[i]->getFrogInfo() << '\n';
        }

        std::cout << "It's time to choose your Team!\n";
        std::cout << "Choose 6 frogs from the list!\n\n";

        while (counter != 6) {
            std::cout << "Type " + std::to_string((counter + 1)) + " number:";
            std::cin >> inputForChooseFrogs;

            if (inputForChooseFrogs == "-h" || inputForChooseFrogs == "--help") {
                std::cout << "Here you can choose your frogs from the list\n" <<
                          "To choose input number of frog\n" <<
                          "Choose wisely!\n" << "To see list of frogs input --help or -h\n\n";
            } else if (std::stoi(inputForChooseFrogs) > 0 && std::stoi(inputForChooseFrogs) <= 15) {
                frogsUserChose[counter] = frogs[std::stoi(inputForChooseFrogs) - 1];
                counter++;
            } else {
                std::cout << "Wrong input!\n";
            }

            if (counter == 6) {
                std::cout << "Your Team is ready for the greatest adventures!\n\n";
            }
        }

        for (auto frog: frogs) {
            frog.reset();
        }

        int inputNumberForChoose = std::stoi(inputForChooseFrogs);


        switch (difficulty) {
            case 1: {
                std::cout << "You chose Easy!\n" <<
                          "And you have 4 battles to win\n";
                std::cout << "Game is started!\n";
                for (int i = 0; i < 4; ++i) {
                    std::cout << "There is a new enemy in the battle!\n";
                    std::array<std::shared_ptr<BaseFrog>, 4> frogsEnemy{};

                    for (int i = 0; i < 4; ++i) {
                        frogsEnemy[i] = createRandomFrog();
                    }

                    std::shared_ptr<BaseFrog> chosenUserFrog = frogsUserChose[0];

                    std::cout << "Battle " << i + 1 << '\n';
                    while (((frogsUserChose[0])->getHealth() > 0 &&
                            (frogsUserChose[1])->getHealth() > 0 &&
                            (frogsUserChose[2])->getHealth() > 0 &&
                            (frogsUserChose[3])->getHealth() > 0 &&
                            (frogsUserChose[4])->getHealth() > 0 &&
                            (frogsUserChose[5])->getHealth() > 0) ||
                           (frogsEnemy[0]->getHealth() > 0 &&
                            frogsEnemy[1]->getHealth() > 0 &&
                            frogsEnemy[2]->getHealth() > 0 &&
                            frogsEnemy[3]->getHealth() > 0)) {

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

                        if (frogsEnemy[0]->getHealth() > 0) {
                            enemyFrog = frogsEnemy[0];
                        } else if (frogsEnemy[1]->getHealth() > 0) {
                            enemyFrog = frogsEnemy[1];
                        } else if (frogsEnemy[2]->getHealth() > 0) {
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
                                switch (chosenUserFrog->getSpecialAttack()->getSpecialAttackType_()) {
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
                                    if (frogsUserChose[inputCheckedForChangeFrog - 1]->getHealth() > 0) {
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

                        /*while (inputForChooseFrog != "1" && inputForChooseFrog != "2" &&
                               inputForChooseFrog != "3" && inputForChooseFrog != "4" &&
                               inputForChooseFrog != "5" && inputForChooseFrog != "6") {
                            std::cin >> inputForChooseFrog;
                            if (inputForChooseFrog == "--help" || inputForChooseFrog == "-h") {
                                std::cout << "Here you can choose frog number from the list to attack\n" <<
                                          "Choose wisely!\n\n";
                            } else if (inputForChooseFrog < "1" && inputForChooseFrog > "6") {
                                std::cout << "Wrong input!\n";
                            }
                        }*/
                        /*  chosen = std::stoi(inputForChooseFrog) - 1;
                          if ((frogsUserChose[chosen])->getHealth() > 0) {
                              std::string inputForAction;
                              std::cout << "Choose your action!\n";
                              while (inputForAction != "1" && inputForAction != "2") {
                                  std::cout << "1. Attack\n" << "2. Special Attack\n";
                                  std::cin >> inputForAction;
                                  if (inputForAction == "--help" || inputForAction == "-h") {
                                      std::cout << "Here you can choose your action\n" <<
                                                "Choose wisely!\n\n";
                                  } else if (inputForAction != "1" && inputForAction != "2") {
                                      std::cout << "Wrong input!\n";
                                  }
                              }*/
                        /*   int chosenAction = std::stoi(inputForAction);

                           std::string chooseEnemyFrogToAttack;

                           while (chooseEnemyFrogToAttack != "1" && chooseEnemyFrogToAttack != "2" &&
                                  chooseEnemyFrogToAttack != "3" && chooseEnemyFrogToAttack != "4") {
                               std::cout << "Choose frog number to attack it:\n";

                               std::cin >> chooseEnemyFrogToAttack;
                               if (chooseEnemyFrogToAttack == "--help" || chooseEnemyFrogToAttack == "-h") {
                                   std::cout << "Now you can choose frog number from the list to attack it!\n";
                               } else if (chooseEnemyFrogToAttack < "1" && chooseEnemyFrogToAttack > "4") {
                                   std::cout << "Wrong input!\n";
                               }
                           }

                           int chosenEnemyFrogToAttack = std::stoi(chooseEnemyFrogToAttack) - 1;
                           chosenUserFrog->attackFrog(frogsEnemy[chosenEnemyFrogToAttack]);
*/
                        /*   if (frogsEnemy[0]->getHealth() > 0) {
                               std::cout << "Enemy chose frog # 1 to attack!\n";
                               if (frogsEnemy[0]->frogUseSpecialAttack(chosenUserFrog) == 0) {
                                   frogsEnemy[0]->attackFrog(chosenUserFrog);
                               }
                           } else if (frogsEnemy[1]->getHealth() > 0) {
                               std::cout << "Enemy chose frog # 2 to attack!\n";
                               if (frogsEnemy[1]->frogUseSpecialAttack(chosenUserFrog) == 0) {
                                   frogsEnemy[1]->attackFrog(chosenUserFrog);
                               }

                           } else if (frogsEnemy[2]->getHealth() > 0) {
                               std::cout << "Enemy chose frog # 3 to attack!\n";
                               if (frogsEnemy[2]->frogUseSpecialAttack(chosenUserFrog) == 0) {
                                   frogsEnemy[2]->attackFrog(chosenUserFrog);
                               }

                           } else {
                               if (frogsEnemy[3]->frogUseSpecialAttack(chosenUserFrog) == 0) {
                                   frogsEnemy[3]->attackFrog(chosenUserFrog);
                               }
                           }


                       } else {
                           std::cout << "You can't choose dead frog!\n";
                           continue;
                       }*/


                        std::cout << "Enemy turn!\n";
                        if (frogsEnemy[0]->getHealth() > 0) {
                            std::cout << "Enemy chose frog # 1 to attack!\n";
                            if (frogsEnemy[0]->frogUseSpecialAttack(chosenUserFrog) == 0) {
                                frogsEnemy[0]->attackFrog(chosenUserFrog);
                            }
                        } else if (frogsEnemy[1]->getHealth() > 0) {
                            std::cout << "Enemy chose frog # 2 to attack!\n";
                            if (frogsEnemy[1]->frogUseSpecialAttack(chosenUserFrog) == 0) {
                                frogsEnemy[1]->attackFrog(chosenUserFrog);
                            }

                        } else if (frogsEnemy[2]->getHealth() > 0) {
                            std::cout << "Enemy chose frog # 3 to attack!\n";
                            if (frogsEnemy[2]->frogUseSpecialAttack(chosenUserFrog) == 0) {
                                frogsEnemy[2]->attackFrog(chosenUserFrog);
                            }

                        } else if (frogsEnemy[3]->getHealth() > 0) {
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

                        if (frogsUserChose[0]->getHealth() <= 0 && frogsUserChose[1]->getHealth() <= 0 &&
                            frogsUserChose[2]->getHealth() <= 0 &&
                            frogsUserChose[3]->getHealth() <= 0 && frogsUserChose[4]->getHealth() <= 0 &&
                            frogsUserChose[5]->getHealth() <= 0) {
                            std::cout << "Enemy killed whole your team!\n" <<
                                      "Game Over!\n";
                            break;
                        }


                        //TODO: same shit for enemy
                        if (chosenUserFrog->getSpecialAttack()->getHowManyRoundsWorking() > 0) {
                            if (chosenUserFrog->getSpecialAttack()->getHowManyRoundsWorking() == 1) {
                                switch (chosenUserFrog->getSpecialAttack()->getSpecialAttackType_()) {
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
                            chosenUserFrog->getSpecialAttack()->setHowManyRoundsWorking(
                                    chosenUserFrog->getSpecialAttack()->getHowManyRoundsWorking() - 1);

                        }


                    }


                }


                break;
            }
            case 2: {
                std::cout << "You chose Medium!\n" <<
                          "And you have 4 battles to win\n";
                std::cout << "Game is started!\n";
                for (int i = 0; i < 6; ++i) {
                    std::cout << "There is a new enemy in the battle!\n";
                    std::cout << "Battle " << i + 1 << '\n';


                }


                break;
            }
            case 3: {
                std::cout << "You chose Hard!\n" <<
                          "And you have 4 battles to win\n";
                std::cout << "Game is started!\n";
                for (int i = 0; i < 8; ++i) {
                    std::cout << "There is a new enemy in the battle!\n";
                    std::cout << "Battle " << i + 1 << '\n';


                }


                break;
            }

        }


    } else {
        std::cout << "Goodbye!\n";
    }


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
///TODO: When generateRandomSpecialAttack will be done, uncomment this
    switch (randomFrog) {
        case 1: {
            frog = std::make_shared<WaterFrog>();
            //frog->frogGiveSpecialAttack((generateRandomSpecialAttack(frog));
            break;
        }
        case 2: {
            frog = std::make_shared<EarthFrog>();

            //frog->frogGiveSpecialAttack((generateRandomSpecialAttack(frog));
            break;
        }
        case 3: {
            frog = std::make_shared<AirFrog>();

            //frog->frogGiveSpecialAttack((generateRandomSpecialAttack(frog));
            break;
        }
        case 4: {
            frog = std::make_shared<FireFrog>();

            // frog->frogGiveSpecialAttack((generateRandomSpecialAttack(frog));
            break;
        }
        case 5: {
            frog = std::make_shared<IceFrog>();

            // frog->frogGiveSpecialAttack((generateRandomSpecialAttack(frog));
            break;
        }
        case 6: {
            frog = std::make_shared<SteelFrog>();

            //frog->frogGiveSpecialAttack((generateRandomSpecialAttack(frog));
            break;
        }
    }

    frog->setFrogName(generateRandomName());
    frog->setFrogMaxHealth(std::uniform_int_distribution<>(200, 250)(gen));
    frog->setHealth(frog->getFrogMaxHealth());
    frog->setFrogMaxPower(std::uniform_int_distribution<>(50, 80)(gen));
    frog->setPower(frog->getFrogMaxPower());
    frog->setFrogAgility(std::uniform_int_distribution<>(40, 70)(gen));

    return frog;
}

auto randomNumber(int min, int max) -> int {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> silaDis(min, max);
    int a = silaDis(gen);
    return a;
}
///TODO: finish this function
BaseSpecialAttack *generateRandomSpecialAttack() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 6);

}
