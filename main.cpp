#include <iostream>
#include <array>
#include "./Frogs/FrogsWithType.hpp"
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <stdlib.h>
#include "./Functions/Functions.hpp"

auto generateUsersFrog() -> std::array<BaseFrog *, 15>;

auto generateEnemyFrogs(float statsCof) -> std::array<BaseFrog *, 4>;

auto foo() -> void;

auto main() -> int {
    srand(time(nullptr));
    std::cout << "Welcome to the game, User!\n";
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

        auto frogs = generateUsersFrog();
        difficulty = game_functions::chooseDifficulty();

        std::array<BaseFrog *, 6> frogsUserChose{};

        std::cout << "Choose 6 frogs from the list!\n\n";

        int currentAmountOfFrogs = 15;

        for (int i = 0; i < 6; i++) {
            std::cout << "Frogs list to choose\n";
            for (int j = 0; j < currentAmountOfFrogs; j++) {
                std::cout << "Frog # " << j + 1 << ':' << frogs[i]->getFrogInfo() << '\n';
            }
            std::cout << "Choose frog number " << i + 1 << ":\n";

            char currentAmountTmp = (char) currentAmountOfFrogs;
            std::string tmpAmount = std::to_string(currentAmountTmp);

            /// Maybe doesn't work
            while (inputForChooseFrogs >= "1" && inputForChooseFrogs <= tmpAmount) {
                std::cin >> inputForChooseFrogs;

                if (inputForChooseFrogs == "--help" || inputForChooseFrogs == "-h") {
                    std::cout << "Here you can choose frog number from the list to add them to your team\n" <<
                              "Choose wisely!\n\n";
                } else if (inputForChooseFrogs < "1" && inputForChooseFrogs > tmpAmount) {
                    std::cout << "Wrong input!\n";
                }
            }

//            int inputNumberForChoose = std::stoi(inputForChooseFrogs);

            frogsUserChose[i] = frogs[std::stoi(inputForChooseFrogs) - 1];
            (void) std::remove(frogs.begin(), frogs.end(), frogs[std::stoi(inputForChooseFrogs) - 1]);

        }

        switch (difficulty) {
            case 1: {
                std::cout << "You chose Easy!\n" <<
                          "And you have 4 battles to win\n";
                std::cout << "Game is started!\n";
                for (int i = 0; i < 4; ++i) {
                    std::cout << "There is a new enemy in the battle!\n";
                    std::array<BaseFrog *, 4> frogsEnemy = generateEnemyFrogs(1);
                    std::cout << "Battle " << i + 1 << '\n';
                    while ((frogsUserChose[0]->getHealth() > 0 &&
                            frogsUserChose[1]->getHealth() > 0 &&
                            frogsUserChose[2]->getHealth() > 0 &&
                            frogsUserChose[3]->getHealth() > 0 &&
                            frogsUserChose[4]->getHealth() > 0 &&
                            frogsUserChose[5]->getHealth() > 0) ||
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
                        if (frogsUserChose[chosen]->getHealth() > 0) {
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


auto foo() -> void {
    /* std::cout << "Welcome to the game, User!\n";
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

         auto frogs = generateUsersFrog();
         difficulty = game_functions::chooseDifficulty();

         std::array<BaseFrog *, 6> frogsUserChose{};

         std::cout << "Choose 6 frogs from the list!\n\n";

         int currentAmountOfFrogs = 15;

         for (int i = 0; i < 6; i++) {
             std::cout << "Frogs list to choose\n";
             for (int j = 0; j < currentAmountOfFrogs; j++) {
                 std::cout << "Frog # " << j + 1 << ':' << frogs[i]->getFrogInfo() << '\n';
             }
             std::cout << "Choose frog number " << i + 1 << ":\n";

             char currentAmountTmp = (char) currentAmountOfFrogs;
             std::string tmpAmount = std::to_string(currentAmountTmp);

             /// Maybe doesn't work
             while (inputForChooseFrogs >= "1" && inputForChooseFrogs <= tmpAmount) {
                 std::cin >> inputForChooseFrogs;

                 if (inputForChooseFrogs == "--help" || inputForChooseFrogs == "-h") {
                     std::cout << "Here you can choose frog number from the list to add them to your team\n" <<
                               "Choose wisely!\n\n";
                 } else if (inputForChooseFrogs < "1" && inputForChooseFrogs > "16") {
                     std::cout << "Wrong input!\n";
                 }
             }
             frogsUserChose[i] = frogs[std::stoi(inputForChooseFrogs) - 1];
             (void) std::remove(frogs.begin(), frogs.end(), frogs[std::stoi(inputForChooseFrogs) - 1]);

         }


         switch (difficulty) {
             case 1: {
                 std::cout << "You chose Easy!\n" <<
                           "And you have 4 battles to win\n";
                 std::cout << "Game is started!\n";
                 for (int i = 0; i < 4; ++i) {
                     std::cout << "There is a new enemy in the battle!\n";
                     std::cout << "Battle " << i + 1 << '\n';


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


 }*/
}

auto generateUsersFrog() -> std::array<BaseFrog *, 15> {
    srand(time(nullptr));
    std::array<BaseFrog *, 15> frogsGenerated{};
    for (int i = 0; i < 15; ++i) {
//  min + rand() % (max+1 - min)

        int randomType = 1 + rand() % (6 + 1 - 1);

        int randomHealth = 200 + rand() % (250 + 1 - 200);
        int randomPower = 50 + rand() % (80 + 1 - 50);
        int randomAgility = 10 + rand() % (20 + 1 - 10);

        switch (randomType) {
            case 1: {
                auto *waterFrogPointer = new WaterFrog("Bulba", randomHealth, randomPower, randomAgility);
                frogsGenerated[i] = waterFrogPointer;
                break;
            }
            case 2: {
                auto *earthFrogPointer = new EarthFrog("Kamien", randomHealth, randomPower, randomAgility);
                frogsGenerated[i] = earthFrogPointer;
                break;

            }
            case 3: {
                auto *airFrogPointer = new AirFrog("Wiatr", randomHealth, randomPower, randomAgility);
                frogsGenerated[i] = airFrogPointer;
                break;

            }
            case 4: {
                auto *firerFrogPointer = new FirerFrog("Ognie", randomHealth, randomPower, randomAgility);
                frogsGenerated[i] = firerFrogPointer;
                break;

            }
            case 5: {
                auto *iceFrogPointer = new IceFrog("Lod", randomHealth, randomPower, randomAgility);
                frogsGenerated[i] = iceFrogPointer;
                break;
            }
            case 6: {
                auto *steelFrogPointer = new SteelFrog("Stal", randomHealth, randomPower, randomAgility);
                frogsGenerated[i] = steelFrogPointer;
                break;
            }
        }
    }
    return frogsGenerated;
}

auto generateEnemyFrogs(float statsCof) -> std::array<BaseFrog *, 4> {
    srand(time(nullptr));
    std::array<BaseFrog *, 4> frogsGenerated{};
    for (int i = 0; i < 4; ++i) {
//  min + rand() % (max+1 - min)

        int randomType = 1 + rand() % (6 + 1 - 1);

        int randomHealth = (200 + rand() % (250 + 1 - 200)) * statsCof;
        int randomPower = (50 + rand() % (80 + 1 - 50)) * statsCof;
        int randomAgility = (10 + rand() % (20 + 1 - 10)) * statsCof;

        switch (randomType) {
            case 1: {
                auto *waterFrogPointer = new WaterFrog("Bulba", randomHealth, randomPower, randomAgility);
                frogsGenerated[i] = waterFrogPointer;
                break;
            }
            case 2: {
                auto *earthFrogPointer = new EarthFrog("Kamien", randomHealth, randomPower, randomAgility);
                frogsGenerated[i] = earthFrogPointer;
                break;

            }
            case 3: {
                auto *airFrogPointer = new AirFrog("Wiatr", randomHealth, randomPower, randomAgility);
                frogsGenerated[i] = airFrogPointer;
                break;

            }
            case 4: {
                auto *firerFrogPointer = new FirerFrog("Ognie", randomHealth, randomPower, randomAgility);
                frogsGenerated[i] = firerFrogPointer;
                break;

            }
            case 5: {
                auto *iceFrogPointer = new IceFrog("Lod", randomHealth, randomPower, randomAgility);
                frogsGenerated[i] = iceFrogPointer;
                break;
            }
            case 6: {
                auto *steelFrogPointer = new SteelFrog("Stal", randomHealth, randomPower, randomAgility);
                frogsGenerated[i] = steelFrogPointer;
                break;
            }
        }
    }
    return frogsGenerated;


}
