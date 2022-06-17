#include <string>
#include <iostream>
#include <random>
#include "../Frogs/BaseFrog.hpp"
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
    }

    auto specialAttackTypeToString(SpecialAttackType type) -> std::string {
        switch (type) {
            case SpecialAttackType::DEFENSIVE:
                return "Defensive";
            case SpecialAttackType::OFFENSIVE:
                return "Offensive";
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
        switch (randomFrog) {
            case 1: {
                frog = std::make_shared<WaterFrog>();
                frog->frogGiveSpecialAttack(generateRandomSpecialAttack(frog->getFrogType()));
                break;
            }
            case 2: {
                frog = std::make_shared<EarthFrog>();

                frog->frogGiveSpecialAttack(generateRandomSpecialAttack(frog->getFrogType()));
                break;
            }
            case 3: {
                frog = std::make_shared<AirFrog>();

                frog->frogGiveSpecialAttack(generateRandomSpecialAttack(frog->getFrogType()));
                break;
            }
            case 4: {
                frog = std::make_shared<FireFrog>();

                frog->frogGiveSpecialAttack(generateRandomSpecialAttack(frog->getFrogType()));
                break;
            }
            case 5: {
                frog = std::make_shared<IceFrog>();

                frog->frogGiveSpecialAttack(generateRandomSpecialAttack(frog->getFrogType()));
                break;
            }
            case 6: {
                frog = std::make_shared<SteelFrog>();

                frog->frogGiveSpecialAttack(generateRandomSpecialAttack(frog->getFrogType()));
                break;
            }
        }

        frog->setFrogName(generateRandomName());
        frog->setFrogMaxHealth(randomNumber(200, 250));
        frog->setCurrentHp(frog->getFrogMaxHealth());
        frog->setFrogMaxPower(randomNumber(50, 80));
        frog->setPower(frog->getFrogMaxPower());
        frog->setFrogAgility(randomNumber(40, 70));

        return frog;
    }

    auto randomNumber(int min, int max) -> int {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> silaDis(min, max);
        int a = silaDis(gen);
        return a;
    }

    auto generateRandomSpecialAttack(const FrogType frogType) -> std::shared_ptr<BaseSpecialAttack> {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 6);

        std::shared_ptr<BaseSpecialAttack> specialAttack;

        int randomSpecialAttackType = std::uniform_int_distribution<>(1, 2)(gen);

        switch (frogType) {
            case FrogType::WATER : {
                switch (randomSpecialAttackType) {
                    case 1: {
                        specialAttack = std::make_shared<DefensiveSpecialAttack>();
                        specialAttack->setSpecialAttackName("Water Fists");
                        break;
                    }
                    case 2: {
                        specialAttack = std::make_shared<OffensiveSpecialAttack>();
                        specialAttack->setSpecialAttackName("Curse of Water");
                        break;
                    }
                }
            }
            case FrogType::EARTH: {
                switch (randomSpecialAttackType) {
                    case 1: {
                        specialAttack = std::make_shared<DefensiveSpecialAttack>();
                        specialAttack->setSpecialAttackName("Earth Fists");
                        break;
                    }
                    case 2: {
                        specialAttack = std::make_shared<OffensiveSpecialAttack>();
                        specialAttack->setSpecialAttackName("Curse of Earth");
                        break;
                    }
                }
            }
            case FrogType::AIR: {
                switch (randomSpecialAttackType) {
                    case 1: {
                        specialAttack = std::make_shared<DefensiveSpecialAttack>();
                        specialAttack->setSpecialAttackName("Air Fists");
                        break;
                    }
                    case 2: {
                        specialAttack = std::make_shared<OffensiveSpecialAttack>();
                        specialAttack->setSpecialAttackName("Curse of Wind");
                        break;
                    }
                }
            }
            case FrogType::FIRE: {
                switch (randomSpecialAttackType) {
                    case 1: {
                        specialAttack = std::make_shared<DefensiveSpecialAttack>();
                        specialAttack->setSpecialAttackName("Fire Fists");
                        break;
                    }
                    case 2: {
                        specialAttack = std::make_shared<OffensiveSpecialAttack>();
                        specialAttack->setSpecialAttackName("Curse of Fire");
                        break;
                    }
                }
            }
            case FrogType::ICE: {
                switch (randomSpecialAttackType) {
                    case 1: {
                        specialAttack = std::make_shared<DefensiveSpecialAttack>();
                        specialAttack->setSpecialAttackName("Ice Fists");
                        break;
                    }
                    case 2: {
                        specialAttack = std::make_shared<OffensiveSpecialAttack>();
                        specialAttack->setSpecialAttackName("Curse of Ice");
                        break;
                    }
                }
            }
            case FrogType::STEEL: {
                switch (randomSpecialAttackType) {
                    case 1: {
                        specialAttack = std::make_shared<DefensiveSpecialAttack>();
                        specialAttack->setSpecialAttackName("Steel Fists");
                        break;
                    }
                    case 2: {
                        specialAttack = std::make_shared<OffensiveSpecialAttack>();
                        specialAttack->setSpecialAttackName("Curse of Steel");
                        break;
                    }
                }
            }
        }
        specialAttack->setHowManyTimesSpecialAttackCanBeUsed(randomNumber(1, 3));
        specialAttack->setSpecialAttackPower(randomNumber(50, 100));
        return specialAttack;
    }

    auto Battle() -> void {

    }

};