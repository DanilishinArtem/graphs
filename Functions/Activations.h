#ifndef ACTIVATIONS_H
#define ACTIVATIONS_H
#include "ActivationDesc.h"
#include <cmath>
#include <stdexcept>
using namespace std;

// #define max(x, y) ((x) > (y) ? (x) : (y))
class ActivationFunctions {
public:
    static double apply(Activation act, double x) {
        switch (act) {
            case Activation::ReLU:
                return max(0.0, x);
            case Activation::LeakyReLU:
                return max(0.01 * x, x);
            case Activation::Sigmoid:
                return 1.0 / (1.0 + exp(-x));
            case Activation::Lin:
                return x;
            default:
                throw std::invalid_argument("Invalid activation function");
        }
    }
};

#endif