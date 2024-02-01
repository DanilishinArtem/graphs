#ifndef DERIVATIVES_H
#define DERIVATIVES_H
#include "ActivationDesc.h"
#include "../Functions/Activations.h"
#include "../Functions/Derivatives.h"
#include <cmath>
#include <stdexcept>

class DerivativeFunctions {
public:
    static double apply(Activation act, double x){
        switch (act) {
            case Activation::ReLU:
                return x > 0.0 ? 1.0 : 0.0;
            case Activation::LeakyReLU:
                return x > 0.0 ? 1.0 : 0.01;
            case Activation::Sigmoid:
                return 1.0 / (1.0 + exp(-x)) * (1.0 - 1.0 / (1.0 + exp(-x)));
            case Activation::Lin:
                return 1.0;
            default:
                throw std::invalid_argument("Invalid activation function");
        }
    }
};

#endif