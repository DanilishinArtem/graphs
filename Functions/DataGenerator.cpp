#include "DataGenerator.h"

DataGen::DataGen(int n) {
    for(int i = 0; i < n; i++) {
        x.push_back(RandomGen::getVal());
        y.push_back(main_function(x[i]));
    }        
};

double DataGen::main_function(double x){
    // 3 * (x ** 3) + (x ** 2) + 0.5 --> python version
    return 3 * (x * x * x) + (x * x) + 0.5;
};