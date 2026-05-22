#include "FuelStrategy.h"

FuelStrategy::~FuelStrategy()
{
}

double MinFuelStrategy::calculate(const std::vector<Vehicle *> &vehicles) const
{
    double min = vehicles[0]->calculateFuelConsumption();

    for (Vehicle *vehicle : vehicles)
    {
        double value = vehicle->calculateFuelConsumption();

        if (value < min)
        {
            min = value;
        }
    }

    return min;
}
