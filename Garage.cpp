#include "Garage.h"

#include <iostream>

class Garage::Impl
{
public:
    std::vector<Vehicle *> vehicles;
    FuelStrategy *strategy;

    Impl()
    {
        strategy = nullptr;
    }
};

Garage::ForwardIterator::ForwardIterator(Vehicle **ptr)
{
    this->ptr = ptr;
}

Garage::ForwardIterator::reference Garage::ForwardIterator::operator*() const
{
    return *ptr;
}

Garage::ForwardIterator &Garage::ForwardIterator::operator++()
{
    ++ptr;
    return *this;
}

bool Garage::ForwardIterator::operator!=(const ForwardIterator &other) const
{
    return ptr != other.ptr;
}

Garage::Garage()
{
    pimpl = new Impl();
}

Garage::Garage(const Garage &other)
{
    pimpl = new Impl();

    for (Vehicle *vehicle : other.pimpl->vehicles)
    {
        pimpl->vehicles.push_back(vehicle->clone());
    }

    pimpl->strategy = other.pimpl->strategy;
}

Garage &Garage::operator=(const Garage &other)
{
    if (this != &other)
    {
        for (Vehicle *vehicle : pimpl->vehicles)
        {
            delete vehicle;
        }

        pimpl->vehicles.clear();

        for (Vehicle *vehicle : other.pimpl->vehicles)
        {
            pimpl->vehicles.push_back(vehicle->clone());
        }

        pimpl->strategy = other.pimpl->strategy;
    }

    return *this;
}

Garage::~Garage()
{
    for (Vehicle *vehicle : pimpl->vehicles)
    {
        delete vehicle;
    }

    delete pimpl;
}

void Garage::addVehicle(Vehicle *vehicle)
{
    pimpl->vehicles.push_back(vehicle);
}

void Garage::removeVehicle(int index)
{
    delete pimpl->vehicles[index];
    pimpl->vehicles.erase(pimpl->vehicles.begin() + index);
}

Vehicle *Garage::getVehicle(int index) const
{
    return pimpl->vehicles[index];
}

int Garage::size() const
{
    return pimpl->vehicles.size();
}

Garage::ForwardIterator Garage::begin()
{
    return ForwardIterator(pimpl->vehicles.data());
}

Garage::ForwardIterator Garage::end()
{
    return ForwardIterator(pimpl->vehicles.data() + pimpl->vehicles.size());
}

void Garage::setStrategy(FuelStrategy *strategy)
{
    pimpl->strategy = strategy;
}

double Garage::calculateStats() const
{
    if (pimpl->strategy == nullptr)
    {
        throw StrategyNotSetException();
    }

    return pimpl->strategy->calculate(pimpl->vehicles);
}

std::vector<Vehicle *> Garage::filterVehicles(
    std::function<bool(const Vehicle *)> callback) const
{
    std::vector<Vehicle *> result;

    for (Vehicle *vehicle : pimpl->vehicles)
    {
        if (callback(vehicle))
        {
            result.push_back(vehicle);
        }
    }

    return result;
}

void Garage::printAllFuelConsumptions() const
{
    for (Vehicle *vehicle : pimpl->vehicles)
    {
        std::cout << vehicle->getBrand()
                  << " -> "
                  << vehicle->calculateFuelConsumption()
                  << std::endl;
    }
}
