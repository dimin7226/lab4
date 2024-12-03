#ifndef SEARCH_VEHICLE_H
#define SEARCH_VEHICLE_H

#include <iostream>
#include <string>
#include "Stack.h"

template <typename T>
void searchVehicle(stack<T>& vehicleStack) {
    std::string color, brand, model, engineType;
    int year = -1, horsepower = -1;
    std::cout << "Введите параметры поиска (оставьте пустым для пропуска):\n";
    std::cout << "Цвет: ";
    std::cin.ignore(); // Очистка буфера
    std::getline(std::cin, color);
    std::cout << "Бренд: ";
    std::getline(std::cin, brand);
    std::cout << "Модель: ";
    std::getline(std::cin, model);
    std::cout << "Год выпуска: ";
    std::cin >> year;
    std::cout << "Лошадиные силы: ";
    std::cin >> horsepower;
    std::cout << "Тип двигателя: ";
    std::cin.ignore(); // Очистка буфера
    std::getline(std::cin, engineType);
    vehicleStack.searchAndShow(color, brand, model, year, horsepower, engineType);
}

#endif // SEARCH_VEHICLE_H