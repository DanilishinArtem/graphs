#ifndef NN_H
#define NN_H
#include <vector>
#include "../Nodes/Nodes.h"
using namespace std;

class NeuralNetwork {
public:
    std::vector<std::vector<Node*>> layers;

    NeuralNetwork(const std::vector<std::pair<int, Activation>>& config);

    double forward(std::vector<double>& inputs_data);

    void backward();

    void step(double learningRate);

    void zero_grad();

    ~NeuralNetwork();
};

#endif