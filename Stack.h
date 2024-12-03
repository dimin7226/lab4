#pragma once 
#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
#include <string>
#include "TransportVehicle.h"
#include "Car.h"
#include "CargoVehicle.h"
#include "PassengerVehicle.h"
#include "Jeep.h"
#include "DumpTruck.h"
#include "Limousine.h"
#include "IntercityPassengerVehicle.h"
#include "CityPassengerVehicle.h"
#include "InternationalPassengerVehicle.h"
#include "RefrigeratedCargoVehicle.h"
#include "SportsCar.h"

template <class T>
class stack {
private:
    struct item {
        T i;
        item* next;
    };
    item* head;
public:
    stack();
    ~stack();
    void push(T value);
    void pop();
    T pop1();
    void show();
    bool empty();
    void clear();
    void removeAt(int index);
};
