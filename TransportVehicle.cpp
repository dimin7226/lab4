#include "TransportVehicle.h"


TransportVehicle::TransportVehicle()
    : color("Unknown"), brand("Unknown"), model("Unknown"),
    year(0), horsepower(0), engineType("Unknown"), id(++counter) {}

TransportVehicle::TransportVehicle(const std::string& color, const std::string& brand, const std::string& model,
    int year, int horsepower, const std::string& engineType)
    : color(color), brand(brand), model(model), year(year),
    horsepower(horsepower), engineType(engineType), id(++counter) {}

// Сеттеры
void TransportVehicle::setColor(const std::string& color) { this->color = color; }
void TransportVehicle::setBrand(const std::string& brand) { this->brand = brand; }
void TransportVehicle::setModel(const std::string& model) { this->model = model; }
void TransportVehicle::setYear(int year) { this->year = year; }
void TransportVehicle::setHorsepower(int horsepower) { this->horsepower = horsepower; }
void TransportVehicle::setEngineType(const std::string& engineType) { this->engineType = engineType; }
// Геттеры
std::string TransportVehicle::getColor() const { return color; }
std::string TransportVehicle::getBrand() const { return brand; }
std::string TransportVehicle::getModel() const { return model; }
int TransportVehicle::getYear() const { return year; }
int TransportVehicle::getHorsepower() const { return horsepower; }
std::string TransportVehicle::getEngineType() const { return engineType; }
int TransportVehicle::getId() const { return id; }
std::string TransportVehicle::getCategory() const {return "Транспортные средста";}

int TransportVehicle::counter = 0;

void TransportVehicle::show() const {
    std::cout << std::setw(5) << std::left 
        << "№" << std::setw(5)
        << "ID" << std::setw(10)
        << "Цвет" << std::setw(10)
        << "Бренд" << std::setw(10)
        << "Модель" << std::setw(15)
        << "Год выпуска" << std::setw(20)
        << "Лошадиные силы" << std::setw(25)
        << "Тип двигателя";
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
    std::cout << "Введите цвет: ";
    in >> vehicle.color;
    std::cout << "Введите бренд: ";
    in >> vehicle.brand;
    std::cout << "Введите модель: ";
    in >> vehicle.model;
    std::cout << "Введите год выпуска: ";
    in >> vehicle.year;
    std::cout << "Введите количество лошадиных сил: ";
    in >> vehicle.horsepower;
    
    int engineChoice = 0;
    bool validChoice = false;
    while (!validChoice) {
        std::cout << "Выберите тип двигателя:\n";
        std::cout << "1 - Электрический\n";
        std::cout << "2 - Внутреннего сгорания\n";
        std::cout << "3 - Гибридный\n";
        std::cout << "Введите номер типа двигателя: ";
        in >> engineChoice;
        switch (engineChoice) {
        case 1:
            vehicle.engineType = "Электрический";
            validChoice = true;
            break;
        case 2:
            vehicle.engineType = "Внутреннего сгорания";
            validChoice = true;
            break;
        case 3:
            vehicle.engineType = "Гибридный";
            validChoice = true;
            break;
        default:
            std::cout << "Неверный выбор. Попробуйте снова.\n";
            break;
        }
    }
    return in;
}

TransportVehicle::~TransportVehicle() {
  // std::cout << "Деструктор TransportVehicle\n";
}