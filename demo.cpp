#include "Garage.h"

#include <algorithm>
#include <iostream>

void printVehicle(const Vehicle *vehicle)
{
    std::cout << vehicle->getBrand()
              << " fuel consumption: "
              << vehicle->calculateFuelConsumption()
              << std::endl;
}

int main()
{
    Garage garage;

    garage.addVehicle(new Car("BMW", 500, 40));
    garage.addVehicle(new Motorcycle("Yamaha", 200, 0.7));

    // iterator
    std::for_each(garage.begin(), garage.end(),
                  [](Vehicle *vehicle)
                  {
                      std::cout << vehicle->getBrand() << std::endl;
                  });

    Vehicle *vehicle = garage.getVehicle(0);

    // polymorphism
    std::cout << std::endl;
    std::cout << "Polymorphism:" << std::endl;
    std::cout << vehicle->calculateFuelConsumption() << std::endl;

    if (Car *car = dynamic_cast<Car *>(vehicle))
    {
        std::cout << car->getLiters() << std::endl;
    }

    // callback
    std::cout << std::endl;
    std::cout << "Callback filter:" << std::endl;
    std::vector<Vehicle *> filtered = garage.filterVehicles(
        [](const Vehicle *vehicle)
        {
            return vehicle->calculateFuelConsumption() > 5;
        });

    for (Vehicle *vehicle : filtered)
    {
        printVehicle(vehicle);
    }

    // deep copy
    Garage copiedGarage = garage;

    copiedGarage.addVehicle(new Car("Audi", 300, 20));

    std::cout << std::endl;
    std::cout << "Deep copy:" << std::endl;
    std::cout << garage.size() << std::endl;
    std::cout << copiedGarage.size() << std::endl;

    AverageFuelStrategy average;

    // strategy
    garage.setStrategy(&average);

    std::cout << std::endl;
    std::cout << "Strategy:" << std::endl;
    std::cout << garage.calculateStats() << std::endl;

    garage.printAllFuelConsumptions();

    return 0;
}
