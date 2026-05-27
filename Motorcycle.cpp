#include "Vehicle.h"

Motorcycle::Motorcycle(const std::string &brand,
                       double distance,
                       double engineSize)
    : Vehicle(brand, distance), engineSize(engineSize)
{
}

double Motorcycle::getEngineSize() const
{
    return engineSize;
}

double Motorcycle::calculateFuelConsumption() const
{
    return engineSize * 0.8;
}

Vehicle *Motorcycle::clone() const
{
    return new Motorcycle(brand, distance, engineSize);
}
