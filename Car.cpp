#include "Vehicle.h"

int Vehicle::idCounter = 0;

Vehicle::Vehicle(const std::string &brand, double distance)
    : brand(brand), distance(distance)
{
    id = ++idCounter;
}

Vehicle::~Vehicle()
{
}

int Vehicle::getId() const
{
    return id;
}

std::string Vehicle::getBrand() const
{
    return brand;
}

double Vehicle::getDistance() const
{
    return distance;
}

bool Vehicle::operator<(const Vehicle &other) const
{
    return brand < other.brand;
}

Car::Car(const std::string &brand,
         double distance,
         double liters)
    : Vehicle(brand, distance), liters(liters)
{
}

double Car::getLiters() const
{
    return liters;
}

double Car::calculateFuelConsumption() const
{
    return (liters / distance) * 100.0;
}

Vehicle *Car::clone() const
{
    return new Car(*this);
}
