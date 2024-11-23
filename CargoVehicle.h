#pragma once

#ifndef CARGOVEHICLE_H
#define CARGOVEHICLE_H

#include "TransportVehicle.h"

class CargoVehicle : public TransportVehicle {
private:
    //std::string getParameterByIndex(int index) const override;
    double maxCargoWeight;
public:
    CargoVehicle();
    CargoVehicle(const std::string& color, const std::string& brand, const std::string& model, int year, int horsepower, const std::string& engineType, double maxCargoWeight);
    void setMaxWeight(double  maxCargoWeight);
    double getMaxWeight() const;
    void show() const override;
    CargoVehicle& operator=(const CargoVehicle& other);
    friend std::ostream& operator << (std::ostream& out, CargoVehicle& vehicle);
    friend std::istream& operator >> (std::istream& out, CargoVehicle& vehicle);
    virtual ~CargoVehicle();
};

#endif