#pragma once

#include "FuelStrategy.h"

#include <functional>
#include <iterator>
#include <vector>

class Garage
{
private:
    class Impl;
    Impl *pimpl;

public:
    class ForwardIterator
    {
    private:
        Vehicle **ptr;

    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = Vehicle *;
        using difference_type = std::ptrdiff_t;
        using pointer = Vehicle **;
        using reference = Vehicle *&;

        ForwardIterator(Vehicle **ptr);

        reference operator*() const;

        ForwardIterator &operator++();

        bool operator!=(const ForwardIterator &other) const;
    };

    Garage();

    Garage(const Garage &other);

    Garage &operator=(const Garage &other);

    ~Garage();

    void addVehicle(Vehicle *vehicle);

    void removeVehicle(int index);

    Vehicle *getVehicle(int index) const;

    int size() const;

    ForwardIterator begin();

    ForwardIterator end();

    void setStrategy(FuelStrategy *strategy);

    double calculateStats() const;

    std::vector<Vehicle *> filterVehicles(
        std::function<bool(const Vehicle *)> callback) const;

    void printAllFuelConsumptions() const;
};
