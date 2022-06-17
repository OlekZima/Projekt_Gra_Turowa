cmake_minimum_required(VERSION 3.21)
project(Projekt_Gra_Turowa)

set(CMAKE_CXX_STANDARD 20)

add_executable(Projekt_Gra_Turowa main.cpp Frogs/BaseFrog.cpp Frogs/BaseFrog.hpp Frogs/Components/Enums/FrogType.hpp Frogs/Components/Enums/SpecialAttackType.hpp Frogs/Components/DefensiveSpecialAttack.cpp Frogs/Components/DefensiveSpecialAttack.hpp Frogs/Components/OffensiveSpecialAttack.cpp Frogs/Components/OffensiveSpecialAttack.hpp Frogs/FrogsWithType.cpp Frogs/FrogsWithType.hpp Frogs/Components/BaseSpecialAttack.cpp Frogs/Components/BaseSpecialAttack.hpp Frogs/Components/damageMultiplier.hpp Frogs/Components/damageMultiplier.cpp Functions/Functions.cpp Functions/Functions.hpp
        )
