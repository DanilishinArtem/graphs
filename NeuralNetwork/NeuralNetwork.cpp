#include "NeuralNetwork.h"

NeuralNetwork::NeuralNetwork(const std::vector<std::pair<int, Activation>>& config) {
    for(int i = 0; i < config.size(); i++) {
        std::vector<Node*> layer;
        for(int j = 0; j < config[i].first; j++) {
            if(i == 0) {
                layer.push_back(new InputNode());
            } else {
                layer.push_back(new HiddenNode(layers.back(), config[i].second));
            }
        }
        if(i != config.size() - 1) {
            layer.push_back(new BiasNode());
        }
        layers.push_back(layer);
    }
}

double NeuralNetwork::forward(std::vector<double>& inputs_data) {
    for(int i = 0; i < inputs_data.size(); i++) {
        layers[0][i]->current_value = inputs_data[i];
    }
    return layers.back()[0]->forward();
}

void NeuralNetwork::backward() {
    for (int i = layers.size() - 1; i >= 1; --i) {
        for(int j = 0; j < layers[i].size(); j++) {
            layers[i][j]->backward();
        }
    }
}

void NeuralNetwork::step(double learningRate) {
    for(int i = 0; i < layers.size(); i++) {
        for(int j = 0; j < layers[i].size(); j++) {
            layers[i][j]->step(learningRate);
        }
    }
}

void NeuralNetwork::zero_grad() {
    for(int i = 0; i < layers.size(); i++) {
        for(int j = 0; j < layers[i].size(); j++) {
            layers[i][j]->zero_grad();
        }
    }
}

NeuralNetwork::~NeuralNetwork() {
    for (auto& layer : layers) {
        for (auto& node : layer) {
            delete node;
        }
    }
}
