#pragma once

#ifndef LIMOUSINE_H
#define LIMOUSINE_H

#include "Car.h"

class Limousine : public Car {
private:
    double length;
public:
    Limousine();
    Limousine(const std::string& color, const std::string& brand, const std::string& model,
        int year, int horsepower, const std::string& engineType, double weight, int numberOfDoors,
        double length);
    void setLength(double length);
    double getLength() const;
    void show() const override;
    Limousine& operator=(const Limousine& other);
    friend std::ostream& operator << (std::ostream& out, Limousine& vehicle);
    friend std::istream& operator >> (std::istream& out, Limousine& vehicle);
    virtual ~Limousine();
};

#endif