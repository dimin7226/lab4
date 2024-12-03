#pragma once

#ifndef INTERNATIONALPASSENGERVEHICLE_H
#define INTERNATIONALPASSENGERVEHICLE_H

#include "PassengerVehicle.h"

class InternationalPassengerVehicle : public PassengerVehicle {
private:
    std::string fromCountry;
    std::string toCountry;
    int travelTime;
public:
    InternationalPassengerVehicle();
    InternationalPassengerVehicle(const std::string& color, const std::string& brand, const std::string& model,
        int year, int horsepower, const std::string& engineType, int passengerSeats,
        const std::string& fromCountry, const std::string& toCountry, int travelTime);
    // Сеттеры и геттеры
    void setFromCountry(const std::string& fromCountry);
    std::string getFromCountry() const;
    void setToCountry(const std::string& toCountry);
    std::string getToCountry() const;
    void setTravelTime(int travelTime);
    int getTravelTime() const;
    std::string getCategory() const;
    void show() const override;
    InternationalPassengerVehicle& operator=(const InternationalPassengerVehicle& other);
    friend std::ostream& operator << (std::ostream& out, InternationalPassengerVehicle& vehicle);
    friend std::istream& operator >> (std::istream& out, InternationalPassengerVehicle& vehicle);
    virtual void print(std::ostream& out) const;
    virtual ~InternationalPassengerVehicle();
};

#endif