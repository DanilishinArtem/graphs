cmake_minimum_required(VERSION 3.12)

# example of CMakeLists.txt with installed matplotlibcpp17
project(plot)

find_package(Python3 COMPONENTS Interpreter Development)
find_package(pybind11 REQUIRED)
find_package(matplotlibcpp17 REQUIRED)

# add_executable(plotter plot.cpp)
add_library(plot plot.cpp)
target_include_directories(plot PUBLIC ${Python3_INCLUDE_DIRS})
target_link_libraries(plot ${Python3_LIBRARIES} pybind11::embed
                      matplotlibcpp17::matplotlibcpp17)
