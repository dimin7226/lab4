#pragma once
#include "TransportVehicle.h"
#include "PassengerVehicle.h"
PassengerVehicle::PassengerVehicle() : passengerSeats(0) {
  //  std::cout << "����������� PassengerVehicle\n";
}

PassengerVehicle::PassengerVehicle(const std::string& color, const std::string& brand, const std::string& model,
    int year, int horsepower, const std::string& engineType, int passengerSeats)
    : TransportVehicle(color, brand, model, year, horsepower, engineType), passengerSeats(passengerSeats) {
   // std::cout << "����������� PassengerVehicle � �����������\n";
}

// ������ � ������
void PassengerVehicle::setPassengerSeats(int passengerSeats) { this->passengerSeats = passengerSeats; }
int PassengerVehicle::getPassengerSeats() const { return passengerSeats; }

void PassengerVehicle::show() const {
    TransportVehicle::show();
    std::cout << std::setw(20) << std::left << "���������� ����";
}

//std::string PassengerVehicle::getParameterByIndex(int index) const {
//    if (index == 7) return std::to_string(passengerSeats);
//    return TransportVehicle::getParameterByIndex(index);
//}


PassengerVehicle& PassengerVehicle::operator=(const PassengerVehicle& other) {
    if (this != &other) {
        TransportVehicle::operator=(other);
        passengerSeats = other.passengerSeats;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& out, PassengerVehicle& vehicle) {
    out << dynamic_cast<TransportVehicle&>(vehicle);
    out << std::setw(20) << std::left << vehicle.getPassengerSeats();
    return out;
}

std::istream& operator>>(std::istream& in, PassengerVehicle& vehicle) {
    in >> dynamic_cast<TransportVehicle&>(vehicle);
    std::cout << "������� ���������� ������������ ����: ";
    in >> vehicle.passengerSeats;
    return in;
}

PassengerVehicle::~PassengerVehicle() {
  //  std::cout << "���������� PassengerVehicle\n";
}