#include <iostream>
#include "FrogsWithType.hpp"
//#define DEBUG

auto WaterFrog::getFrogType() const -> FrogType {
    return FrogType::WATER;
}

WaterFrog::~WaterFrog()  {
/*#ifdef DEBUG
#endif*/
}

auto EarthFrog::getFrogType() const -> FrogType {
    return FrogType::EARTH;
}

EarthFrog::~EarthFrog() {
/*#ifdef DEBUG
#endif*/
}

auto AirFrog::getFrogType() const -> FrogType {
    return FrogType::AIR;
}

AirFrog::~AirFrog() {
/*#ifdef DEBUG
#endif*/
}

auto FireFrog::getFrogType() const -> FrogType {
    return FrogType::FIRE;
}

FireFrog::~FireFrog() {
/*#ifdef DEBUG

#endif*/
}

auto IceFrog::getFrogType() const -> FrogType {
    return FrogType::ICE;
}

IceFrog::~IceFrog() {
/*#ifdef DEBUG

#endif*/
}

auto SteelFrog::getFrogType() const -> FrogType {
    return FrogType::STEEL;
}

SteelFrog::~SteelFrog() {
/*#ifdef DEBUG
    std::cout << "Destructor of SteelFrog" << std::endl;
#endif*/
}
