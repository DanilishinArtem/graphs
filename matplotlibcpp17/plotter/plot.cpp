
#include "plot.h"

void Plotter::plot(std::vector<double> x, std::vector<double> y, std::vector<double> predictions, std::string path){
    pybind11::scoped_interpreter guard{};
    auto plt = matplotlibcpp17::pyplot::import();
    plt.plot(Args(x), Kwargs("color"_a = "blue", "linewidth"_a = 1.0));
    plt.plot(Args(y), Kwargs("color"_a = "red", "linewidth"_a = 1.0));
    plt.plot(Args(predictions), Kwargs("color"_a = "black", "linewidth"_a = 1.0));
    plt.savefig(Args(path + "/out.png"));
}