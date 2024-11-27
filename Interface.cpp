#include"Interface.h"
#include"Stack.h"
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

/*
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
        std::cout << "5. �����" << std::endl;
        std::cout << "6. ������� ��� �������� �����" << std::endl;
        std::cout << "7. ������� ������� �� ������ �" << std::endl;
        std::cout << "8. �����" << std::endl;
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

            if (st.empty()) {
                std::cout << "���� ����. �������� ������." << std::endl;
                break;
            }

            int index;
            std::cout << "������� ����� �������� � �����, ������� ������ �������� (������� � 1): ";
            std::cin >> index;

            // �������� ������������ �������
            if (index <= 0) {
                std::cout << "������������ ������." << std::endl;
                break;
            }

            T elementToModify;
            int currentIndex = 1;
            stack<T> tempStack;

            // ��������� �������� �� ������� �������
            while (!st.empty() && currentIndex < index) {
                tempStack.push(st.pop1());
                ++currentIndex;
            }

            if (st.empty() || currentIndex != index) {
                std::cout << "������� � ����� ������� �����������." << std::endl;
                while (!tempStack.empty()) {
                    st.push(tempStack.pop1());
                }
                break;
            }

            elementToModify = st.pop1(); // ��������� �������

            // ����� ����� ��� ��������������
            std::cout << "�������� ���� ��� ���������:\n";
            if constexpr (std::is_same<T, Car>::value) {
                std::cout << "1. ����\n";
                std::cout << "2. �����\n";
                std::cout << "3. ������\n";
                std::cout << "4. ��� �������\n";
                std::cout << "5. ��������� ����\n";
                std::cout << "6. ��� ���������\n";
                std::cout << "7. ���\n";
                std::cout << "8. ���������� ������\n";
            }
            else if constexpr (std::is_same<T, Jeep>::value) {
                std::cout << "1. �������\n";
                // �������� ���� ��� Jeep
            }
            // ���������� ��� ������ �������

            int fieldChoice;
            std::cout << "������� ����� ����: ";
            std::cin >> fieldChoice;

            std::cout << "������� ����� ��������: ";
            std::string newValue;
            std::cin.ignore();
            std::getline(std::cin, newValue);

            // ��������� ���� � ����������� �� ������
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
                // �������� ��������� ���� ��� �������
            default:
                std::cout << "�������� ����� ����." << std::endl;
                break;
            }

            if (fieldChanged) {
                std::cout << "���� ������� ��������." << std::endl;
            }
            else {
                std::cout << "���� �� ��������." << std::endl;
            }

            // ���������� �������� ������� � ����
            while (!tempStack.empty()) {
                st.push(tempStack.pop1());
            }
            st.push(elementToModify); // ���������� ���������� ������� � ����
            break;
        }
        case '5': {
            searchVehicle(st);
            break;
        }
        case '6': {
            std::cout << "�������� ���� ��������� �����..." << std::endl;
            st.clear();
            break;
        }
        case '7': {
            std::cout << "������� ����� � �������� �����: ";
            int index;
            std::cin >> index;
            st.removeAt(index - 1);
            break;
        }
        case '8': {
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
*/
template <class T>
void Interface<T>::menu(stack<T*>& st) {
    T value;
    char selection;
    bool flag = true;
    do {
        std::cout << "1. �������� ������� �����" << std::endl;
        std::cout << "2. �������� ����" << std::endl;
        std::cout << "3. ������� ������� �����" << std::endl;
        std::cout << "4. ���������� �������� ����" << std::endl;
        std::cout << "5. �����" << std::endl;
        std::cout << "6. ������� ��� �������� �����" << std::endl;
        std::cout << "7. ������� ������� �� ������ �" << std::endl;
        std::cout << "8. �����" << std::endl;
        std::cout << "������� �����: ";
        std::cin >> selection;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        switch (selection) {
        case '1': {
            T* value = new T(); // ������� ��������� �� ������
            std::cin >> *value;
            st.push(value);
            break;
        }
        case '2': {
            std::cout << "����� �����..." << std::endl;
            st.show();
            break;
        }
        case '3': {
            std::cout << "�������� �������� �����..." << std::endl;
            T* value = st.pop1();
            delete value; 
            break;
        }
        case '4': {
            std::cout << "��������� �������� ����..." << std::endl;
            // ���������� ��������� �������� ����
            break;
        }
        case '5': {
            //searchVehicle(st);
            break;
        }
        case '6': {
            std::cout << "�������� �������� �����..." << std::endl;
            T* value = st.pop1();
            delete value;
            break;
        }
        case '7': {
            std::cout << "������� ����� � �������� �����: ";
            int index;
            std::cin >> index;
            st.removeAt(index - 1);
            break;
        }
        case '8': {
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

    std::cout << "�������� �����. ����������, ���������� �����." << std::endl;
}

template <class T>
void Interface<T>::handleCar() {
    handleVehicle<TransportVehicle>(
        "�������� ��� ��������� ������������� ��������:\n"
        "1. ��������\n"
        "2. �����������\n"
        "3. �������\n"
        "��� �����: ",
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
        "�������� ��� ��������� ������������� ��������:\n"
        "1. ������������\n"
        "2. ��������\n"
        "��� �����: ",
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
        "�������� ��� ������������� ������������� ��������:\n"
        "1. �������������\n"
        "2. ���������\n"
        "3. �������������\n"
        "��� �����: ",
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

