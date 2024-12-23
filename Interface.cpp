#include<iostream>
#include "Interface.h"


template <typename T>
void Interface<T>::menu()
{
    
    stack<T> st;
    stack<T> findRes;
    T object;
    int choice, index;
    do
    {
        system("cls");
        std::cout << std::endl << "--- ���� ---" << std::endl
            << "1. �������� ������� � ����" << std::endl
            << "2. �������� ����" << std::endl
            << "3. ������� ������� �� �����" << std::endl
            << "4. �������� �������� ����" << std::endl
            << "5. �����" << std::endl
            << "6. ������� ��� �������� �����" << std::endl
            << "7. ������� ������� �� ������" << std::endl
            << "8. �����" << std::endl
            << "�������� ��������: ";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            std::cout << "������� �������:" << std::endl;
            std::cin >> object;
            st.push(object);
            break;
        case 2:
            st.show();
            system("pause");
            break;
        case 3:
            if (!st.empty()) {
                delete st.pop1();
                std::cout << "������� ������� ������ �� �����." << std::endl;
            }
            else  std::cout << "���� ����, ������ �������." << std::endl;
            break;
        }
        case 4: {
            if (!st.empty()) modifyElement(st);
            else  std::cout << "���� ����, ������ ��������." << std::endl;
            break;
        }
        case 5: {
           // if (!st.empty()) searchVehicle(st);
           // else std::cout << "���� ����, ����� ����������." << std::endl;
            break;
        }
        case 6: {
            while (!st.empty()) { delete st.pop1(); }
            std::cout << "��� �������� ������� �� �����." << std::endl;
            break;
        }
        case 7: {
            if (!st.empty()) {
                int index;
                std::cout << "������� ����� �������� ��� ��������: ";
                std::cin >> index;
                st.removeAt(index - 1);
            }
            else  std::cout << "���� ����, ������ �������." << std::endl;
            break;
        }
        case 8: {
            std::cout << "����� �� ����." << std::endl;
            break;
        }
        default:
            std::cout << "�������� �����. ���������� �����." << std::endl;
    } while (choice != 9);
    
}
template<typename T>
void Interface<T>::func()
{
    int choice;
    do
    {
        system("cls");
        std::cout << "1. �������� � �������� ��" << std::endl
        << "2. �������� � ������������ ��" << std::endl
        << "3. �������� � �������� ��" << std::endl
        << "4. �����." << std::endl
        << "��� �����: ";
        std::cin >> choice;
        switch (choice)
        {
        case 1: {
            Interface<CargoVehicle> obj;
            obj.menu();
        }
              break;
        case 2: {
            Interface<PassengerVehicle> obj;
            obj.menu();
        }
              break;
        case 3: {
            Interface<Car> obj;
            obj.menu();
        }
              break;
        default:
            break;
        }
        system("pause");
    } while (choice != 4);
}
/*
template <class T>
void Interface<T>::menu() {
    stack<T*> st;
    char selection;
    bool flag = true;
    do {
        std::cout << std::endl << "--- ���� ---" << std::endl
            << "1. �������� ������� � ����" << std::endl
            << "2. �������� ����" << std::endl
            << "3. ������� ������� �� �����" << std::endl
            << "4. �������� �������� ����" << std::endl
            << "5. �����" << std::endl
            << "6. ������� ��� �������� �����" << std::endl
            << "7. ������� ������� �� ������" << std::endl
            << "8. �����" << std::endl
            << "�������� ��������: ";
        std::cin >> selection;
        rewind(stdin);
        switch (selection) {
        case '1': {
            T* newVehicle = createVehicle();
            if (newVehicle) {
                st.push(newVehicle);
                std::cout << "������� �������� � ����." << std::endl;
            }
            break;
        }
        case '2': {
            if (st.empty()) {
                std::cout << "���� ����." << std::endl;
            }
            else {
                std::cout << "���������� �����:" << std::endl;
                st.show();
            }
            break;
        }
        case '3': {
            if (!st.empty()) {
                delete st.pop1();
                std::cout << "������� ������� ������ �� �����." << std::endl;
            }
            else  std::cout << "���� ����, ������ �������." << std::endl;
            break;
        }
        case '4': {
            if (!st.empty()) modifyElement(st);
            else  std::cout << "���� ����, ������ ��������." << std::endl;
            break;
        }
        case '5': {
            if (!st.empty()) searchVehicle(st);
            else std::cout << "���� ����, ����� ����������." << std::endl;
            break;
        }
        case '6': {
            while (!st.empty()) { delete st.pop1(); }
            std::cout << "��� �������� ������� �� �����." << std::endl;
            break;
        }
        case '7': {
            if (!st.empty()) {
                int index;
                std::cout << "������� ����� �������� ��� ��������: ";
                std::cin >> index;
                st.removeAt(index - 1);
            }
            else  std::cout << "���� ����, ������ �������." << std::endl;
            break;
        }
        case '8': {
            flag = false;
            std::cout << "����� �� ����." << std::endl;
            break;
        }
        default:
            std::cout << "�������� �����. ���������� �����." << std::endl;
        }
    } while (flag);
    st.clear();
}

template <class T>
TransportVehicle* Interface<T>::createVehicle() {
    int choice;
    std::cout << "�������� ��� ������������� ��������:\n";
    std::cout << "1. �������� ��\n";
    std::cout << "2. ������������ ��\n";
    std::cout << "3. �������� ��\n";
    std::cout << "��� �����: ";
    std::cin >> choice;
    TransportVehicle* vehicle = nullptr;
    switch (choice) {
    case 1: {
        std::cout << "�������� ��� ��������� ��:\n";
        std::cout << "1. ������������\n";
        std::cout << "2. ��������\n";
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
        std::cout << "�������� ��� ������������� ��:\n";
        std::cout << "1. �������������\n";
        std::cout << "2. ���������\n";
        std::cout << "3. �������������\n";
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
        std::cout << "�������� ��� ��������� ��:\n";
        std::cout << "1. ��������\n";
        std::cout << "2. �����������\n";
        std::cout << "3. �������\n";
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
        std::cout << "�������� �����.\n";
        return nullptr;
    }
    return vehicle;
}
*/

template <class T>
void Interface<T>::modifyElement(stack<T*>& st) {
    if (st.empty()) {
        std::cout << "���� ����. ������ ��������.\n";
        return;
    }
    std::cout << "������� ��������� �����:\n";
    st.show();
    int index;
    std::cout << "������� ����� �������� ��� ��������� (������� � 1): ";
    std::cin >> index;
    if (index < 1) {
        std::cout << "�������� ������.\n";
        return;
    }
    stack<T*> tempStack;
    int currentIndex = 1;
    T* elementToModify = nullptr;
    while (!st.empty() && currentIndex < index) {   // ��������� �������� �� ������� �������
        tempStack.push(st.pop1());
        ++currentIndex;
    }
    if (st.empty()) std::cout << "������� � ����� ������� �����������." << std::endl;
    else {
        elementToModify = st.pop1();
        std::cout << "������� ������ ��������:" << std::endl;
        std::cout << *elementToModify << std::endl;
        std::cout << "�������� ���� ��� ���������:" << std::endl;
        std::cout << "1. ����" << std::endl;
        std::cout << "2. �����" << std::endl;
        std::cout << "3. ������" << std::endl;
        std::cout << "4. ��� �������" << std::endl;
        std::cout << "5. ��������� ����" << std::endl;
        std::cout << "6. ��� ���������" << std::endl;
        if (dynamic_cast<Car*>(elementToModify)) {
            std::cout << "7. ��� ����������" << std::endl;
            std::cout << "8. ���������� ������" << std::endl;
        }
        if (dynamic_cast<SportsCar*>(elementToModify)) {
            std::cout << "9. ������������ ��������" << std::endl;
            std::cout << "10. ����� ������� �� 100 ��/�" << std::endl;
        }
        if (dynamic_cast<Limousine*>(elementToModify))
            std::cout << "11. ����� ����������\n";
        if (dynamic_cast<PassengerVehicle*>(elementToModify))
            std::cout << "12. ���������� ������������ ����\n";
        if (dynamic_cast<CargoVehicle*>(elementToModify))
            std::cout << "13. ������������ ��� �����\n";
        if (dynamic_cast<DumpTruck*>(elementToModify))
            std::cout << "14. ����� ������\n";
        if (dynamic_cast<RefrigeratedCargoVehicle*>(elementToModify))
            std::cout << "15. ����������� �����������\n";
        int fieldChoice;
        std::cout << "������� ����� ����: ";
        std::cin >> fieldChoice;
        std::string newStringValue;
        int newIntValue;
        double newDoubleValue;
        switch (fieldChoice) {
        case 1:
            std::cout << "������� ����� ����: ";
            std::cin >> newStringValue;
            elementToModify->setColor(newStringValue);
            break;
        case 2:
            std::cout << "������� ����� �����: ";
            std::cin >> newStringValue;
            elementToModify->setBrand(newStringValue);
            break;
        case 3:
            std::cout << "������� ����� ������: ";
            std::cin >> newStringValue;
            elementToModify->setModel(newStringValue);
            break;
        case 4:
            std::cout << "������� ����� ��� �������: ";
            std::cin >> newIntValue;
            elementToModify->setYear(newIntValue);
            break;
        case 5:
            std::cout << "������� ����� ���������� ��������� ���: ";
            std::cin >> newIntValue;
            elementToModify->setHorsepower(newIntValue);
            break;
        case 6:
            std::cout << "������� ����� ��� ���������: ";
            std::cin >> newStringValue;
            elementToModify->setEngineType(newStringValue);
            break;
        case 7:
            if (auto car = dynamic_cast<Car*>(elementToModify)) {
                std::cout << "������� ����� ��� ����������: ";
                std::cin >> newDoubleValue;
                car->setWeightCar(newDoubleValue);
            }
            break;
        case 8:
            if (auto car = dynamic_cast<Car*>(elementToModify)) {
                std::cout << "������� ����� ���������� ������: ";
                std::cin >> newIntValue;
                car->setNumberOfDoors(newIntValue);
            }
            break;
        case 9:
            if (auto sportsCar = dynamic_cast<SportsCar*>(elementToModify)) {
                std::cout << "������� ����� ������������ ��������: ";
                std::cin >> newDoubleValue;
                sportsCar->setMaxSpeed(newDoubleValue);
            }
            break;
        case 10:
            if (auto sportsCar = dynamic_cast<SportsCar*>(elementToModify)) {
                std::cout << "������� ����� ����� ������� �� 100 ��/�: ";
                std::cin >> newDoubleValue;
                sportsCar->setAccelerationTime(newDoubleValue);
            }
            break;
        case 11:
            if (auto limousine = dynamic_cast<Limousine*>(elementToModify)) {
                std::cout << "������� ����� ����� ����������: ";
                std::cin >> newDoubleValue;
                limousine->setLength(newDoubleValue);
            }
            break;
        case 12:
            if (auto passengerVehicle = dynamic_cast<PassengerVehicle*>(elementToModify)) {
                std::cout << "������� ����� ���������� ������������ ����: ";
                std::cin >> newIntValue;
                passengerVehicle->setPassengerSeats(newIntValue);
            }
            break;
        case 13:
            if (auto cargoVehicle = dynamic_cast<CargoVehicle*>(elementToModify)) {
                std::cout << "������� ����� ������������ ��� �����: ";
                std::cin >> newDoubleValue;
                cargoVehicle->setMaxWeight(newDoubleValue);
            }
            break;
        case 14:
            if (auto dumpTruck = dynamic_cast<DumpTruck*>(elementToModify)) {
                std::cout << "������� ����� ����� ������: ";
                std::cin >> newDoubleValue;
                dumpTruck->setLoadVolume(newDoubleValue);
            }
            break;
        case 15:
            if (auto refrigeratedCargoVehicle = dynamic_cast<RefrigeratedCargoVehicle*>(elementToModify)) {
                std::cout << "������� ����� ����������� �����������: ";
                std::cin >> newDoubleValue;
                refrigeratedCargoVehicle->setMinTemperature(newDoubleValue);
            }
            break;
        default:
            std::cout << "�������� ����� ����.\n";
            break;
        }
        std::cout << "������� ������� �������.\n";
        st.push(elementToModify);
    }
    while (!tempStack.empty()) { 
        st.push(tempStack.pop1());
    }
}
