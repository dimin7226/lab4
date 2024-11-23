#pragma once
#include "Car.h"
#include "Jeep.h"

Jeep::Jeep() : clearance(0.0) {
  //  std::cout << "Конструктор Jeep\n";
}

Jeep::Jeep(const std::string& color, const std::string& brand, const std::string& model,
    int year, int horsepower, const std::string& engineType, double weight, int numberOfDoors,
    double clearance)
    : Car(color, brand, model, year, horsepower, engineType, weight, numberOfDoors), clearance(clearance) {
  //  std::cout << "Конструктор Jeep с параметрами\n";
}

//Сеттер, геттер
void Jeep::setClearance(double  clearance) { this->clearance = clearance; }
double Jeep::getClearance() const { return clearance; }

void Jeep::show() const {
    Car::show();
    std::cout << std::setw(15) << std::left << "Клиренс (см)" << std::endl;
}

Jeep& Jeep::operator=(const Jeep& other) {
    if (this != &other) {
        Car::operator=(other);
        clearance = other.clearance;
    }
    return *this;
}


std::ostream& operator<<(std::ostream& out, Jeep& vehicle) {
    out << dynamic_cast<Car&>(vehicle);
    out << std::setw(15) << std::left << vehicle.getClearance() << std::endl;
    return out;
}

std::istream& operator>>(std::istream& in, Jeep& vehicle) {
    in >> dynamic_cast<Car&>(vehicle);
    std::cout << "Введите клиренс (см): ";
    in >> vehicle.clearance;
    return in;
}

Jeep::~Jeep() {
  //  std::cout << "Деструктор Jeep\n";
}
