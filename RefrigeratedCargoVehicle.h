#pragma once

#ifndef REFRIGERATEDCARGOVEHICLE_H
#define REFRIGERATEDCARGOVEHICLE_H

#include "CargoVehicle.h"

class RefrigeratedCargoVehicle : public CargoVehicle {
private:
  //  std::string getParameterByIndex(int index) const override;
    double minTemperature;
public:
    RefrigeratedCargoVehicle();
    RefrigeratedCargoVehicle(const std::string& color, const std::string& brand, const std::string& model,
        int year, int horsepower, const std::string& engineType, double maxCargoWeight,
        double minTemperature);
    void setMinTemperature(double minTemperature);
    double getMinTemperature() const;
    std::string getCategory() const;
    void show() const override;
    RefrigeratedCargoVehicle& operator=(const RefrigeratedCargoVehicle& other);
    friend std::ostream& operator << (std::ostream& out, RefrigeratedCargoVehicle& vehicle);
    friend std::istream& operator >> (std::istream& out, RefrigeratedCargoVehicle& vehicle);
    virtual void print(std::ostream& out) const;
    virtual ~RefrigeratedCargoVehicle();
};

#endif