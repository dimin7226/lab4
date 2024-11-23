#pragma once
#include "CargoVehicle.h"
#include "RefrigeratedCargoVehicle.h"

RefrigeratedCargoVehicle::RefrigeratedCargoVehicle() : minTemperature(0.0) {
  //  std::cout << "Конструктор RefrigeratedCargoVehicle\n";
}

RefrigeratedCargoVehicle::RefrigeratedCargoVehicle(const std::string& color, const std::string& brand, const std::string& model,
    int year, int horsepower, const std::string& engineType, double maxCargoWeight,
    double minTemperature)
    : CargoVehicle(color, brand, model, year, horsepower, engineType, maxCargoWeight), minTemperature(minTemperature) {
  //  std::cout << "Конструктор RefrigeratedCargoVehicle с параметрами\n";
}

// Сеттеры и геттеры
void RefrigeratedCargoVehicle::setMinTemperature(double minTemperature) { this->minTemperature = minTemperature; }
double RefrigeratedCargoVehicle::getMinTemperature() const { return minTemperature; }

void RefrigeratedCargoVehicle::show() const {
    CargoVehicle::show();
    std::cout << std::setw(30) << std::left << "Минимальная температура" << std::endl;
}

RefrigeratedCargoVehicle& RefrigeratedCargoVehicle::operator=(const RefrigeratedCargoVehicle& other) {
    if (this != &other) {
        CargoVehicle::operator=(other);
        minTemperature = other.minTemperature;
    }
    return *this;
}

//std::string RefrigeratedCargoVehicle::getParameterByIndex(int index) const {
//    if (index == 8) return std::to_string(minTemperature);
//    return TransportVehicle::getParameterByIndex(index);
//}

std::ostream& operator<<(std::ostream& out, RefrigeratedCargoVehicle& vehicle) {
    out << dynamic_cast<CargoVehicle&>(vehicle);
    out << std::setw(30) << std::left << vehicle.getMinTemperature() << std::endl;
    return out;
}

std::istream& operator>>(std::istream& in, RefrigeratedCargoVehicle& vehicle) {
    in >> dynamic_cast<CargoVehicle&>(vehicle);
    std::cout << "Введите минимальную температуру: ";
    in >> vehicle.minTemperature;
    return in;
}

RefrigeratedCargoVehicle::~RefrigeratedCargoVehicle() {
  //  std::cout << "Деструктор RefrigeratedCargoVehicle\n";
}