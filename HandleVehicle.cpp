//#include "Interface.cpp"
//#include "HandleVehicle.h"
//
//void displayMainMenu() {
//    std::cout << "�������� ������ � ������� ������ ��������:" << std::endl;
//    std::cout << "1. �������� ������������ ��������" << std::endl;
//    std::cout << "2. ������������ ������������ ��������" << std::endl;
//    std::cout << "3. �������� ������������ ��������" << std::endl;
//    std::cout << "0. �����" << std::endl;
//    std::cout << "������� �����: ";
//}
//
//void func() {
//    int choice;
//    do {
//        displayMainMenu();
//        rewind(stdin);
//        std::cin >> choice;
//        switch (choice) {
//        case 1:
//            handleCargoVehicle();
//            break;
//        case 2:
//            handlePassengerVehicle();
//            break;
//        case 3:
//            handleCar();
//            break;
//        case 0:
//            std::cout << "����� �� ���������." << std::endl;
//            break;
//        default:
//            std::cout << "�������� �����. ����������, ���������� �����." << std::endl;
//            break;
//        }
//    } while (choice != 0);
//}
//
//template <typename VehicleType>
//void handleVehicle(const std::string& prompt, const std::vector<std::pair<int, VehicleType>>& options) {
//    std::cout << prompt;
//    int choice;
//    rewind(stdin);
//    std::cin >> choice;
//    for (const auto& option : options) {
//        if (option.first == choice) {
//            Interface<VehicleType> vehicle;
//            vehicle.menu();
//            return;
//        }
//    }
//    std::cout << "�������� �����. ����������, ���������� �����." << std::endl;
//}
//
//void handleCar() {
//    handleVehicle<Car>(
//        "�������� ��� ��������� ������������� ��������:\n"
//        "1. ��������\n"
//        "2. �����������\n"
//        "3. �������\n"
//        "��� �����: ",
//        {
//        { 1, SportsCar{} },
//        { 2, Jeep{} },
//        { 3, Limousine{} }
//        }
//    );
//}
//
//void handleCargoVehicle() {
//    handleVehicle<CargoVehicle>(
//        "�������� ��� ��������� ������������� ��������:\n"
//        "1. ������������\n"
//        "2. ��������\n"
//        "��� �����: ",
//        {
//            {1, RefrigeratedCargoVehicle()},
//            {2, DumpTruck()}
//        }
//    );
//}
//
//void handlePassengerVehicle() {
//    handleVehicle<PassengerVehicle>(
//        "�������� ��� ������������� ������������� ��������:\n"
//        "1. �������������\n"
//        "2. ���������\n"
//        "3. �������������\n"
//        "��� �����: ",
//        {
//            {1, IntercityPassengerVehicle()},
//            {2, CityPassengerVehicle()},
//            {3, InternationalPassengerVehicle()}
//        }
//    );
//}