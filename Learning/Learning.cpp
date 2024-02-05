#include "Learning.h"
#include "../Functions/Derivatives.h"

double LearningProcess::loss_function(double pred, double correct) {
    return 0.5 * (correct - pred) * (correct - pred);
}

double LearningProcess::loss_function_der(double pred, double correct) {
    return (pred - correct);
}

void LearningProcess::run(NeuralNetwork* nn, DataGen* dg) {
    double prediction;
    std::vector<double> data;
    data.resize(1);
    for(int i = 0; i < epochs; i++) {
        total_loss = 0;
        for(int j = 0; j < dg->x.size(); j++) {
            data[0] = dg->x[j];
            prediction = nn->forward(data);
            total_loss += LearningProcess::loss_function(prediction, dg->y[j]);
            nn->layers.back()[0]->gradient = LearningProcess::loss_function_der(prediction, dg->y[j]) * DerivativeFunctions::apply(nn->layers.back()[0]->act, nn->layers.back()[0]->current_value);
            nn->backward();
            nn->step(learningRate);
            nn->zero_grad();
        }
        cout << "value of loss for epoch " << i << ": " << total_loss << endl;
    }
}
