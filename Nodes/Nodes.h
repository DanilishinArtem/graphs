#ifndef NODES_H
#define NODES_H
#include <vector>
#include "../Functions/ActivationDesc.h"
#include "../Functions/Generator.h"
#include "../Functions/Derivatives.h"
#include "../Functions/Activations.h"

class Node {
public:
    std::vector<Node*> inputs; 
    std::vector<double> weights_inputs; 
    std::vector<double> weights_gradients; 
    double current_value; 
    Activation act; 
    double gradient; 

    virtual double forward() = 0;
    virtual void backward() = 0;
    virtual void step(double learningRate) = 0;
    virtual void zero_grad() = 0;
    virtual ~Node() {}
};

class InputNode : public Node {
public:
    InputNode(){
        current_value = 0;
    }
    double forward() override{
        return current_value;
    }
    void backward() override {}
    void step(double learningRate) override {}
    void zero_grad() override {}
};

class BiasNode : public Node {
public:
    BiasNode(){
        current_value = RandomGen::getVal();
        gradient = 0;
        act = Activation::Lin;
    }
    double forward() override {
        return current_value;
    }
    void backward() override {}
    void step(double learningRate) override {
        current_value -= gradient * learningRate;
    }
    void zero_grad() override {
        gradient = 0;
    }
};

class HiddenNode : public Node {
public:
    HiddenNode(std::vector<Node*> inputs_arg, Activation act_arg);
    
    double forward() override;

    void backward() override;

    void step(double learningRate) override {
        for(int i = 0; i < weights_inputs.size(); i++) {
            weights_inputs[i] -= learningRate * weights_gradients[i]; 
        }
    }

    void zero_grad() override {
        for(int i = 0; i < weights_gradients.size(); i++) {
            weights_gradients[i] = 0;
            gradient = 0;
        }
    }
};


#endif