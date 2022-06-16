#include <string>
#include <iostream>
#include "../Frogs/BaseFrog.hpp"

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

    auto FrogLvlPromotion(BaseFrog *frogToUpgrade) -> void {
        std::string option;
        while (option != "1" && option != "2" && option != "3") {
            cout << "You can upgrade your Frog now!\n";

            cout << "\t(1) Upgrade strength +23\n";
            cout << "\t(2) Upgrade dexterity +4\n";
            cout << "\t(3) Cancel\n";

            cout << "Input:";
            cin >> option;

            if (option == "--help" || option == "-h") {
                cout << "Choose 1. to increase Frog's power by 23! " <<
                     "2. to increase Frog's agility by 4! " <<
                     "3. or anything else to cancel\n\n";
            }
        }

        if (option == "1") {
            frogToUpgrade->setPower(frogToUpgrade->getPower() + 23);
            cout << "Power increased!\n";
        } else if (option == "2") {
            frogToUpgrade->FrogSetAgility(frogToUpgrade->FrogGetAgility() + 4);
            cout << "Agility increased!\n";
        } else {
            return;
        }
    }

    auto generateFrogCollection() -> BaseFrog *
    {
        for (int i = 0; i < 15; ++i)
        {

        }
    }


};