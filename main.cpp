#include <iostream>
#include <array>
#include "./Frogs/FrogsWithType.hpp"
#include <ctime>
#include <algorithm>
#include "./Functions/Functions.hpp"

auto generateFrog() -> std::array<BaseFrog *, 15>;
auto foo() -> void;

auto main() -> int {

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
            std::cout << "Here you can choose to start the game or exit\n" <<
                      "To start the game input (1)\n" <<
                      "To exit input (2)\n";
        } else if (input != "1" && input != "2") {
            std::cout << "Wrong input!\n";
        }
    }
    int inputNumber = std::stoi(input);

    if (inputNumber == 1) {
        auto frogs = generateFrog();
        difficulty = game_functions::chooseDifficulty();
        //make user choose 6 frogs from the collection frogs
        std::cout << "Choose 6 frogs from the collection\n";
        std::array<BaseFrog *, 6> frogsUserChose{};
        auto frogsVectorToChose = std::vector<BaseFrog *>{};

        for (auto &frog: frogs) {
            frogsVectorToChose.push_back(frog);
        }

        for (auto frogToPrint: frogsVectorToChose) {
            std::cout << "1." << frogToPrint->getFrogInfo() << "\n";
        }


        for (int i = 0; i < 6; i++) {
            std::cout << "Input number of frog:";
            std::cin >> input;
            int inputNumber = std::stoi(input);
            if (inputNumber > 1 && inputNumber < 16) {
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
        int randomNumber = 1 + rand() % 6;

        switch (randomNumber) {
            case 1: {
                auto *waterFrogPointer = new WaterFrog("Bulba", 200 + rand() % (251 - 200),
                                                       50 + rand() % (81 - 50),
                                                       10 + rand() % (21 - 10));
                frogsGenerated[i] = waterFrogPointer;
                break;
            }
            case 2: {
                auto *earthFrogPointer = new EarthFrog("Kamien", 200 + rand() % (251 - 200),
                                                       50 + rand() % (81 - 50),
                                                       10 + rand() % (21 - 10));
                frogsGenerated[i] = earthFrogPointer;
                break;

            }
            case 3: {
                auto *airFrogPointer = new AirFrog("Wiatr", 200 + rand() % (251 - 200),
                                                   50 + rand() % (81 - 50),
                                                   10 + rand() % (21 - 10));
                frogsGenerated[i] = airFrogPointer;
                break;

            }
            case 4: {
                auto *firerFrogPointer = new FirerFrog("Ognie", 200 + rand() % (251 - 200),
                                                       50 + rand() % (81 - 50),
                                                       10 + rand() % (21 - 10));
                frogsGenerated[i] = firerFrogPointer;
                break;

            }
            case 5: {
                auto *iceFrogPointer = new IceFrog("Lod", 200 + rand() % (251 - 200),
                                                   50 + rand() % (81 - 50),
                                                   10 + rand() % (21 - 10));
                frogsGenerated[i] = iceFrogPointer;
                break;
            }
            case 6: {
                auto *steelFrogPointer = new SteelFrog("Stal", 200 + rand() % (251 - 200),
                                                       50 + rand() % (81 - 50),
                                                       10 + rand() % (21 - 10));
                frogsGenerated[i] = steelFrogPointer;
                break;
            }
        }
    }
    return frogsGenerated;
}
