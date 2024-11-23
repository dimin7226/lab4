#pragma once
#include "PassengerVehicle.h"
#include "IntercityPassengerVehicle.h"

IntercityPassengerVehicle::IntercityPassengerVehicle() : routeLength(0.0) {}

IntercityPassengerVehicle::IntercityPassengerVehicle(const std::string& color, const std::string& brand, const std::string& model,
    int year, int horsepower, const std::string& engineType, int passengerSeats,
    const std::string& fromCity, const std::string& toCity, double routeLength)
    : PassengerVehicle(color, brand, model, year, horsepower, engineType, passengerSeats),
    fromCity(fromCity), toCity(toCity), routeLength(routeLength) {
   // std::cout << "Конструктор IntercityPassengerVehicle с параметрами\n";
}

// Геттеры и сеттеры
void IntercityPassengerVehicle::setFromCity(const std::string& fromCity) { this->fromCity = fromCity; }
std::string IntercityPassengerVehicle::getFromCity() const { return fromCity; }
void IntercityPassengerVehicle::setToCity(const std::string& toCity) { this->toCity = toCity; }
std::string IntercityPassengerVehicle::getToCity() const { return toCity; }
void IntercityPassengerVehicle::setRouteLength(double routeLength) { this->routeLength = routeLength; }
double IntercityPassengerVehicle::getRouteLength() const { return routeLength; }

void IntercityPassengerVehicle::show() const {
    PassengerVehicle::show();
    std::cout << std::setw(15) << std::left << "Из города" 
        << std::setw(15) << "В город" 
        << std::setw(15) << "Длина маршрута" << std::endl;
}

//std::string IntercityPassengerVehicle::getParameterByIndex(int index) const {
//    if (index == 8) return std::to_string(fromCity);
//    else if (index == 9) return std::to_string(toCity);
//    else if (index == 10) return std::to_string(routeLength);
//    return TransportVehicle::getParameterByIndex(index);
//}

IntercityPassengerVehicle& IntercityPassengerVehicle::operator=(const IntercityPassengerVehicle& other) {
    if (this != &other) {
        PassengerVehicle::operator=(other);
        fromCity = other.fromCity;
        toCity = other.toCity;
        routeLength = other.routeLength;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& out, IntercityPassengerVehicle& vehicle) {
    out << dynamic_cast<PassengerVehicle&>(vehicle);
    out << std::setw(15) << std::left << vehicle.getFromCity() << std::setw(15) << vehicle.getToCity() << std::setw(15) << vehicle.getRouteLength() << std::endl;
    return out;
}

std::istream& operator>>(std::istream& in, IntercityPassengerVehicle& vehicle) {
    in >> dynamic_cast<PassengerVehicle&>(vehicle);
    std::cout << "Введите город отправления: ";
    in >> vehicle.fromCity;
    std::cout << "Введите город назначения: ";
    in >> vehicle.toCity;
    std::cout << "Введите длину маршрута (в км): ";
    in >> vehicle.routeLength;
    return in;
}

IntercityPassengerVehicle::~IntercityPassengerVehicle() {
  //  std::cout << "Деструктор IntercityPassengerVehicle\n";
}
