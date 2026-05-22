#include "Garage.h"

#include <cassert>

int main()
{
    Garage garage;

    garage.addVehicle(new Car("BMW", 100, 10));
    garage.addVehicle(new Motorcycle("Honda", 100, 0.6));

    assert(garage.size() == 2);

    Vehicle *vehicle = garage.getVehicle(0);

    assert(vehicle->calculateFuelConsumption() == 10);

    std::vector<Vehicle *> filtered = garage.filterVehicles(
        [](const Vehicle *vehicle)
        {
            return vehicle->calculateFuelConsumption() >= 5;
        });

    assert(filtered.size() == 1);

    return 0;
}
