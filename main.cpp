#include <iostream>
#include <vector>
#include "Functions/ActivationDesc.h"
#include "NeuralNetwork/NeuralNetwork.h"
#include "Functions/DataGenerator.h"
#include "Functions/Info.h"
#include "Learning/Learning.h"

int main() {
    // std::vector<std::pair<int, Activation>> config = {{5, Activation::Sigmoid}, {10, Activation::Sigmoid}, {10, Activation::Sigmoid}, {10, Activation::Sigmoid}, {1, Activation::ReLU}};
    std::vector<std::pair<int, Activation>> config = {{1, Activation::Lin}, {2, Activation::Sigmoid}, {1, Activation::ReLU}};
    NeuralNetwork nn(config);
    int N = 500;
    DataGen dg(0, 0.1, N);
    showInfoPred(&nn, &dg);
    // info.show();
    LearningProcess lp(0.01, 10000);
    lp.run(&nn, &dg);
    showInfoPred(&nn, &dg);    
}