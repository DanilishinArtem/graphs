
#include "Activations.h"

#define max(x, y) ((x) > (y) ? (x) : (y))

double ActivationFunctions::apply(Activation act, double x) {
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
