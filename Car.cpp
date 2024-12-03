#pragma once
#include "TransportVehicle.h"
#include "Car.h"

Car::Car() : weight(0.0), numberOfDoors(0) {
   // std::cout << "����������� Car\n";
}
Car::Car(const std::string& color, const std::string& brand, const std::string& model,
    int year, int horsepower, const std::string& engineType, double weight, int numberOfDoors)
    : TransportVehicle(color, brand, model, year, horsepower, engineType), weight(weight), numberOfDoors(numberOfDoors) {
   // std::cout << "����������� Car � �����������\n";
}
// ������� � �������
void Car::setWeightCar(double  weight) { this->weight = weight; }
double Car::getWightCar() const { return weight; }
void Car::setNumberOfDoors(int numberOfDoors) { this->numberOfDoors = numberOfDoors; }
int Car::getNumberOfDoors() const { return numberOfDoors; }
std::string Car::getCategory() const { return "�������� ������"; }

void Car::show() const {
    TransportVehicle::show();
    std::cout << std::setw(25) << std::left << "����� ����������(��)" << std::setw(20)
        << "���������� ������" << std::setw(8);
}

Car& Car::operator=(const Car& other) {
    if (this != &other) {
        TransportVehicle::operator=(other);
        weight = other.weight;
        numberOfDoors = other.numberOfDoors;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& out, Car& vehicle) {
    out << dynamic_cast<TransportVehicle&>(vehicle);
    out << std::setw(25) << std::left << vehicle.getWightCar() << std::setw(20) << vehicle.getNumberOfDoors();
    return out;
}

std::istream& operator>>(std::istream& in, Car& vehicle) {
    in >> dynamic_cast<TransportVehicle&>(vehicle);
    std::cout << "������� ����� ����������: ";
    in >> vehicle.weight;
    std::cout << "������� ���������� ������: ";
    in >> vehicle.numberOfDoors;
    return in;
}

void Car::print(std::ostream& out) const {
    TransportVehicle::print(out);
    out << std::setw(25) << getWightCar()
        << std::setw(20) << getNumberOfDoors();
}

Car::~Car() {
  //  std::cout << "���������� Car\n";
}
