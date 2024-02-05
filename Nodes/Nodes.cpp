#include "Nodes.h"


HiddenNode::HiddenNode(std::vector<Node*> inputs_arg, Activation act_arg){
    // Инициализация через аргументы
    inputs = inputs_arg;
    act = act_arg;
    // Инициализация остальных членов базового класса
    weights_inputs.resize(inputs.size());
    adam_grad.resize(inputs.size());
    adam_grad_sq.resize(inputs.size());
    weights_gradients.resize(inputs.size());
    for(int i = 0; i < inputs.size(); i++) {
        weights_inputs[i] = RandomGen::getVal();
        weights_gradients[i] = 0; // NormalGen::getVal()
        adam_grad[i] = 0;
        adam_grad_sq[i] = 0;
    }
    current_value = 0;
    gradient = 0;
}

double HiddenNode::forward() {
    t += 1;
    double tempSum = 0;   
    for (size_t i = 0; i < inputs.size(); i++) {
        tempSum += inputs[i]->forward() * weights_inputs[i];
    }
    current_value = tempSum;
    return ActivationFunctions::apply(act, tempSum);
}

void HiddenNode::backward() {
    for(int i = 0; i < inputs.size(); i++) {
        // double input_gradient = gradient * weights_inputs[i] * DerivativeFunctions::apply(inputs[i]->act, inputs[i]->current_value);
        double input_gradient = gradient * weights_inputs[i] * DerivativeFunctions::apply(act, current_value);
        inputs[i]->gradient += input_gradient;
        // weights_gradients[i] = input_gradient * inputs[i]->current_value; // Градиент для веса
        weights_gradients[i] = gradient * inputs[i]->current_value; // Градиент для веса
    }
}

