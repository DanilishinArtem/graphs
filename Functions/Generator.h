#ifndef GENERATOR_H
#define GENERATOR_H
#include <vector>
#include <random>

class RandomGen {
public:
    static double getVal() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<double> dis(0.0, 1.0);
        return dis(gen);
    }
};

class NormalGen {
public:
    static double getVal() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::normal_distribution<double> dis(0.0, 1.0);
        return dis(gen);
    }    
};

#endif