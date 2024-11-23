#pragma once 
#include <map>
#include <iostream>
#include <iomanip>
#include <string>

class TransportVehicle {
protected:
    std::string color;
    std::string brand;
    std::string model;
    int year;
    int horsepower;
    std::string engineType;
    static int counter;  // Статическая переменная для подсчета
    int id;              // Идентификатор объекта
public:
    TransportVehicle();
    TransportVehicle(const std::string& color, const std::string& brand, const std::string& model,
        int year, int horsepower, const std::string& engineType);
    // Сеттеры
    void setColor(const std::string& color);
    void setBrand(const std::string& brand);
    void setModel(const std::string& model);
    void setYear(int year);
    void setHorsepower(int horsepower);
    void setEngineType(const std::string& engineType);
    // Геттеры
    std::string getColor() const;
    std::string getBrand() const;
    std::string getModel() const;
    int getYear() const;
    int getHorsepower() const;
    int getId() const;
    std::string getEngineType() const;
    virtual void show() const;
    TransportVehicle& operator=(const TransportVehicle& other);
    friend std::ostream& operator<<(std::ostream& os, TransportVehicle& vehicle);
    friend std::istream& operator>>(std::istream& is, TransportVehicle& vehicle);
    virtual ~TransportVehicle();
};
