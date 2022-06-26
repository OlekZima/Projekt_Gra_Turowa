#include <iostream>
#include <array>
#include <random>
#include <memory>
#include "./Frogs/FrogsWithType.hpp"
#include "./Functions/Functions.hpp"
#include "Frogs/Components/DefensiveSpecialAttack.hpp"

auto main() -> int {
    std::cout
            << "    _____  ____     __    __  _____     ____  _________   _________ ______    ____     _____   _____  \n"
               "   / ___ \\(    )    \\ \\  / / / ___/    / __ \\(_   _____) (_   _____(   __ \\  / __ \\   / ___ \\ / ____\\ \n"
               "  / /   \\_/ /\\ \\    () \\/ ()( (__     / /  \\ \\ ) (___      ) (___   ) (__) )/ /  \\ \\ / /   \\_( (___   \n"
               " ( (  ___( (__) )   / _  _ \\ ) __)   ( ()  () (   ___)    (   ___) (    __/( ()  () ( (  ____ \\___ \\  \n"
               " ( ( (__  )    (   / / \\/ \\ ( (      ( ()  () )) (         ) (      ) \\ \\  ( ()  () ( ( (__  )    ) ) \n"
               "  \\ \\__/ /  /\\  \\ /_/      \\_\\ \\___   \\ \\__/ /(   )       (   )    ( ( \\ \\_)\\ \\__/ / \\ \\__/ / ___/ /  \n"
               "   \\____/__(  )__(/          \\\\____\\   \\____/  \\_/         \\_/      )_) \\__/ \\____/   \\____/ /____/   \n"
               "                                                                                                      \n\n";
    std::cout << "Hi, User!\n";

    std::string input;
    int difficulty = 0;

    while (input != "1" && input != "2") {
        std::cout << "Do you want to play?\n";
        std::cout << "Choose (1) to start the game\n" <<
                  "Choose (2) to exit\n";
        std::cout << "Input:";
        std::cin >> input;

        if (input == "--help" || input == "-h") {
            std::cout << "Here you can choose to start the game or exit\n\n" <<
                      "To start the game input (1)\n" <<
                      "To exit input (2)\n" << "To see this message again type `--help` or `-h`\n\n";
        } else if (input != "1" && input != "2") {
            std::cout << "Wrong input!\n";
        }
    }
    int inputNumber = std::stoi(input);

    if (inputNumber == 1) {

        std::string inputForChooseFrogs;

        auto frogs = std::array<std::shared_ptr<BaseFrog>, 15>{};

        for (int i = 0; i < 15; ++i) {
            frogs[i] = game_functions::createRandomFrog();
        }

        difficulty = game_functions::chooseDifficulty();

        switch (difficulty) {
            case 1:
                std::cout << "\nYou chose Easy!\n\n";
                break;
            case 2:
                std::cout << "\nYou chose Medium!\n\n";
                break;
            case 3:
                std::cout << "\nYou chose Hard!!11!!1!!!1!!!\n\n";
                break;
        }

        std::array<std::shared_ptr<BaseFrog>, 6> frogsUserChose{};

        std::cout << "It's time to choose your Team!\n\n";

        for (int i = 0; i < frogs.size(); ++i) {
            std::cout << "Frog # " << i + 1 << frogs[i]->getFrogInfo();
        }

        std::cout << "Choose 6 frogs from the list!\n\n";

        int counter = 0;

        while (counter != 6) {
            std::cout << "Type " + std::to_string((counter + 1)) + " number:";
            std::cin >> inputForChooseFrogs;

            if (inputForChooseFrogs == "-h" || inputForChooseFrogs == "--help") {
                std::cout << "Here you can choose your frogs from the list\n" <<
                          "To choose input number of frog\n" <<
                          "Choose wisely!\n" << "To see this message again type `--help` or `-h`\n\n";
            } else if (std::stoi(inputForChooseFrogs) > 0 && std::stoi(inputForChooseFrogs) <= 15) {

                bool flagForChooseTeam = false;
                for (int i = 0; i < frogsUserChose.size(); ++i) {
                    if (frogsUserChose[i] == frogs[std::stoi(inputForChooseFrogs) - 1]) {
                        std::cout << "You already chose this frog! Try again\n";
                        flagForChooseTeam = true;
                        break;
                    }
                }
                if (flagForChooseTeam) {
                    continue;
                } else {
                    frogsUserChose[counter] = frogs[std::stoi(inputForChooseFrogs) - 1];
                    counter++;
                }
            } else {
                std::cout << "Wrong input!\n";
            }
            if (counter == 6) {
                std::cout << "\nYour Team is ready for the greatest adventures!\n\n";
            }
        }

        for (auto frog: frogs) {
            frog.reset();
        }

        std::array<std::shared_ptr<BaseFrog>, 4> frogsEnemy{};

        for (int i = 0; i < 4; ++i) {
            frogsEnemy[i] = game_functions::createRandomFrog();
        }

        switch (difficulty) {
            case 1: {
                std::cout <<
                          "You have 4 battles to win\n\n";
                std::cout << "We are preparing your team for the battle!\n\n";
                std::cout << "Game is started!\n";
                for (int i = 0; i < 4; ++i) {
                    std::cout << "There is a new enemy in the battle!\n\n";
                    std::cout << "Battle #" << i + 1 << "\n\n";

                    game_functions::Battle(frogsUserChose, frogsEnemy);
                    //fixed start TODO:
                    for (int j = 0; j < 4; ++j) {
                        frogsEnemy[j] = game_functions::createRandomFrog();
                        frogsUserChose[j]->restoreStats();
                        frogsUserChose[j]->restoreHealth();
                    }
                    ///---------------------------------------------------
                }
                break;
            }
            case 2: {
                std::cout << "You have 6 battles to win\n";
                std::cout << "Game is started!\n";
                for (int i = 0; i < 6; ++i) {
                    std::cout << "There is a new enemy in the battle!\n";
                    std::cout << "Battle " << i + 1 << '\n';

                    game_functions::Battle(frogsUserChose, frogsEnemy);
                    //fixed start TODO:
                    for (int j = 0; j < 4; ++j) {
                        frogsEnemy[j] = game_functions::createRandomFrog();
                        frogsUserChose[j]->restoreStats();
                        frogsUserChose[j]->restoreHealth();
                    }
                    ///---------------------------------------------------
                }
                break;
            }
            case 3: {
                std::cout << "You have 8 battles to win\n";
                std::cout << "Game is started!\n";
                for (int i = 0; i < 8; ++i) {
                    std::cout << "There is a new enemy in the battle!\n";
                    std::cout << "Battle " << i + 1 << '\n';

                    game_functions::Battle(frogsUserChose, frogsEnemy);
                    //fixed start TODO:
                    for (int j = 0; j < 4; ++j) {
                        frogsEnemy[j] = game_functions::createRandomFrog();
                        frogsUserChose[j]->restoreStats();
                        frogsUserChose[j]->restoreHealth();
                    }
                    ///---------------------------------------------------
                }
                break;
            }
        }
    } else std::cout << "Goodbye!\n";
    std::cout << "You won!\n";
    std::cout << "Thanks for playing!\n";
}