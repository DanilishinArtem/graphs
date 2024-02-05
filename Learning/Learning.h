#ifndef LEARNING_H
#define LEARNING_H
#include <iostream>
#include "../Functions/DataGenerator.h"
#include "../NeuralNetwork/NeuralNetwork.h"
using namespace std;
// #include "../Functions/Derivatives.h"

class LearningProcess{
public:
    double learningRate;
    int epochs;
    double total_loss;
    double loss_function(double pred, double correct);
    double loss_function_der(double pred, double correct);
    LearningProcess(double learningRate_arg, int epochs_arg) {
        learningRate = learningRate_arg;
        epochs = epochs_arg;
    }
    void run(NeuralNetwork* nn, DataGen* dg);
};

#endif