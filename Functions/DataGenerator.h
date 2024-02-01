#ifndef GATADEN_H
#define GATADEN_H
#include <vector>
#include <cmath>

class DataGen{
public:
    std::vector<double> x;
    std::vector<double> y;
    double main_function(double x);
    DataGen(double start, double dx, int n);
};

#endif