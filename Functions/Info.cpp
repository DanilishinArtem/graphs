#include "Info.h"


void showInfoPred(NeuralNetwork* nn, DataGen* dg, int N){
    std::vector<double> data;
    data.resize(1);
    cout << "\n\nValues of x          Values of y          Values of network" << endl;
    for(int i = 0; i < N; i++) {
        data[0] = dg->x[i];
        cout << dg->x[i] << "                    " << dg->y[i] << "                    " << nn->forward(data) << endl;
    }
    cout << "-----------------------------------------------------------------\n\n" << endl;
}

void show_weights(NeuralNetwork* nn) {
    cout << "info about weiths:--------------------------------------" << endl;
    cout << "input: " << nn->layers[0][0]->current_value << endl;
    cout << "bias: " << nn->layers[0][1]->current_value << endl;
    for(int i = 1; i < nn->layers.size(); i++) {
        for(int j = 0; j < nn->layers[i].size(); j++) {
            cout << "layer: " << i << ", node: " << j << " " << endl;
            cout << "weights: " << endl;
            for(int k = 0; k < nn->layers[i][j]->weights_inputs.size(); k++) {
                cout << nn->layers[i][j]->weights_inputs[k] << endl;
            }
            cout << "out: " << nn->layers[i][j]->current_value << endl;
            cout << endl;
        }
    }
}

void show_grads(NeuralNetwork* nn) {
    cout << "info about grads:--------------------------------------" << endl;
    for(int i = 1; i < nn->layers.size(); i++) {
        for(int j = 0; j < nn->layers[i].size(); j++) {
            cout << "layer: " << i << ", node: " << j << " " << endl;
            cout << "weights_gradients: " << endl;
            for(int k = 0; k < nn->layers[i][j]->weights_gradients.size(); k++) {
                cout << nn->layers[i][j]->weights_gradients[k] << endl;
            }
            cout << endl;
        }
    }
}

std::vector<double> predict(NeuralNetwork* nn, DataGen* dg){
    std::vector<double> data;
    std::vector<double> out;
    data.resize(1);
        for(int i = 0; i < dg->x.size(); i++) {
        data[0] = dg->x[i];
        out.push_back(nn->forward(data));
    }
    return out;
}