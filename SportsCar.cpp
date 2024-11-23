#pragma once
#include "Car.h"
#include "SportsCar.h"

SportsCar::SportsCar() : maxSpeed(0.0), accelerationTime(0.0) {
  //  std::cout << "����������� SportsCar\n";
}

SportsCar::SportsCar(const std::string& color, const std::string& brand, const std::string& model,
    int year, int horsepower, const std::string& engineType, double weight, int numberOfDoors,
    double maxSpeed, double accelerationTime)
    : Car(color, brand, model, year, horsepower, engineType, weight, numberOfDoors),
    maxSpeed(maxSpeed), accelerationTime(accelerationTime) {
 //   std::cout << "����������� SportsCar � �����������\n";
}

// ������� � �������
void SportsCar::setMaxSpeed(double maxSpeed) { this->maxSpeed = maxSpeed; }
double SportsCar::getMaxSpeed() const { return maxSpeed; }
void SportsCar::setAccelerationTime(double accelerationTime) { this->accelerationTime = accelerationTime; }
double SportsCar::getAccelerationTime() const { return accelerationTime; }

void SportsCar::show() const {
    Car::show();
    std::cout << std::setw(20) << std::left << "����. ��������" 
        << std::setw(25) << "������ 0-100 ��/� (���)" << std::endl;
}

SportsCar& SportsCar::operator=(const SportsCar& other) {
    if (this != &other) {
        Car::operator=(other);
        maxSpeed = other.maxSpeed;
        accelerationTime = other.accelerationTime;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& out, SportsCar& vehicle) {
    out << dynamic_cast<Car&>(vehicle);
    out << std::setw(20) << std::left << vehicle.getMaxSpeed() 
        << std::setw(25) << vehicle.getAccelerationTime() << std::endl;
    return out;
}

std::istream& operator>>(std::istream& in, SportsCar& vehicle) {
    in >> dynamic_cast<Car&>(vehicle);
    std::cout << "������� ������������ �������� (��/�): ";
    in >>  vehicle.maxSpeed;
    std::cout << "������� ����� ������� 0-100 ��/� (� ��������): ";
    in >> vehicle.accelerationTime;
    return in;
}

SportsCar::~SportsCar() {
  //  std::cout << "���������� SportsCar\n";
}