#include <iostream>
#include <array>
#include "./Frogs/FrogsWithType.hpp"
#include <ctime>
#include <algorithm>
#include <random>
#include "./Functions/Functions.hpp"

auto generateFrog() -> std::array<BaseFrog *, 15>;

auto foo() -> void;

auto main() -> int {
    foo();
}

auto foo() -> void {
    srand(time(NULL));

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
        auto frogs = generateFrog();
        difficulty = game_functions::chooseDifficulty();

        std::cout << "Choose 6 frogs from the collection\n";
        std::array<BaseFrog *, 6> frogsUserChose{};

        auto frogsVectorToChose = std::vector<BaseFrog *>{};
        for (auto &frog: frogs) {
            frogsVectorToChose.push_back(frog);
        }

        int i = 0;
        for (auto frogToPrint: frogsVectorToChose) {
            std::cout << i + 1 << frogToPrint->getFrogInfo() << "\n";
            i++;
        }

        for (int i = 0; i < 6; i++) {
            std::cout << "Input number of frog:";
            int frogNumber;
            std::cin >> inputNumber;
            input = std::to_string(inputNumber);
            if (input >= "1" && input <= "16") {
                frogsUserChose[i] = frogsVectorToChose[inputNumber - 1];
                frogsVectorToChose.erase(frogsVectorToChose.begin() + inputNumber);
            } else {
                std::cout << "Wrong input!\n";
                i--;
            }
        }

        switch (difficulty) {
            case 1: {
                std::cout << "You chose Easy!\n" <<
                          "And you have 4 battles to win\n";
                std::cout << "Game is started!\n";
                for (int i = 0; i < 4; ++i) {
                    std::cout << "Battle " << i + 1 << '\n';


                }


                break;
            }
            case 2: {
                std::cout << "You chose Medium!\n" <<
                          "And you have 4 battles to win\n";
                std::cout << "Game is started!\n";
                for (int i = 0; i < 6; ++i) {
                    std::cout << "There is a new enemy ;;;";
                    std::cout << "Battle " << i + 1 << '\n';


                }


                break;
            }
            case 3: {
                std::cout << "You chose Hard!\n" <<
                          "And you have 4 battles to win\n";
                std::cout << "Game is started!\n";
                for (int i = 0; i < 8; ++i) {
                    std::cout << "Battle " << i + 1 << '\n';


                }


                break;
            }

        }


    } else {
        std::cout << "Goodbye!\n";
    }


}


auto generateFrog() -> std::array<BaseFrog *, 15> {
    std::array<BaseFrog *, 15> frogsGenerated{};
    for (int i = 0; i < 15; ++i) {
//  min + rand() % (max+1 - min)
        std::random_device rd;
        std::mt19937 mt(rd());

        std::uniform_int_distribution<int> randomType(1, 6);

        int randomNumber = 1 + rand() % 6;


        std::uniform_int_distribution<int> randomHp(200, 250);
        std::uniform_int_distribution<int> randomPower(50, 80);
        std::uniform_int_distribution<int> randomAgility(10, 20);


        switch (randomType(mt)) {
            case 1: {
                auto *waterFrogPointer = new WaterFrog("Bulba", randomHp(mt), randomPower(mt), randomAgility(mt));
                frogsGenerated[i] = waterFrogPointer;
                break;
            }
            case 2: {
                auto *earthFrogPointer = new EarthFrog("Kamien", randomHp(mt), randomPower(mt), randomAgility(mt));
                frogsGenerated[i] = earthFrogPointer;
                break;

            }
            case 3: {
                auto *airFrogPointer = new AirFrog("Wiatr", randomHp(mt), randomPower(mt), randomAgility(mt));
                frogsGenerated[i] = airFrogPointer;
                break;

            }
            case 4: {
                auto *firerFrogPointer = new FirerFrog("Ognie", randomHp(mt), randomPower(mt), randomAgility(mt));
                frogsGenerated[i] = firerFrogPointer;
                break;

            }
            case 5: {
                auto *iceFrogPointer = new IceFrog("Lod", randomHp(mt), randomPower(mt), randomAgility(mt));
                frogsGenerated[i] = iceFrogPointer;
                break;
            }
            case 6: {
                auto *steelFrogPointer = new SteelFrog("Stal", randomHp(mt), randomPower(mt), randomAgility(mt));
                frogsGenerated[i] = steelFrogPointer;
                break;
            }
        }
    }
    return frogsGenerated;
}
