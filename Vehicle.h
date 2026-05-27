#pragma once

#include "Exceptions.h"

#include <string>

class Vehicle
{
private:
    static int idCounter;
    int id;

protected:
    std::string brand;
    double distance;

public:
    Vehicle(const std::string &brand, double distance);
    virtual ~Vehicle();

    Vehicle(const Vehicle &) = delete;
    Vehicle &operator=(const Vehicle &) = delete;

    int getId() const;
    std::string getBrand() const;
    double getDistance() const;

    virtual double calculateFuelConsumption() const = 0;

    virtual Vehicle *clone() const = 0;

    bool operator<(const Vehicle &other) const;
};

class Car : public Vehicle
{
private:
    double liters;

public:
    Car(const std::string &brand, double distance, double liters);

    double getLiters() const;

    double calculateFuelConsumption() const override;

    Vehicle *clone() const override;
};

class Motorcycle : public Vehicle
{
private:
    double engineSize;

public:
    Motorcycle(const std::string &brand,
               double distance,
               double engineSize);

    double getEngineSize() const;

    double calculateFuelConsumption() const override;

    Vehicle *clone() const override;
};

class Truck : public Vehicle
{
public:
    Truck(const std::string &brand, double distance);

    double calculateFuelConsumption() const override;

    Vehicle *clone() const override;
};
