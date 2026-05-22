#pragma once

#include "Vehicle.h"

#include <vector>

class FuelStrategy
{
public:
    virtual ~FuelStrategy();

    virtual double calculate(const std::vector<Vehicle *> &vehicles) const = 0;
};

class MinFuelStrategy : public FuelStrategy
{
public:
    double calculate(const std::vector<Vehicle *> &vehicles) const override;
};

class MaxFuelStrategy : public FuelStrategy
{
public:
    double calculate(const std::vector<Vehicle *> &vehicles) const override;
};

class AverageFuelStrategy : public FuelStrategy
{
public:
    double calculate(const std::vector<Vehicle *> &vehicles) const override;
};
