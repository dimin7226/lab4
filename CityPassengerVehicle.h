#pragma once

#ifndef CITYPASSENGERVEHICLE_H
#define CITYPASSENGERVEHICLE_H

#include "PassengerVehicle.h"

class CityPassengerVehicle : public PassengerVehicle {
private:
    int routeNumber;
    int numberOfStops;

public:
    CityPassengerVehicle();
    CityPassengerVehicle(const std::string& color, const std::string& brand, const std::string& model,
        int year, int horsepower, const std::string& engineType, int passengerSeats,
        int routeNumber, int numberOfStops);
    void setRouteNumber(int routeNumber);
    int getRouteNumber() const;
    void setNumberOfStops(int numberOfStops);
    int getNumberOfStops() const;
    std::string getCategory() const;
    void show() const override;
    CityPassengerVehicle& operator=(const CityPassengerVehicle& other);
    friend std::ostream& operator << (std::ostream& out, CityPassengerVehicle& vehicle);
    friend std::istream& operator >> (std::istream& out, CityPassengerVehicle& vehicle);
    virtual void print(std::ostream& out) const;
    virtual ~CityPassengerVehicle();
};

#endif