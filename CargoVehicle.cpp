#pragma once
#include "TransportVehicle.h"
#include "RefrigeratedCargoVehicle.h"
#include "DumpTruck.h"
#include "CargoVehicle.h"

CargoVehicle::CargoVehicle() : maxCargoWeight(0.0) {
  //  std::cout << "Конструктор CargoVehicle\n";
}
CargoVehicle::CargoVehicle(const std::string& color, const std::string& brand, const std::string& model,
    int year, int horsepower, const std::string& engineType, double maxCargoWeight)
    : TransportVehicle(color, brand, model, year, horsepower, engineType), maxCargoWeight(maxCargoWeight) {
   // std::cout << "Конструктор CargoVehicle с параметрами\n";
}
// Сеттер и геттер
void CargoVehicle::setMaxWeight(double  maxCargoWeight) { this->maxCargoWeight = maxCargoWeight; }
double CargoVehicle::getMaxWeight() const { return maxCargoWeight; }

void CargoVehicle::show() const {
    TransportVehicle::show();
    std::cout << std::setw(35) << std::left << "Максимальная масса груза (кг)" << std::endl;
}

CargoVehicle& CargoVehicle::operator=(const CargoVehicle& other) {
    if (this != &other) {
        TransportVehicle::operator=(other);
        maxCargoWeight = other.maxCargoWeight;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& out, CargoVehicle& vehicle) {
    out << dynamic_cast<TransportVehicle&>(vehicle);
    out << std::setw(35) << std::left << vehicle.getMaxWeight();
    return out;
}

//std::string CargoVehicle::getParameterByIndex(int index) const {
//    if (index == 7) return std::to_string(maxCargoWeight);
//    return TransportVehicle::getParameterByIndex(index);
//}

std::istream& operator>>(std::istream& in, CargoVehicle& vehicle) {
    in >> dynamic_cast<TransportVehicle&>(vehicle);
    std::cout << "Введите максимальную массу груза (кг): ";
    in >> vehicle.maxCargoWeight;
    return in;
}

CargoVehicle::~CargoVehicle() {
 //   std::cout << "Деструктор CargoVehicle\n";
}
