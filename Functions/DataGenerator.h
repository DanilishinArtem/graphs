#ifndef GATADEN_H
#define GATADEN_H
#include <vector>
#include <cmath>
#include "Generator.h"

class DataGen{
public:
    std::vector<double> x;
    std::vector<double> y;
    double main_function(double x);
    DataGen(int n);
};

#endif