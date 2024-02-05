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
    int N = 100;
    DataGen dg(N);
    showInfoPred(&nn, &dg, 10);
    // show_weights(&nn);
    LearningProcess lp(0.01, 100);
    lp.run(&nn, &dg);
    showInfoPred(&nn, &dg, 10);   
    Plotter plot;
    std::vector<double> out = predict(&nn, &dg);
    plot.plot(dg.x, dg.y, out, "/home/adanilishin/Graph");
    // show_weights(&nn);
    // show_grads(&nn);
    return 0;
}