//#include "Interface.cpp"
//#include "HandleVehicle.h"
//
//void displayMainMenu() {
//    std::cout << "Выберете объект с которым будете работать:" << std::endl;
//    std::cout << "1. Грузовое транспортное средство" << std::endl;
//    std::cout << "2. Пассажирское транспортное средство" << std::endl;
//    std::cout << "3. Легковое транспортное средство" << std::endl;
//    std::cout << "0. Выход" << std::endl;
//    std::cout << "Сделать выбор: ";
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
//            std::cout << "Выход из программы." << std::endl;
//            break;
//        default:
//            std::cout << "Неверный выбор. Пожалуйста, попробуйте снова." << std::endl;
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
//    std::cout << "Неверный выбор. Пожалуйста, попробуйте снова." << std::endl;
//}
//
//void handleCar() {
//    handleVehicle<Car>(
//        "Выберите тип легкового транспортного средства:\n"
//        "1. Спорткар\n"
//        "2. Внедорожник\n"
//        "3. Лимузин\n"
//        "Ваш выбор: ",
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
//        "Выберите тип грузового транспортного средства:\n"
//        "1. Рефрижератор\n"
//        "2. Самосвал\n"
//        "Ваш выбор: ",
//        {
//            {1, RefrigeratedCargoVehicle()},
//            {2, DumpTruck()}
//        }
//    );
//}
//
//void handlePassengerVehicle() {
//    handleVehicle<PassengerVehicle>(
//        "Выберите тип пассажирского транспортного средства:\n"
//        "1. Междугородний\n"
//        "2. Городской\n"
//        "3. Международный\n"
//        "Ваш выбор: ",
//        {
//            {1, IntercityPassengerVehicle()},
//            {2, CityPassengerVehicle()},
//            {3, InternationalPassengerVehicle()}
//        }
//    );
//}