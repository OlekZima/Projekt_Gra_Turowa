#include <iostream>
#include "FrogsWithType.hpp"

auto WaterFrog::getFrogType() const -> FrogType {
    return FrogType::WATER;
}

WaterFrog::~WaterFrog() {

}

auto EarthFrog::getFrogType() const -> FrogType {
    return FrogType::EARTH;
}

EarthFrog::~EarthFrog() {

}

auto AirFrog::getFrogType() const -> FrogType {
    return FrogType::AIR;
}

AirFrog::~AirFrog() {

}

auto FireFrog::getFrogType() const -> FrogType {
    return FrogType::FIRE;
}

FireFrog::~FireFrog() {

}

auto IceFrog::getFrogType() const -> FrogType {
    return FrogType::ICE;
}

IceFrog::~IceFrog() {

}

auto SteelFrog::getFrogType() const -> FrogType {
    return FrogType::STEEL;
}

SteelFrog::~SteelFrog() {

}
