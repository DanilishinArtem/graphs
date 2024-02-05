#ifndef PLOTTER_H
#define PLOTTER_H
#include <vector>
#include <matplotlibcpp17/pyplot.h>

class Plotter {
public:
    void plot(std::vector<double> x, std::vector<double> y, std::vector<double> predictions, std::string path);
};

#endif