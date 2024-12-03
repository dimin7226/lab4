#include "TransportVehicle.h"


TransportVehicle::TransportVehicle()
    : color("Unknown"), brand("Unknown"), model("Unknown"),
    year(0), horsepower(0), engineType("Unknown"), id(++counter) {}

TransportVehicle::TransportVehicle(const std::string& color, const std::string& brand, const std::string& model,
    int year, int horsepower, const std::string& engineType)
    : color(color), brand(brand), model(model), year(year),
    horsepower(horsepower), engineType(engineType), id(++counter) {}

// �������
void TransportVehicle::setColor(const std::string& color) { this->color = color; }
void TransportVehicle::setBrand(const std::string& brand) { this->brand = brand; }
void TransportVehicle::setModel(const std::string& model) { this->model = model; }
void TransportVehicle::setYear(int year) { this->year = year; }
void TransportVehicle::setHorsepower(int horsepower) { this->horsepower = horsepower; }
void TransportVehicle::setEngineType(const std::string& engineType) { this->engineType = engineType; }
// �������
std::string TransportVehicle::getColor() const { return color; }
std::string TransportVehicle::getBrand() const { return brand; }
std::string TransportVehicle::getModel() const { return model; }
int TransportVehicle::getYear() const { return year; }
int TransportVehicle::getHorsepower() const { return horsepower; }
std::string TransportVehicle::getEngineType() const { return engineType; }
int TransportVehicle::getId() const { return id; }
std::string TransportVehicle::getCategory() const {return "������������ �������";}

int TransportVehicle::counter = 0;

void TransportVehicle::show() const {
    std::cout << std::setw(5) << std::left 
        << "�" << std::setw(5)
        << "ID" << std::setw(10)
        << "����" << std::setw(10)
        << "�����" << std::setw(10)
        << "������" << std::setw(15)
        << "��� �������" << std::setw(20)
        << "��������� ����" << std::setw(25)
        << "��� ���������";
}

void TransportVehicle::print(std::ostream& out) const {
    out << std::setw(5) << std::left << getId()
        << std::setw(10) << getColor()
        << std::setw(10) << getBrand()
        << std::setw(10) << getModel()
        << std::setw(15) << getYear()
        << std::setw(20) << getHorsepower()
        << std::setw(25) << getEngineType();
}

TransportVehicle& TransportVehicle::operator=(const TransportVehicle& other) {
    if (this != &other) {
        id = other.id;
        color = other.color;
        brand = other.brand;
        model = other.model;
        year = other.year;
        horsepower = other.horsepower;
        engineType = other.engineType;
    }
    return *this;
}


std::istream& operator>>(std::istream& in, TransportVehicle& vehicle) {
    std::cout << "������� ����: ";
    in >> vehicle.color;
    std::cout << "������� �����: ";
    in >> vehicle.brand;
    std::cout << "������� ������: ";
    in >> vehicle.model;
    std::cout << "������� ��� �������: ";
    in >> vehicle.year;
    std::cout << "������� ���������� ��������� ���: ";
    in >> vehicle.horsepower;
    
    int engineChoice = 0;
    bool validChoice = false;
    while (!validChoice) {
        std::cout << "�������� ��� ���������:\n";
        std::cout << "1 - �������������\n";
        std::cout << "2 - ����������� ��������\n";
        std::cout << "3 - ���������\n";
        std::cout << "������� ����� ���� ���������: ";
        in >> engineChoice;
        switch (engineChoice) {
        case 1:
            vehicle.engineType = "�������������";
            validChoice = true;
            break;
        case 2:
            vehicle.engineType = "����������� ��������";
            validChoice = true;
            break;
        case 3:
            vehicle.engineType = "���������";
            validChoice = true;
            break;
        default:
            std::cout << "�������� �����. ���������� �����.\n";
            break;
        }
    }
    return in;
}

TransportVehicle::~TransportVehicle() {
  // std::cout << "���������� TransportVehicle\n";
}