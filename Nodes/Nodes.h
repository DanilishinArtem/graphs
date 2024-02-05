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
    std::vector<double> adam_grad;
    std::vector<double> adam_grad_sq;
    double current_value; 
    Activation act; 
    double gradient;
    double adam_grad_bias;
    double adam_grad_sq_bias; 
    double t = 0;

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
        t += 1;
        return current_value;
    }
    void backward() override {}
    void step(double learningRate) override {}
    void zero_grad() override {}
};

class BiasNode : public Node {
public:
    BiasNode(){
        current_value = 0;
        gradient = 0;
        adam_grad_bias = 0;
        adam_grad_sq_bias = 0;
        act = Activation::Lin;
    }
    double forward() override {
        t += 1;
        return current_value;
    }
    void backward() override {}
    void step(double learningRate) override {
        adam_grad_bias = 0.9 * adam_grad_bias + (1 - 0.9) * gradient;
        adam_grad_sq_bias = 0.999 * adam_grad_sq_bias + (1 - 0.999) * gradient * gradient;
        double bias_correction = 1 - pow(0.9, t);
        double bias_correction_sq = 1 - pow(0.999, t);
        current_value -= learningRate * (adam_grad_bias / bias_correction) / (sqrt(adam_grad_sq_bias / bias_correction_sq) + 1e-8);
        // current_value -= learningRate * ((adam_grad / bias_correction) / (adam_grad_sq / sqrt(bias_correction_sq + 1e-8)));
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
            adam_grad[i] = 0.9 * adam_grad[i] + (1 - 0.9) * weights_gradients[i];
            adam_grad_sq[i] = 0.999 * adam_grad_sq[i] + (1 - 0.999) * gradient * gradient;
            double bias_correction = 1 - pow(0.9, t);
            double bias_correction_sq = 1 - pow(0.999, t);
            weights_inputs[i] -= learningRate * (adam_grad[i] / bias_correction) / (sqrt(adam_grad_sq[i] / bias_correction_sq) + 1e-8);
        }
    }

    void zero_grad() override {
        for(int i = 0; i < weights_gradients.size(); i++) {
            weights_gradients[i] = 0;
        }
        gradient = 0;
    }
};


#endif