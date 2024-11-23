#pragma once
#include "PassengerVehicle.h"
#include "InternationalPassengerVehicle.h"

InternationalPassengerVehicle::InternationalPassengerVehicle() : travelTime(0) {
 //   std::cout << "Конструктор InternationalPassengerVehicle\n";
}

InternationalPassengerVehicle::InternationalPassengerVehicle(const std::string& color, const std::string& brand, const std::string& model,
    int year, int horsepower, const std::string& engineType, int passengerSeats,
    const std::string& fromCountry, const std::string& toCountry, int travelTime)
    : PassengerVehicle(color, brand, model, year, horsepower, engineType, passengerSeats),
    fromCountry(fromCountry), toCountry(toCountry), travelTime(travelTime) {
   // std::cout << "Конструктор InternationalPassengerVehicle с параметрами\n";
}

// Сеттеры и геттеры
void InternationalPassengerVehicle::setFromCountry(const std::string& fromCountry) { this->fromCountry = fromCountry; }
std::string InternationalPassengerVehicle::getFromCountry() const { return fromCountry; }
void InternationalPassengerVehicle::setToCountry(const std::string& toCountry) { this->toCountry = toCountry; }
std::string InternationalPassengerVehicle::getToCountry() const { return toCountry; }
void InternationalPassengerVehicle::setTravelTime(int travelTime) { this->travelTime = travelTime; }
int InternationalPassengerVehicle::getTravelTime() const { return travelTime; }

void InternationalPassengerVehicle::show() const {
    PassengerVehicle::show();
    std::cout << std::setw(15) << std::left << "Из страны"
        << std::setw(15) << "В страну"
        << std::setw(15) << "Время в пути" << std::endl;
}

InternationalPassengerVehicle& InternationalPassengerVehicle::operator=(const InternationalPassengerVehicle& other) {
    if (this != &other) {
        PassengerVehicle::operator=(other);
        fromCountry = other.fromCountry;
        toCountry = other.toCountry;
        travelTime = other.travelTime;
    }
    return *this;
}

//std::string InternationalPassengerVehicle::getParameterByIndex(int index) const {
//    if (index == 8) return std::to_string(fromCountry);
//    if (index == 9) return std::to_string(toCountry);
//    if (index == 10) return std::to_string(travelTime);
//    return PassengerVehicle::getParameterByIndex(index);
//}

std::ostream& operator<<(std::ostream& out, InternationalPassengerVehicle& vehicle) {
    out << dynamic_cast<PassengerVehicle&>(vehicle);
    out << std::setw(15) << std::left << vehicle.getFromCountry() << std::setw(15) << vehicle.getToCountry() << std::setw(15) << vehicle.getTravelTime() << std::endl;
    return out;
}

std::istream& operator>>(std::istream& in, InternationalPassengerVehicle& vehicle) {
    in >> dynamic_cast<PassengerVehicle&>(vehicle);
    std::cout << "Введите страну отправления: ";
    in >> vehicle.fromCountry;
    std::cout << "Введите страну назначения: ";
    in >> vehicle.toCountry;
    std::cout << "Введите время в пути (в часах): ";
    in >> vehicle.travelTime;
    return in;
}

InternationalPassengerVehicle::~InternationalPassengerVehicle() {
 //   std::cout << "Деструктор IntercityPassengerVehicle\n";
}