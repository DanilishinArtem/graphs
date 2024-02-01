#include "DataGenerator.h"

DataGen::DataGen(double start, double dx, int n) {
    for(int i = 0; i < n; i++) {
        x.push_back(start + i * dx);
        // y.push_back(main_function(x[i]));
    }        
    double mean_x = 0;
    double sd_x = 0;
    for(int i = 0; i < x.size(); i++) {
        mean_x += x[i];
    }
    mean_x /= x.size();
    for(int i = 0; i < x.size(); i++) {
        sd_x += (x[i] - mean_x) * (x[i] - mean_x);
    }
    sd_x /= x.size();
    sd_x = sqrt(sd_x);
    for(int i = 0; i < x.size(); i++) {
        x[i] = (x[i] - mean_x) / sd_x;
        y.push_back(main_function(x[i]));
    }
};

double DataGen::main_function(double x){
    // x /= 10;
    // return 2 * sin(x) + RandomGen::getVal() / 1;
    return 3 * x + 5;
};