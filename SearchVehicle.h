#ifndef SEARCH_VEHICLE_H
#define SEARCH_VEHICLE_H

#include <iostream>
#include <string>
#include "Stack.h"

template <typename T>
void searchVehicle(stack<T>& vehicleStack) {
    std::string color, brand, model, engineType;
    int year = -1, horsepower = -1;
    std::cout << "������� ��������� ������ (�������� ������ ��� ��������):\n";
    std::cout << "����: ";
    std::cin.ignore(); // ������� ������
    std::getline(std::cin, color);
    std::cout << "�����: ";
    std::getline(std::cin, brand);
    std::cout << "������: ";
    std::getline(std::cin, model);
    std::cout << "��� �������: ";
    std::cin >> year;
    std::cout << "��������� ����: ";
    std::cin >> horsepower;
    std::cout << "��� ���������: ";
    std::cin.ignore(); // ������� ������
    std::getline(std::cin, engineType);
    vehicleStack.searchAndShow(color, brand, model, year, horsepower, engineType);
}

#endif // SEARCH_VEHICLE_H