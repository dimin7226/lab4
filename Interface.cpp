#include"Interface.h"
#include"Stack.h"
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

/*
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
        std::cout << "5. Поиск" << std::endl;
        std::cout << "6. Удалить все элементы стека" << std::endl;
        std::cout << "7. Удалить элемент по номеру №" << std::endl;
        std::cout << "8. Выход" << std::endl;
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

            if (st.empty()) {
                std::cout << "Стек пуст. Изменять нечего." << std::endl;
                break;
            }

            int index;
            std::cout << "Введите номер элемента в стеке, который хотите изменить (начиная с 1): ";
            std::cin >> index;

            // Проверка корректности индекса
            if (index <= 0) {
                std::cout << "Некорректный индекс." << std::endl;
                break;
            }

            T elementToModify;
            int currentIndex = 1;
            stack<T> tempStack;

            // Извлекаем элементы до нужного индекса
            while (!st.empty() && currentIndex < index) {
                tempStack.push(st.pop1());
                ++currentIndex;
            }

            if (st.empty() || currentIndex != index) {
                std::cout << "Элемент с таким номером отсутствует." << std::endl;
                while (!tempStack.empty()) {
                    st.push(tempStack.pop1());
                }
                break;
            }

            elementToModify = st.pop1(); // Извлекаем элемент

            // Вывод полей для редактирования
            std::cout << "Выберите поле для изменения:\n";
            if constexpr (std::is_same<T, Car>::value) {
                std::cout << "1. Цвет\n";
                std::cout << "2. Бренд\n";
                std::cout << "3. Модель\n";
                std::cout << "4. Год выпуска\n";
                std::cout << "5. Лошадиные силы\n";
                std::cout << "6. Тип двигателя\n";
                std::cout << "7. Вес\n";
                std::cout << "8. Количество дверей\n";
            }
            else if constexpr (std::is_same<T, Jeep>::value) {
                std::cout << "1. Клиренс\n";
                // Добавить поля для Jeep
            }
            // Аналогично для других классов

            int fieldChoice;
            std::cout << "Введите номер поля: ";
            std::cin >> fieldChoice;

            std::cout << "Введите новое значение: ";
            std::string newValue;
            std::cin.ignore();
            std::getline(std::cin, newValue);

            // Изменение поля в зависимости от выбора
            bool fieldChanged = false;
            switch (fieldChoice) {
            case 1:
                if constexpr (std::is_same<T, Car>::value || std::is_same<T, Jeep>::value) {
                    elementToModify.setColor(newValue);
                    fieldChanged = true;
                }
                break;
            case 2:
                if constexpr (std::is_same<T, Car>::value) {
                    elementToModify.setBrand(newValue);
                    fieldChanged = true;
                }
                break;
                // Добавить остальные поля для классов
            default:
                std::cout << "Неверный выбор поля." << std::endl;
                break;
            }

            if (fieldChanged) {
                std::cout << "Поле успешно изменено." << std::endl;
            }
            else {
                std::cout << "Поле не изменено." << std::endl;
            }

            // Возвращаем элементы обратно в стек
            while (!tempStack.empty()) {
                st.push(tempStack.pop1());
            }
            st.push(elementToModify); // Возвращаем измененный элемент в стек
            break;
        }
        case '5': {
            searchVehicle(st);
            break;
        }
        case '6': {
            std::cout << "Удаление всех элементов стека..." << std::endl;
            st.clear();
            break;
        }
        case '7': {
            std::cout << "Введите номер № элемента стека: ";
            int index;
            std::cin >> index;
            st.removeAt(index - 1);
            break;
        }
        case '8': {
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
*/
template <class T>
void Interface<T>::menu(stack<T*>& st) {
    T value;
    char selection;
    bool flag = true;
    do {
        std::cout << "1. Добавить элемент стека" << std::endl;
        std::cout << "2. Показать стек" << std::endl;
        std::cout << "3. Удалить элемент стека" << std::endl;
        std::cout << "4. Измененить значение поля" << std::endl;
        std::cout << "5. Поиск" << std::endl;
        std::cout << "6. Удалить все элементы стека" << std::endl;
        std::cout << "7. Удалить элемент по номеру №" << std::endl;
        std::cout << "8. Выход" << std::endl;
        std::cout << "Сделать выбор: ";
        std::cin >> selection;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        switch (selection) {
        case '1': {
            T* value = new T(); // Создаем указатель на объект
            std::cin >> *value;
            st.push(value);
            break;
        }
        case '2': {
            std::cout << "Показ стека..." << std::endl;
            st.show();
            break;
        }
        case '3': {
            std::cout << "Удаление элемента стека..." << std::endl;
            T* value = st.pop1();
            delete value; 
            break;
        }
        case '4': {
            std::cout << "Изменение значения поля..." << std::endl;
            // Реализация изменения значения поля
            break;
        }
        case '5': {
            //searchVehicle(st);
            break;
        }
        case '6': {
            std::cout << "Удаление элемента стека..." << std::endl;
            T* value = st.pop1();
            delete value;
            break;
        }
        case '7': {
            std::cout << "Введите номер № элемента стека: ";
            int index;
            std::cin >> index;
            st.removeAt(index - 1);
            break;
        }
        case '8': {
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
void handleVehicle(const std::string& prompt, const std::vector<std::pair<int, VehicleType*>>& options, stack<VehicleType*>& st) {
    std::cout << prompt;
    int choice;
    std::cin >> choice;
    for (const auto& option : options) {
        if (option.first == choice) {
            Interface<VehicleType> vehicle;
            vehicle.menu(st);
            return;
        }
    }

    std::cout << "Неверный выбор. Пожалуйста, попробуйте снова." << std::endl;
}

template <class T>
void Interface<T>::handleCar() {
    handleVehicle<TransportVehicle>(
        "Выберите тип легкового транспортного средства:\n"
        "1. Спорткар\n"
        "2. Внедорожник\n"
        "3. Лимузин\n"
        "Ваш выбор: ",
        {
        { 1, new SportsCar() },
        { 2, new Jeep() },
        { 3, new Limousine() }
        },
        st
        );
}

template <class T>
void Interface<T>::handleCargoVehicle() {
    handleVehicle<TransportVehicle>(
        "Выберите тип грузового транспортного средства:\n"
        "1. Рефрижератор\n"
        "2. Самосвал\n"
        "Ваш выбор: ",
        {
            {1, new RefrigeratedCargoVehicle()},
            {2, new DumpTruck()}
        },
        st
    );
}

template <class T>
void Interface<T>::handlePassengerVehicle() {
    handleVehicle<TransportVehicle>(
        "Выберите тип пассажирского транспортного средства:\n"
        "1. Междугородний\n"
        "2. Городской\n"
        "3. Международный\n"
        "Ваш выбор: ",
        {
            {1, new IntercityPassengerVehicle()},
            {2, new CityPassengerVehicle()},
            {3, new InternationalPassengerVehicle()}
        },
        st
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

