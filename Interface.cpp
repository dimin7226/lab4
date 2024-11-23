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
    bool flag = true; // Управление циклом
    do {
        std::cout << "1. Добавить элемент стека" << std::endl;
        std::cout << "2. Показать стек" << std::endl;
        std::cout << "3. Удалить элемент стека" << std::endl;
        std::cout << "4. Измененить значение поля" << std::endl;
        std::cout << "5. Удалить все элементы стека" << std::endl;
        std::cout << "6. Удалить элемент по номеру №" << std::endl;
        std::cout << "7. Выход" << std::endl;
        std::cout << "Сделать выбор: ";
        rewind(stdin);
        std::cin >> selection;
        while (std::cin.get() != '\n'); // Удаляет все символы из потока ввода до новой строки
        switch (selection) {
        case '1': {
            T value;
            std::cin >> value;
            st.push(value);
            break;
        }
        case '2': {
            std::cout << "Показ стека..." << std::endl;
            st.show(value);
            break;
        }
        case '3': {
            std::cout << "Удаление элемента стека..." << std::endl;
            st.pop();
            break;
        }
        case '4': {
            std::cout << "Изменение значения поля..." << std::endl;
            st.show(value);
            int count;
            std::cout << "Укажите количество параметров по которым будет поиск: ";
            rewind(stdin);
            std::cin >> count;
            std::vector<int> columns(count);
            std::cout << "Укажите номер столбца, который соответствует параметру, который вы хотите изменить: ";
            for (int i = 0; i < count; i++) std::cin >> columns[i];
            for (int i = 0; i < count; i++) {
                std::cout << columns[i] << " ";
            }
            rewind(stdin);
            std::cout << "Введите новое значение: ";
            std::string value;
            std::cin >> value;
            /*
            code ...
            */
            break;
        }
        case '5': {
            std::cout << "Удаление всех элементов стека..." << std::endl;
            st.clear();
            break;
        }
        case '6': {
            std::cout << "Введите номер № элемента стека: ";
            int index;
            std::cin >> index;
            st.removeAt(index - 1);
            break;
        }
        case '7': {
            std::cout << "Выход из меню работы со стеком..." << std::endl;
            flag = false;
            break;
        }
        default: {
            std::cout << "Невозможный ввод. Пожалуйста, попробуйте снова." << std::endl;
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

    std::cout << "Неверный выбор. Пожалуйста, попробуйте снова." << std::endl;
}

template <class T>
void Interface<T>::handleCar() {
    handleVehicle<Car>(
        "Выберите тип легкового транспортного средства:\n"
        "1. Спорткар\n"
        "2. Внедорожник\n"
        "3. Лимузин\n"
        "Ваш выбор: ",
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
        "Выберите тип грузового транспортного средства:\n"
        "1. Рефрижератор\n"
        "2. Самосвал\n"
        "Ваш выбор: ",
        {
            {1, RefrigeratedCargoVehicle()},
            {2, DumpTruck()}
        }
    );
}

template <class T>
void Interface<T>::handlePassengerVehicle() {
    handleVehicle<PassengerVehicle>(
        "Выберите тип пассажирского транспортного средства:\n"
        "1. Междугородний\n"
        "2. Городской\n"
        "3. Международный\n"
        "Ваш выбор: ",
        {
            {1, IntercityPassengerVehicle()},
            {2, CityPassengerVehicle()},
            {3, InternationalPassengerVehicle()}
        }
    );
}

template <class T>
void Interface<T>::displayMainMenu() const {
    std::cout << "Выберете объект с которым будете работать:" << std::endl;
    std::cout << "1. Грузовое транспортное средство" << std::endl;
    std::cout << "2. Пассажирское транспортное средство" << std::endl;
    std::cout << "3. Легковое транспортное средство" << std::endl;
    std::cout << "0. Выход" << std::endl;
    std::cout << "Сделать выбор: ";
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
            std::cout << "Выход из программы." << std::endl;
            break;
        default:
            std::cout << "Неверный выбор. Пожалуйста, попробуйте снова." << std::endl;
            break;
        }
    } while (choice != 0);
}


