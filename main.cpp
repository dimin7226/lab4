#include <iostream>
#include "Interface.cpp"
#include "TransportVehicle.h"
#include "Stack.cpp"

int main() {
    system("chcp 1251");
    system("cls");
    Interface<TransportVehicle> interface; 
    interface.func();
    return 0;
}