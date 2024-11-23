#include<vector>
#include "Stack.h"
#include "RefrigeratedCargoVehicle.h"
#include "CargoVehicle.h"
#include "DumpTruck.h"
#include "IntercityPassengerVehicle.h"
#include "CityPassengerVehicle.h"
#include "InternationalPassengerVehicle.h"
#include "Jeep.h"
#include "Limousine.h"
#include "SportsCar.h"
#include "Interface.h"
template <class T>
void Interface<T>::menu() {
    stack<T> st;
    T value;
    char selection;
    bool flag = true; // ���������� ������
    do {
        std::cout << "1. �������� ������� �����" << std::endl;
        std::cout << "2. �������� ����" << std::endl;
        std::cout << "3. ������� ������� �����" << std::endl;
        std::cout << "4. ���������� �������� ����" << std::endl;
        std::cout << "5. ������� ��� �������� �����" << std::endl;
        std::cout << "6. ������� ������� �� ������ �" << std::endl;
        std::cout << "7. �����" << std::endl;
        std::cout << "������� �����: ";
        rewind(stdin);
        std::cin >> selection;
        while (std::cin.get() != '\n'); // ������� ��� ������� �� ������ ����� �� ����� ������
        switch (selection) {
        case '1': {
            T value;
            std::cin >> value;
            st.push(value);
            break;
        }
        case '2': {
            std::cout << "����� �����..." << std::endl;
            st.show(value);
            break;
        }
        case '3': {
            std::cout << "�������� �������� �����..." << std::endl;
            st.pop();
            break;
        }
        case '4': {
            std::cout << "��������� �������� ����..." << std::endl;
            st.show(value);
            int count;
            std::cout << "������� ���������� ���������� �� ������� ����� �����: ";
            rewind(stdin);
            std::cin >> count;
            std::vector<int> columns(count);
            std::cout << "������� ����� �������, ������� ������������� ���������, ������� �� ������ ��������: ";
            for (int i = 0; i < count; i++) std::cin >> columns[i];
            for (int i = 0; i < count; i++) {
                std::cout << columns[i] << " ";
            }
            rewind(stdin);
            std::cout << "������� ����� ��������: ";
            std::string value;
            std::cin >> value;
            /*
            code ...
            */
            break;
        }
        case '5': {
            std::cout << "�������� ���� ��������� �����..." << std::endl;
            st.clear();
            break;
        }
        case '6': {
            std::cout << "������� ����� � �������� �����: ";
            int index;
            std::cin >> index;
            st.removeAt(index - 1);
            break;
        }
        case '7': {
            std::cout << "����� �� ���� ������ �� ������..." << std::endl;
            flag = false;
            break;
        }
        default: {
            std::cout << "����������� ����. ����������, ���������� �����." << std::endl;
            break;
        }
        }
    } while (flag);
}

template <typename VehicleType>
void handleVehicle(const std::string& prompt, const std::vector<std::pair<int, VehicleType>>& options) {
    std::cout << prompt;
    int choice;
    rewind(stdin);
    std::cin >> choice;
    for (const auto& option : options) {
        if (option.first == choice) {
            Interface<VehicleType> vehicle;
            vehicle.menu();
            return;
        }
    }

    std::cout << "�������� �����. ����������, ���������� �����." << std::endl;
}

template <class T>
void Interface<T>::handleCar() {
    handleVehicle<Car>(
        "�������� ��� ��������� ������������� ��������:\n"
        "1. ��������\n"
        "2. �����������\n"
        "3. �������\n"
        "��� �����: ",
        {
        { 1, SportsCar{} },
        { 2, Jeep{} },
        { 3, Limousine{} }
        }
    );
}

template <class T>
void Interface<T>::handleCargoVehicle() {
    handleVehicle<CargoVehicle>(
        "�������� ��� ��������� ������������� ��������:\n"
        "1. ������������\n"
        "2. ��������\n"
        "��� �����: ",
        {
            {1, RefrigeratedCargoVehicle()},
            {2, DumpTruck()}
        }
    );
}

template <class T>
void Interface<T>::handlePassengerVehicle() {
    handleVehicle<PassengerVehicle>(
        "�������� ��� ������������� ������������� ��������:\n"
        "1. �������������\n"
        "2. ���������\n"
        "3. �������������\n"
        "��� �����: ",
        {
            {1, IntercityPassengerVehicle()},
            {2, CityPassengerVehicle()},
            {3, InternationalPassengerVehicle()}
        }
    );
}

template <class T>
void Interface<T>::displayMainMenu() const {
    std::cout << "�������� ������ � ������� ������ ��������:" << std::endl;
    std::cout << "1. �������� ������������ ��������" << std::endl;
    std::cout << "2. ������������ ������������ ��������" << std::endl;
    std::cout << "3. �������� ������������ ��������" << std::endl;
    std::cout << "0. �����" << std::endl;
    std::cout << "������� �����: ";
}

template <class T>
void Interface<T>::func() {
    int choice;
    do {
        displayMainMenu();
        rewind(stdin);
        std::cin >> choice;
        switch (choice) {
        case 1:
           handleCargoVehicle();
            break;
        case 2:
           handlePassengerVehicle();
            break;
        case 3:
           handleCar();
            break;
        case 0:
            std::cout << "����� �� ���������." << std::endl;
            break;
        default:
            std::cout << "�������� �����. ����������, ���������� �����." << std::endl;
            break;
        }
    } while (choice != 0);
}


