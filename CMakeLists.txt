cmake_minimum_required(VERSION 3.21)
project(Projekt_Gra_Turowa)

set(CMAKE_CXX_STANDARD 20)

add_executable(Projekt_Gra_Turowa main.cpp Frogs/BaseFrog.cpp Frogs/BaseFrog.hpp Frogs/Components/Enums/FrogType.hpp Frogs/Components/Enums/SpecialAttackType.hpp Frogs/Components/BaseDefensiveSpecialAttack.cpp Frogs/Components/BaseDefensiveSpecialAttack.hpp Frogs/Components/BaseOffensiveSpecialAttack.cpp Frogs/Components/BaseOffensiveSpecialAttack.hpp Frogs/FrogsWithType.cpp Frogs/FrogsWithType.hpp Frogs/Components/BaseSpecialAttack.cpp Frogs/Components/BaseSpecialAttack.hpp Frogs/Components/damageMultiplier.hpp Frogs/Components/damageMultiplier.cpp Functions/Functions.cpp Functions/Functions.hpp
        )
