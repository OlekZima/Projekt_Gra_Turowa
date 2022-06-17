#pragma once

#include <memory>
#include "Components/Based/BaseFrog.hpp"

class WaterFrog : public BaseFrog {
public:
    using BaseFrog::BaseFrog;

    auto getFrogType() const -> FrogType override;

    ~WaterFrog() override;

};

class EarthFrog : public BaseFrog {
public:
    using BaseFrog::BaseFrog;

    auto getFrogType() const -> FrogType override;

    ~EarthFrog() override;

};

class AirFrog : public BaseFrog {
public:
    using BaseFrog::BaseFrog;

    auto getFrogType() const -> FrogType override;

    ~AirFrog() override;

};

class FireFrog : public BaseFrog {
public:
    using BaseFrog::BaseFrog;

    auto getFrogType() const -> FrogType override;

    ~FireFrog() override;

};

class IceFrog : public BaseFrog {
public:
    using BaseFrog::BaseFrog;

    auto getFrogType() const -> FrogType override;

    ~IceFrog() override;

};

class SteelFrog : public BaseFrog {
public:
    using BaseFrog::BaseFrog;

    auto getFrogType() const -> FrogType override;

    ~SteelFrog() override;

};

