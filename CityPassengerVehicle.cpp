#pragma once
#include "PassengerVehicle.h"
#include "CityPassengerVehicle.h"

CityPassengerVehicle::CityPassengerVehicle() : routeNumber(0), numberOfStops(0) {
   // std::cout << "Конструктор CityPassengerVehicle\n";
}

CityPassengerVehicle::CityPassengerVehicle(const std::string& color, const std::string& brand, const std::string& model,
    int year, int horsepower, const std::string& engineType, int passengerSeats,
    int routeNumber, int numberOfStops)
    : PassengerVehicle(color, brand, model, year, horsepower, engineType, passengerSeats),
    routeNumber(routeNumber), numberOfStops(numberOfStops) {
   // std::cout << "Конструктор CityPassengerVehicle с параметрами\n";
}

// Геттеры и сеттеры
void CityPassengerVehicle::setRouteNumber(int routeNumber) { this->routeNumber = routeNumber; }
int CityPassengerVehicle::getRouteNumber() const { return routeNumber; }
void CityPassengerVehicle::setNumberOfStops(int numberOfStops) { this->numberOfStops = numberOfStops; }
int CityPassengerVehicle::getNumberOfStops() const { return numberOfStops; };

void CityPassengerVehicle::show() const {
    PassengerVehicle::show();
    std::cout << std::setw(20) << std::left << "Номер маршрута" << std::setw(30)
        << "Количество остановок" << std::endl;
}

//std::string CityPassengerVehicle::getParameterByIndex(int index) const {
//    if (index == 8) return std::to_string(routeNumber);
//    if (index == 9) return std::to_string(numberOfStops);
//    return TransportVehicle::getParameterByIndex(index);
//}

CityPassengerVehicle& CityPassengerVehicle::operator=(const CityPassengerVehicle& other) {
    if (this != &other) {
        PassengerVehicle::operator=(other);
        routeNumber = other.routeNumber;
        numberOfStops = other.numberOfStops;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& out, CityPassengerVehicle& vehicle) {
    out << dynamic_cast<PassengerVehicle&>(vehicle);
    out << std::setw(20) << std::left << vehicle.getRouteNumber() << std::setw(30) << vehicle.getNumberOfStops() << std::endl;
    return out;
}

std::istream& operator>>(std::istream& in, CityPassengerVehicle& vehicle) {
    in >> dynamic_cast<PassengerVehicle&>(vehicle);
    std::cout << "Введите номер маршрута: ";
    in >> vehicle.routeNumber;
    std::cout << "Введите количество остановок: ";
    in >> vehicle.numberOfStops;
    return in;
}

CityPassengerVehicle::~CityPassengerVehicle() {
   // std::cout << "Деструктор CityPassengerVehicle\n";
}