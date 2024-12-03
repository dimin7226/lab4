#pragma once

#ifndef SPORTSCAR_H
#define SPORTSCAR_H

#include "Car.h"

class SportsCar : public Car {
private:
    double maxSpeed;
    double accelerationTime;
public:
    SportsCar();
    SportsCar(const std::string& color, const std::string& brand, const std::string& model,
        int year, int horsepower, const std::string& engineType, double weight, int numberOfDoors,
        double maxSpeed, double accelerationTime);
    void setMaxSpeed(double maxSpeed);
    double getMaxSpeed() const;
    std::string getCategory() const;
    void setAccelerationTime(double accelerationTime);
    double getAccelerationTime() const;
    void show() const override;
    SportsCar& operator=(const SportsCar& other);
    friend std::ostream& operator << (std::ostream& out, SportsCar& vehicle);
    friend std::istream& operator >> (std::istream& out, SportsCar& vehicle);
    virtual void print(std::ostream& out) const;
    virtual ~SportsCar();
};

#endif