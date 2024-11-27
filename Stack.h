#pragma once 
#include <iostream>
#include <vector>
#include "Car.h"
#include "CargoVehicle.h"
#include "PassengerVehicle.h"
#include "Jeep.h"
#include "Limousine.h"
#include "RefrigeratedCargoVehicle.h"
#include "SportsCar.h"

template <class T>
class stack {
	struct item {
		T i;
		item* next;
	};
	item* head;
public:
	void push(T);
	void pop();
	T pop1();
	stack();
	~stack();
    void searchAndShow(const std::string& color = "", const std::string& brand = "", const std::string& model = "",
        int year = -1, int horsepower = -1, const std::string& engineType = "",
        double weight = -1.0, int numberOfDoors = -1, double maxCargoWeight = -1.0,
        int passengerSeats = -1, double clearance = -1.0, double length = -1.0,
        double minTemperature = -1.0, double maxSpeed = -1.0, double accelerationTime = -1.0) {
        if (head == NULL) {
            std::cout << "Стек пуст" << std::endl;
            return;
        }

        std::vector<T> results;
        item* p = head;
        while (p != NULL) {
            bool match = true;
            if (!color.empty() && p->i.getColor() != color) match = false;
            if (!brand.empty() && p->i.getBrand() != brand) match = false;
            if (!model.empty() && p->i.getModel() != model) match = false;
            if (year != -1 && p->i.getYear() != year) match = false;
            if (horsepower != -1 && p->i.getHorsepower() != horsepower) match = false;
            if (!engineType.empty() && p->i.getEngineType() != engineType) match = false;

            // Проверка уникальных полей для Car
            if (Car* car = dynamic_cast<Car*>(&p->i)) {
                if (weight != -1.0 && car->getWightCar() != weight) match = false;
                if (numberOfDoors != -1 && car->getNumberOfDoors() != numberOfDoors) match = false;
            }

            // Проверка уникальных полей для CargoVehicle
            if (CargoVehicle* cargo = dynamic_cast<CargoVehicle*>(&p->i)) {
                if (maxCargoWeight != -1.0 && cargo->getMaxWeight() != maxCargoWeight) match = false;
            }

            // Проверка уникальных полей для PassengerVehicle
            if (PassengerVehicle* passenger = dynamic_cast<PassengerVehicle*>(&p->i)) {
                if (passengerSeats != -1 && passenger->getPassengerSeats() != passengerSeats) match = false;
            }

            // Проверка уникальных полей для Jeep
            if (Jeep* jeep = dynamic_cast<Jeep*>(&p->i)) {
                if (clearance != -1.0 && jeep->getClearance() != clearance) match = false;
            }

            // Проверка уникальных полей для Limousine
            if (Limousine* limo = dynamic_cast<Limousine*>(&p->i)) {
                if (length != -1.0 && limo->getLength() != length) match = false;
            }

            // Проверка уникальных полей для RefrigeratedCargoVehicle
            if (RefrigeratedCargoVehicle* refrigerated = dynamic_cast<RefrigeratedCargoVehicle*>(&p->i)) {
                if (minTemperature != -1.0 && refrigerated->getMinTemperature() != minTemperature) match = false;
            }

            // Проверка уникальных полей для SportsCar
            if (SportsCar* sports = dynamic_cast<SportsCar*>(&p->i)) {
                if (maxSpeed != -1.0 && sports->getMaxSpeed() != maxSpeed) match = false;
                if (accelerationTime != -1.0 && sports->getAccelerationTime() != accelerationTime) match = false;
            }

            if (match) {
                results.push_back(p->i);
            }
            p = p->next;
        }

        if (results.empty()) {
            std::cout << "Нет результатов, соответствующих критериям поиска." << std::endl;
        }
        else {
            results[0].show(); // Печать заголовка таблицы
            std::cout << std::endl;
            for (size_t i = 0; i < results.size(); ++i) {
                std::cout << std::setw(5) << i + 1 << results[i] << std::endl;
            }
        }
    }
	void show();
	void clear();
	void removeAt(int index);
	bool empty();
};

