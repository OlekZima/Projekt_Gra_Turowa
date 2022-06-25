cmake_minimum_required(VERSION 3.21)
project(Projekt_Gra_Turowa)

set(CMAKE_CXX_STANDARD 20)
set(BUILD_SHARED_LIBS OFF)
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(
        Projekt_Gra_Turowa main.cpp Frogs/Components/Based/BaseFrog.cpp Frogs/Components/Based/BaseFrog.hpp Frogs/Components/Enums/FrogType.hpp
        Frogs/Components/Enums/SpecialAttackType.hpp Frogs/Components/DefensiveSpecialAttack.cpp
        Frogs/Components/DefensiveSpecialAttack.hpp Frogs/Components/OffensiveSpecialAttack.cpp
        Frogs/Components/OffensiveSpecialAttack.hpp Frogs/FrogsWithType.cpp Frogs/FrogsWithType.hpp
        Frogs/Components/Based/BaseSpecialAttack.cpp Frogs/Components/Based/BaseSpecialAttack.hpp Functions/Functions.cpp
        Functions/Functions.hpp)
