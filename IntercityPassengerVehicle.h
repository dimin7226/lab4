#pragma once

#ifndef INTERCITYPASSENGERVEHICLE_H
#define INTERCITYPASSENGERVEHICLE_H

#include "PassengerVehicle.h"

class IntercityPassengerVehicle : public PassengerVehicle {
private:
    std::string fromCity;
    std::string toCity;
    double routeLength;

public:
    IntercityPassengerVehicle();
    IntercityPassengerVehicle(const std::string& color, const std::string& brand, const std::string& model,
        int year, int horsepower, const std::string& engineType, int passengerSeats,
        const std::string& fromCity, const std::string& toCity, double routeLength);
    void setFromCity(const std::string& fromCity);
    std::string getFromCity() const;
    void setToCity(const std::string& toCity);
    std::string getToCity() const;
    void setRouteLength(double routeLength);
    double getRouteLength() const;
    void show() const override;
    IntercityPassengerVehicle& operator=(const IntercityPassengerVehicle& other);
    friend std::ostream& operator << (std::ostream& out, IntercityPassengerVehicle& vehicle);
    friend std::istream& operator >> (std::istream& out, IntercityPassengerVehicle& vehicle);
    virtual ~IntercityPassengerVehicle();
};

#endif