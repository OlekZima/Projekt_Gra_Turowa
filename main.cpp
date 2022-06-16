#include <iostream>
#include <array>
#include <random>
#include <memory>
#include "./Frogs/FrogsWithType.hpp"
#include "./Functions/Functions.hpp"

auto getRandomNumber(int min, int max) -> int;

auto createRandomFrog() -> BaseFrog *;

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

        auto frogs = std::array<BaseFrog *, 15>{};

        for (int i = 0; i < 15; ++i) {
            frogs[i] = createRandomFrog();
        }

        difficulty = game_functions::chooseDifficulty();

        std::array<BaseFrog *, 6> frogsUserChose{};

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


        int inputNumberForChoose = std::stoi(inputForChooseFrogs);


        switch (difficulty) {
            case 1: {
                std::cout << "You chose Easy!\n" <<
                          "And you have 4 battles to win\n";
                std::cout << "Game is started!\n";
                for (int i = 0; i < 4; ++i) {
                    std::cout << "There is a new enemy in the battle!\n";
                    std::array<BaseFrog *, 4> frogsEnemy{};

                    for (int i = 0; i < 4; ++i) {
                        frogsEnemy[i] = createRandomFrog();
                    }

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
                        ///TODO:
                        /// turn by user
                        std::cout << "Your turn!\n";
                        std::cout << "Choose frog number to attack:\n";
                        BaseFrog *chosenUserFrog;
                        int chosen;
                        std::string inputForChooseFrog;
                        while (inputForChooseFrog != "1" && inputForChooseFrog != "2" &&
                               inputForChooseFrog != "3" && inputForChooseFrog != "4" &&
                               inputForChooseFrog != "5" && inputForChooseFrog != "6") {
                            std::cin >> inputForChooseFrog;
                            if (inputForChooseFrog == "--help" || inputForChooseFrog == "-h") {
                                std::cout << "Here you can choose frog number from the list to attack\n" <<
                                          "Choose wisely!\n\n";
                            } else if (inputForChooseFrog < "1" && inputForChooseFrog > "6") {
                                std::cout << "Wrong input!\n";
                            }
                        }
                        chosen = std::stoi(inputForChooseFrog) - 1;
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
                            }

                            int chosenAction = std::stoi(inputForAction);

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

                            } else {
                                if (frogsEnemy[3]->frogUseSpecialAttack(chosenUserFrog) == 0) {
                                    frogsEnemy[3]->attackFrog(chosenUserFrog);
                                }
                            }


                        } else {
                            std::cout << "You can't choose dead frog!\n";
                            continue;
                        }


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

                        } else {
                            if (frogsEnemy[3]->frogUseSpecialAttack(chosenUserFrog) == 0) {
                                frogsEnemy[3]->attackFrog(chosenUserFrog);
                            }
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

auto makeFrogsForUser() -> std::array<BaseFrog *, 15> {

    std::array<BaseFrog *, 15> frogsToUser{};

    frogsToUser[0] = new WaterFrog("Fukasaku", 247, 55, 15);
    frogsToUser[1] = new WaterFrog("Gama", 212, 77, 20);
    frogsToUser[2] = new WaterFrog("Gamabunta", 227, 54, 25);
    frogsToUser[3] = new EarthFrog("Gamaden", 243, 77, 30);
    frogsToUser[4] = new EarthFrog("Gamagorō", 229, 51, 35);
    frogsToUser[5] = new EarthFrog("Gamahiro", 250, 55, 40);
    frogsToUser[6] = new AirFrog("Gamaken", 209, 67, 45);
    frogsToUser[7] = new AirFrog("Gamakichi", 236, 62, 50);
    frogsToUser[8] = new FireFrog("Gamamaru", 201, 67, 55);
    frogsToUser[9] = new FireFrog("Gamamichi", 218, 78, 60);
    frogsToUser[10] = new FireFrog("Gamariki", 231, 75, 65);
    frogsToUser[11] = new SteelFrog("Gamatama", 207, 74, 70);
    frogsToUser[12] = new SteelFrog("Gamatatsu", 205, 61, 75);
    frogsToUser[13] = new SteelFrog("Gekomatsu", 224, 68, 80);
    frogsToUser[14] = new AirFrog("Gerotora", 225, 66, 85);
    return frogsToUser;
}

const std::string &generateRandomName() {
    std::random_device rd;
    std::mt19937 gen(rd());

    auto frogNames = std::vector<std::string>{
            "Bulba", "Kamien", "Wiatr", "Ognie", "Lod", "Stal", "Fukasaku", "Gama", "Gamabunta", "Gamaden", "Gamagorō",
            "Gamahiro", "Gamaken", "Gamakichi", "Gamamaru", "Gamamichi", "Gamariki", "Gamatama", "Gamatatsu",
            "Gekomatsu", "Gerotora"
    };
    std::uniform_int_distribution<> dis(0, frogNames.size() - 1);

    return frogNames[dis(rd)];

}

auto createRandomFrog() -> BaseFrog * {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 6);

    BaseFrog *frog;

    switch (dis(rd)) {
        case 1: {
            frog = new WaterFrog();
            //frog->frogGiveSpecialAttack(generateRandomSpecialAttack());
            break;
        }
        case 2: {
            frog = new EarthFrog();
            //frog->frogGiveSpecialAttack(generateRandomSpecialAttack());
            break;
        }
        case 3: {
            frog = new AirFrog();
            //frog->frogGiveSpecialAttack(generateRandomSpecialAttack());
            break;
        }
        case 4: {
            frog = new FireFrog();
           // frog->frogGiveSpecialAttack(generateRandomSpecialAttack());
            break;
        }
        case 5: {
            frog = new IceFrog();
           // frog->frogGiveSpecialAttack(generateRandomSpecialAttack());
            break;
        }
        case 6: {
            frog = new SteelFrog();
            //frog->frogGiveSpecialAttack(generateRandomSpecialAttack());
            break;
        }
    }

    frog->setFrogName(generateRandomName());
    frog->setFrogMaxHealth(getRandomNumber(200, 250));
    frog->setFrogMaxPower(getRandomNumber(50, 80));
    frog->setFrogAgility(getRandomNumber(10, 20));

    return frog;
}

auto getRandomNumber(int min, int max) -> int{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);

    return dis(rd);
}

BaseSpecialAttack *generateRandomSpecialAttack() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 6);

}
