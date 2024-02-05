#ifndef INFO_H
#define INFO_H
#include "../NeuralNetwork/NeuralNetwork.h"
#include "../Functions/DataGenerator.h"
#include <iostream>
using namespace std;

void showInfoPred(NeuralNetwork* nn, DataGen* dg, int N);
void show_grads(NeuralNetwork* nn);
void show_weights(NeuralNetwork* nn);
std::vector<double> predict(NeuralNetwork* nn, DataGen* dg);

#endif