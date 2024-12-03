#pragma once
#include "CargoVehicle.h"
#include "DumpTruck.h"

DumpTruck::DumpTruck() : loadVolume(0.0) {
  //  std::cout << "Конструктор DumpTruck\n";
}
DumpTruck::DumpTruck(const std::string& color, const std::string& brand, const std::string& model,
    int year, int horsepower, const std::string& engineType, double maxCargoWeight,
    double loadVolume)
    : CargoVehicle(color, brand, model, year, horsepower, engineType, maxCargoWeight), loadVolume(loadVolume) {
    //std::cout << "Конструктор DumpTruck с параметрами\n";
}
//Сеттер, геттер
void DumpTruck::setLoadVolume(double  loadVolume) { this->loadVolume = loadVolume; }
double DumpTruck::getLoadVolume() const { return loadVolume; }
std::string DumpTruck::getCategory() const { return "Самосвалы"; }

void DumpTruck::show() const {
    CargoVehicle::show();
    std::cout << std::setw(sizeof(getLoadVolume())/sizeof(double) + 5) << std::left << "Объем кузова" << std::endl;
}

DumpTruck& DumpTruck::operator=(const DumpTruck& other) {
    if (this != &other) {
        CargoVehicle::operator=(other);
        loadVolume = other.loadVolume;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& out, DumpTruck& vehicle) {
    out << dynamic_cast<CargoVehicle&>(vehicle);
    out << std::setw(sizeof(vehicle.getLoadVolume()) / sizeof(double) + 5) << std::left << vehicle.getLoadVolume() << std::endl;
    return out;
}

//std::string DumpTruck::getParameterByIndex(int index) const {
//    if (index == 8) return std::to_string(loadVolume);
//    return TransportVehicle::getParameterByIndex(index);
//}

std::istream& operator>>(std::istream& in, DumpTruck& vehicle) {
    in >> dynamic_cast<CargoVehicle&>(vehicle);
    std::cout << "Введите объем кузова (м3): ";
    in >> vehicle.loadVolume;
    return in;
}

void DumpTruck::print(std::ostream& out) const {
    CargoVehicle::print(out);
    out << std::setw(20) << getLoadVolume();
}

DumpTruck::~DumpTruck() {
   // std::cout << "Деструктор DumpTruck\n";
}