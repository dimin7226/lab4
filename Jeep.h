#pragma once

#ifndef JEEP_H
#define JEEP_H

#include "Car.h"

class Jeep : public Car {
private:
    double clearance;

public:
    Jeep();
    Jeep(const std::string& color, const std::string& brand, const std::string& model,
        int year, int horsepower, const std::string& engineType, double weight, int numberOfDoors,
        double clearance);
    void setClearance(double clearance);
    double getClearance() const;
    void show() const override;
    Jeep& operator=(const Jeep& other);
    friend std::ostream& operator << (std::ostream& out, Jeep& vehicle);
    friend std::istream& operator >> (std::istream& out, Jeep& vehicle);
    virtual ~Jeep();
};

#endif