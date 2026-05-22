#include "FuelStrategy.h"

double AverageFuelStrategy::calculate(const std::vector<Vehicle *> &vehicles) const
{
    double sum = 0;

    for (Vehicle *vehicle : vehicles)
    {
        sum += vehicle->calculateFuelConsumption();
    }

    return sum / vehicles.size();
}
