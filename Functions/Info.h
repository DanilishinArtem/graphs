#ifndef INFO_H
#define INFO_H
#include "../NeuralNetwork/NeuralNetwork.h"
#include "../Functions/DataGenerator.h"
#include <iostream>

void showInfoPred(NeuralNetwork* nn, DataGen* dg);
void show_grads(NeuralNetwork* nn);
void show_weights(NeuralNetwork* nn);

#endif