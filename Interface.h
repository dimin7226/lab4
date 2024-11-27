#include<vector>
#include<iostream>
#include <stack>
#include <utility>
#include <string.h>
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

template <class T>
class Interface {
private:
    stack<T*> st;
public:
    Interface() {}
    void displayMainMenu() const;
    void func();
    void menu(stack<T*>& st);
    void handleCar();
    void handleCargoVehicle();
    void handlePassengerVehicle();
    ~Interface() {}
};
