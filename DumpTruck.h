#pragma once

#ifndef DUMPTRUCK_H
#define DUMPTRUCK_H

#include "CargoVehicle.h"

class DumpTruck : public CargoVehicle {
private:
    //std::string getParameterByIndex(int index) const override;
    double loadVolume;
public:
    DumpTruck();
    DumpTruck(const std::string& color, const std::string& brand, const std::string& model,
        int year, int horsepower, const std::string& engineType, double maxCargoWeight,
        double loadVolume);
    void setLoadVolume(double loadVolume);
    double getLoadVolume() const;
    void show() const override;
    DumpTruck& operator=(const DumpTruck& other);
    friend std::ostream& operator << (std::ostream& out, DumpTruck& vehicle);
    friend std::istream& operator >> (std::istream& out, DumpTruck& vehicle);
    virtual ~DumpTruck();
};

#endif 