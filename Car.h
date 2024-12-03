#pragma once

#ifndef CAR_H
#define CAR_H

#include "TransportVehicle.h"
class Car : public TransportVehicle {
private:
    double weight;
    int numberOfDoors;
public:
    Car();
    Car(const std::string& color, const std::string& brand, const std::string& model, int year, int horsepower, const std::string& engineType, double weight, int numberOfDoors);
    void setWeightCar(double  weight);
    double getWightCar() const;
    void setNumberOfDoors(int numberOfDoors);
    int getNumberOfDoors() const;
    std::string getCategory() const;
    void show() const override;
    Car& operator=(const Car& other);
    friend std::ostream& operator << (std::ostream& out, Car& vehicle);
    friend std::istream& operator >> (std::istream& out, Car& vehicle);
    virtual void print(std::ostream& out) const;
    virtual ~Car();
};

#endif