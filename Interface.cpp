#include<iostream>
#include "interface.h"

template <class T>
void Interface<T>::searchVehicle(stack<T*>& st) {
    if (st.empty()) {
        std::cout << "Стек пуст. Поиск невозможен.\n";
        return;
    }

    std::cout << "Выберите параметры для поиска (введите номера через пробел, 0 для завершения выбора):\n";
    std::cout << "1. Цвет\n2. Бренд\n3. Модель\n4. Год выпуска\n5. Лошадиные силы\n6. Тип двигателя\n";
    std::cout << "7. Вес автомобиля\n8. Количество дверей\n9. Максимальная скорость\n";
    std::cout << "10. Время разгона до 100 км/ч\n11. Длина автомобиля\n12. Количество пассажирских мест\n";
    std::cout << "13. Максимальный вес груза\n14. Объем кузова\n15. Минимальная температура\n";

    std::vector<int> searchParams;
    int param;
    while (true) {
        std::cin >> param;
        if (param == 0) break;
        if (param >= 1 && param <= 15) searchParams.push_back(param);
    }

    std::vector<std::string> searchValues(searchParams.size());
    for (size_t i = 0; i < searchParams.size(); ++i) {
        std::cout << "Введите значение для параметра " << searchParams[i] << ": ";
        std::cin >> searchValues[i];
    }

    stack<T*> tempStack;
    bool found = false;

    while (!st.empty()) {
        T* vehicle = st.pop1();
        bool match = true;

        for (size_t i = 0; i < searchParams.size(); ++i) {
            std::string vehicleValue;
            switch (searchParams[i]) {
            case 1: vehicleValue = vehicle->getColor(); break;
            case 2: vehicleValue = vehicle->getBrand(); break;
            case 3: vehicleValue = vehicle->getModel(); break;
            case 4: vehicleValue = std::to_string(vehicle->getYear()); break;
            case 5: vehicleValue = std::to_string(vehicle->getHorsepower()); break;
            case 6: vehicleValue = vehicle->getEngineType(); break;
            case 7:
                if (auto car = dynamic_cast<Car*>(vehicle))
                    vehicleValue = std::to_string(car->getWightCar());
                break;
            case 8:
                if (auto car = dynamic_cast<Car*>(vehicle))
                    vehicleValue = std::to_string(car->getNumberOfDoors());
                break;
            case 9:
                if (auto sportsCar = dynamic_cast<SportsCar*>(vehicle))
                    vehicleValue = std::to_string(sportsCar->getMaxSpeed());
                break;
            case 10:
                if (auto sportsCar = dynamic_cast<SportsCar*>(vehicle))
                    vehicleValue = std::to_string(sportsCar->getAccelerationTime());
                break;
            case 11:
                if (auto limousine = dynamic_cast<Limousine*>(vehicle))
                    vehicleValue = std::to_string(limousine->getLength());
                break;
            case 12:
                if (auto passengerVehicle = dynamic_cast<PassengerVehicle*>(vehicle))
                    vehicleValue = std::to_string(passengerVehicle->getPassengerSeats());
                break;
            case 13:
                if (auto cargoVehicle = dynamic_cast<CargoVehicle*>(vehicle))
                    vehicleValue = std::to_string(cargoVehicle->getMaxWeight());
                break;
            case 14:
                if (auto dumpTruck = dynamic_cast<DumpTruck*>(vehicle))
                    vehicleValue = std::to_string(dumpTruck->getLoadVolume());
                break;
            case 15:
                if (auto refrigeratedCargoVehicle = dynamic_cast<RefrigeratedCargoVehicle*>(vehicle))
                    vehicleValue = std::to_string(refrigeratedCargoVehicle->getMinTemperature());
                break;
            }

            if (vehicleValue != searchValues[i]) {
                match = false;
                break;
            }
        }

        if (match) {
            std::cout << "Найдено совпадение:\n";
            (*vehicle).show();
            std::cout << *vehicle << std::endl;
            found = true;
        }

        tempStack.push(vehicle);
    }

    // Восстанавливаем исходный стек
    while (!tempStack.empty()) {
        st.push(tempStack.pop1());
    }

    if (!found) {
        std::cout << "Совпадений не найдено.\n";
    }
}

template <class T>
TransportVehicle* Interface<T>::createVehicle() {
    int choice;
    std::cout << "Выберите тип транспортного средства:\n";
    std::cout << "1. Грузовое ТС\n";
    std::cout << "2. Пассажирское ТС\n";
    std::cout << "3. Легковое ТС\n";
    std::cout << "Ваш выбор: ";
    std::cin >> choice;
    TransportVehicle* vehicle = nullptr;
    switch (choice) {
    case 1: {
        std::cout << "Выберите тип грузового ТС:\n";
        std::cout << "1. Рефрижератор\n";
        std::cout << "2. Самосвал\n";
        std::cin >> choice;
        if (choice == 1) {
            auto* refVehicle = new RefrigeratedCargoVehicle();
            std::cin >> *refVehicle;
            vehicle = refVehicle;
        }
        else if (choice == 2) {
            auto* dumpVehicle = new DumpTruck();
            std::cin >> *dumpVehicle;
            vehicle = dumpVehicle;
        }
        break;
    }
    case 2: {
        std::cout << "Выберите тип пассажирского ТС:\n";
        std::cout << "1. Междугородний\n";
        std::cout << "2. Городской\n";
        std::cout << "3. Международный\n";
        std::cin >> choice;
        if (choice == 1) {
            auto* intercityVehicle = new IntercityPassengerVehicle();
            std::cin >> *intercityVehicle;
            vehicle = intercityVehicle;
        }
        else if (choice == 2) {
            auto* cityVehicle = new CityPassengerVehicle();
            std::cin >> *cityVehicle;
            vehicle = cityVehicle;
        }
        else if (choice == 3) {
            auto* internationalVehicle = new InternationalPassengerVehicle();
            std::cin >> *internationalVehicle;
            vehicle = internationalVehicle;
        }
        break;
    }
    case 3: {
        std::cout << "Выберите тип легкового ТС:\n";
        std::cout << "1. Спорткар\n";
        std::cout << "2. Внедорожник\n";
        std::cout << "3. Лимузин\n";
        std::cin >> choice;
        if (choice == 1) {
            auto* sportsVehicle = new SportsCar();
            std::cin >> *sportsVehicle;
            vehicle = sportsVehicle;
        }
        else if (choice == 2) {
            auto* jeepVehicle = new Jeep();
            std::cin >> *jeepVehicle;
            vehicle = jeepVehicle;
        }
        else if (choice == 3) {
            auto* limoVehicle = new Limousine();
            std::cin >> *limoVehicle;
            vehicle = limoVehicle;
        }
        break;
    }
    default:
        std::cout << "Неверный выбор.\n";
        return nullptr;
    }
    return vehicle;
}

template <class T>
void Interface<T>::modifyElement(stack<T*>& st) {
    if (st.empty()) {
        std::cout << "Стек пуст. Нечего изменять.\n";
        return;
    }
    std::cout << "Текущее состояние стека:\n";
    st.show();
    int index;
    std::cout << "Введите номер элемента для изменения (начиная с 1): ";
    std::cin >> index;
    if (index < 1) {
        std::cout << "Неверный индекс.\n";
        return;
    }
    stack<T*> tempStack;
    int currentIndex = 1;
    T* elementToModify = nullptr;
    while (!st.empty() && currentIndex < index) {   // Извлекаем элементы до нужного индекса
        tempStack.push(st.pop1());
        ++currentIndex;
    }
    if (st.empty()) std::cout << "Элемент с таким номером отсутствует.\n";
    else {
        elementToModify = st.pop1();
        std::cout << "Текущие данные элемента:\n";
        std::cout << *elementToModify << std::endl;
        std::cout << "Выберите поле для изменения:\n";
        std::cout << "1. Цвет\n";
        std::cout << "2. Бренд\n";
        std::cout << "3. Модель\n";
        std::cout << "4. Год выпуска\n";
        std::cout << "5. Лошадиные силы\n";
        std::cout << "6. Тип двигателя\n";
        if (dynamic_cast<Car*>(elementToModify)) {
            std::cout << "7. Вес автомобиля\n";
            std::cout << "8. Количество дверей\n";
        }
        if (dynamic_cast<SportsCar*>(elementToModify)) {
            std::cout << "9. Максимальная скорость\n";
            std::cout << "10. Время разгона до 100 км/ч\n";
        }
        if (dynamic_cast<Limousine*>(elementToModify)) {
            std::cout << "11. Длина автомобиля\n";
        }
        if (dynamic_cast<PassengerVehicle*>(elementToModify)) {
            std::cout << "12. Количество пассажирских мест\n";
        }
        if (dynamic_cast<CargoVehicle*>(elementToModify)) {
            std::cout << "13. Максимальный вес груза\n";
        }
        if (dynamic_cast<DumpTruck*>(elementToModify)) {
            std::cout << "14. Объем кузова\n";
        }
        if (dynamic_cast<RefrigeratedCargoVehicle*>(elementToModify)) {
            std::cout << "15. Минимальная температура\n";
        }
        int fieldChoice;
        std::cout << "Введите номер поля: ";
        std::cin >> fieldChoice;
        std::string newStringValue;
        int newIntValue;
        double newDoubleValue;
        switch (fieldChoice) {
        case 1:
            std::cout << "Введите новый цвет: ";
            std::cin >> newStringValue;
            elementToModify->setColor(newStringValue);
            break;
        case 2:
            std::cout << "Введите новый бренд: ";
            std::cin >> newStringValue;
            elementToModify->setBrand(newStringValue);
            break;
        case 3:
            std::cout << "Введите новую модель: ";
            std::cin >> newStringValue;
            elementToModify->setModel(newStringValue);
            break;
        case 4:
            std::cout << "Введите новый год выпуска: ";
            std::cin >> newIntValue;
            elementToModify->setYear(newIntValue);
            break;
        case 5:
            std::cout << "Введите новое количество лошадиных сил: ";
            std::cin >> newIntValue;
            elementToModify->setHorsepower(newIntValue);
            break;
        case 6:
            std::cout << "Введите новый тип двигателя: ";
            std::cin >> newStringValue;
            elementToModify->setEngineType(newStringValue);
            break;
        case 7:
            if (auto car = dynamic_cast<Car*>(elementToModify)) {
                std::cout << "Введите новый вес автомобиля: ";
                std::cin >> newDoubleValue;
                car->setWeightCar(newDoubleValue);
            }
            break;
        case 8:
            if (auto car = dynamic_cast<Car*>(elementToModify)) {
                std::cout << "Введите новое количество дверей: ";
                std::cin >> newIntValue;
                car->setNumberOfDoors(newIntValue);
            }
            break;
        case 9:
            if (auto sportsCar = dynamic_cast<SportsCar*>(elementToModify)) {
                std::cout << "Введите новую максимальную скорость: ";
                std::cin >> newDoubleValue;
                sportsCar->setMaxSpeed(newDoubleValue);
            }
            break;
        case 10:
            if (auto sportsCar = dynamic_cast<SportsCar*>(elementToModify)) {
                std::cout << "Введите новое время разгона до 100 км/ч: ";
                std::cin >> newDoubleValue;
                sportsCar->setAccelerationTime(newDoubleValue);
            }
            break;
        case 11:
            if (auto limousine = dynamic_cast<Limousine*>(elementToModify)) {
                std::cout << "Введите новую длину автомобиля: ";
                std::cin >> newDoubleValue;
                limousine->setLength(newDoubleValue);
            }
            break;
        case 12:
            if (auto passengerVehicle = dynamic_cast<PassengerVehicle*>(elementToModify)) {
                std::cout << "Введите новое количество пассажирских мест: ";
                std::cin >> newIntValue;
                passengerVehicle->setPassengerSeats(newIntValue);
            }
            break;
        case 13:
            if (auto cargoVehicle = dynamic_cast<CargoVehicle*>(elementToModify)) {
                std::cout << "Введите новый максимальный вес груза: ";
                std::cin >> newDoubleValue;
                cargoVehicle->setMaxWeight(newDoubleValue);
            }
            break;
        case 14:
            if (auto dumpTruck = dynamic_cast<DumpTruck*>(elementToModify)) {
                std::cout << "Введите новый объем кузова: ";
                std::cin >> newDoubleValue;
                dumpTruck->setLoadVolume(newDoubleValue);
            }
            break;
        case 15:
            if (auto refrigeratedCargoVehicle = dynamic_cast<RefrigeratedCargoVehicle*>(elementToModify)) {
                std::cout << "Введите новую минимальную температуру: ";
                std::cin >> newDoubleValue;
                refrigeratedCargoVehicle->setMinTemperature(newDoubleValue);
            }
            break;
        default:
            std::cout << "Неверный выбор поля.\n";
            break;
        }
        std::cout << "Элемент успешно изменен.\n";
        st.push(elementToModify);
    }
    while (!tempStack.empty()) {    // Возвращаем остальные элементы обратно в стек
        st.push(tempStack.pop1());
    }
}


template <class T>
void Interface<T>::menu() {
    stack<T*> st;
    char selection;
    bool flag = true;
    do {
        std::cout << std::endl << "--- Меню ---" << std::endl
            << "1. Добавить элемент в стек" << std::endl
            << "2. Показать стек" << std::endl
            << "3. Удалить элемент из стека" << std::endl
            << "4. Изменить значение поля" << std::endl
            << "5. Поиск" << std::endl
            << "6. Удалить все элементы стека" << std::endl
            << "7. Удалить элемент по номеру" << std::endl
            << "8. Выход" << std::endl
            << "Выберите действие: ";
        std::cin >> selection;
        rewind(stdin);
        switch (selection) {
        case '1': {
            T* newVehicle = createVehicle();
            if (newVehicle) {
                st.push(newVehicle);
                std::cout << "Элемент добавлен в стек." << std::endl;
            }
            break;
        }
        case '2': {
            if (st.empty()) {
                std::cout << "Стек пуст." << std::endl;
            }
            else {
                std::cout << "Содержимое стека:" << std::endl;
                st.show();
            }
            break;
        }
        case '3': {
            if (!st.empty()) {
                delete st.pop1();
                std::cout << "Верхний элемент удален из стека." << std::endl;
            }
            else {
                std::cout << "Стек пуст, нечего удалять." << std::endl;
            }
            break;
        }
        case '4': {
            if (!st.empty()) {
                modifyElement(st);
            }
            else {
                std::cout << "Стек пуст, нечего изменять." << std::endl;
            }
            break;
        }
        case '5': {
            if (!st.empty()) {
                searchVehicle(st);
            }
            else {
                std::cout << "Стек пуст, поиск невозможен." << std::endl;
            }
            break;
        }
        case '6': {
            while (!st.empty()) {
                delete st.pop1();
            }
            std::cout << "Все элементы удалены из стека." << std::endl;
            break;
        }
        case '7': {
            if (!st.empty()) {
                int index;
                std::cout << "Введите номер элемента для удаления: ";
                std::cin >> index;
                st.removeAt(index - 1);
            }
            else {
                std::cout << "Стек пуст, нечего удалять." << std::endl;
            }
            break;
        }
        case '8': {
            flag = false;
            std::cout << "Выход из меню." << std::endl;
            break;
        }
        default:
            std::cout << "Неверный выбор. Попробуйте снова." << std::endl;
        }
    } while (flag);
    st.clear();
}