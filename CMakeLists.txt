cmake_minimum_required(VERSION 3.10)
project(MyProject)

# Добавляем исполняемый файл main
add_executable(main main.cpp)

# Добавляем поддиректории для сборки
add_subdirectory(Functions)
add_subdirectory(Learning)
add_subdirectory(NeuralNetwork)
add_subdirectory(Nodes)
find_package(Python3 COMPONENTS Interpreter Development)
find_package(pybind11 REQUIRED)
find_package(matplotlibcpp17 REQUIRED)

# Связываем цель main с библиотеками
target_link_libraries(main PRIVATE Functions Learning NeuralNetwork Nodes ${Python3_LIBRARIES} pybind11::embed /home/adanilishin/Graph/Plotter/libplot.a)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
