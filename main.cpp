#include <iostream>
#include <vector>
#include "Functions/ActivationDesc.h"
#include "NeuralNetwork/NeuralNetwork.h"
#include "Functions/DataGenerator.h"
#include "Functions/Info.h"
#include "Learning/Learning.h"
#include "Plotter/plot.h"


int main() {
    std::vector<std::pair<int, Activation>> config = {{1, Activation::ReLU}, {2, Activation::ReLU}, {2, Activation::ReLU}, {1, Activation::ReLU}};
    NeuralNetwork nn(config);
    int N = 1000;
    DataGen dg(N);
    showInfoPred(&nn, &dg, 10);
    LearningProcess lp(0.01, 100);
    lp.run(&nn, &dg);
    showInfoPred(&nn, &dg, 10);   
    Plotter plot;
    std::vector<double> out = predict(&nn, &dg);
    plot.plot(dg.x, dg.y, out, "/home/adanilishin/Graph");
    return 0;
}