#include "FuelStrategy.h"

double MaxFuelStrategy::calculate(const std::vector<Vehicle *> &vehicles) const
{
    double max = vehicles[0]->calculateFuelConsumption();

    for (Vehicle *vehicle : vehicles)
    {
        double value = vehicle->calculateFuelConsumption();

        if (value > max)
        {
            max = value;
        }
    }

    return max;
}
