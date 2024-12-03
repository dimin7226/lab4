#pragma once
#include "Car.h"
#include "Limousine.h"

Limousine::Limousine() : length(0.0) {
   // std::cout << "Конструктор Limousine\n";
}

Limousine::Limousine(const std::string& color, const std::string& brand, const std::string& model,
    int year, int horsepower, const std::string& engineType, double weight, int numberOfDoors,
    double length)
    : Car(color, brand, model, year, horsepower, engineType, weight, numberOfDoors), length(length) {
  //  std::cout << "Конструктор Limousine с параметрами\n";
}

// Сеттер и геттер
void Limousine::setLength(double length) { this->length = length; }
double Limousine::getLength() const { return length; }
std::string Limousine::getCategory() const { return "Лимузины"; }

void Limousine::show() const {
    Car::show();
    std::cout << std::setw(20) << std::left << "Длина автомобиля" << std::endl;
}

Limousine& Limousine::operator=(const Limousine& other) {
    if (this != &other) {
        Car::operator=(other);
        length = other.length;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& out, Limousine& vehicle) {
    out << dynamic_cast<Car&>(vehicle);
    out << std::setw(20) << std::left << vehicle.getLength() << std::endl;
    return out;
}

std::istream& operator>>(std::istream& in, Limousine& vehicle) {
    in >> dynamic_cast<Car&>(vehicle);
    std::cout << "Введите длину автомобиля: ";
    in >> vehicle.length;
    return in;
}

void Limousine::print(std::ostream& out) const {
    Car::print(out);
    out << std::setw(20) << getLength();
}

Limousine::~Limousine() {
    //std::cout << "Деструктор Limousine\n";
}
