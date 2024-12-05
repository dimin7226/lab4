#pragma once
#include <iostream>
#include <vector>
#include "Stack.h"
#include "TransportVehicle.h"

template <class T>
class Interface {
public:
    void func();
    void menu();
private:
    void displaySearchMenu();
    std::vector<int> getSearchParameters();
    std::vector<std::string> getSearchValues(const std::vector<int>& searchParams);
    std::string getVehicleValue(T* vehicle, int param);
    void modifyElement(stack<T*>& st);
    void searchVehicle(stack<T*>& st);
    void performSearch(stack<T*>& st, const std::vector<int>& searchParams, const std::vector<std::string>& searchValues);
};