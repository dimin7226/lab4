#pragma once

#ifndef PASSENGERVEHICLE_H
#define PASSENGERVEHICLE_H

#include "TransportVehicle.h"

class PassengerVehicle : public TransportVehicle {
private:
    int passengerSeats;
public:
    PassengerVehicle();
    PassengerVehicle(const std::string& color, const std::string& brand, const std::string& model,
        int year, int horsepower, const std::string& engineType, int passengerSeats);
        // Сеттер и геттер
    void setPassengerSeats(int passengerSeats);
    int getPassengerSeats() const;
    void show() const override;
    PassengerVehicle& operator=(const PassengerVehicle& other);
    friend std::ostream& operator << (std::ostream& out, PassengerVehicle& vehicle);
    friend std::istream& operator >> (std::istream& out, PassengerVehicle& vehicle);
    virtual ~PassengerVehicle();
};

#endif