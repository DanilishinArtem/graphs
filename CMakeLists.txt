cmake_minimum_required(VERSION 3.10)
project(MyProject)

# Устанавливаем стандарт языка C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Добавляем исполняемый файл main
add_executable(main main.cpp)

# Добавляем поддиректории для сборки
add_subdirectory(Functions)
add_subdirectory(Learning)
add_subdirectory(NeuralNetwork)
add_subdirectory(Nodes)

# Связываем цель main с библиотеками
target_link_libraries(main Functions Learning NeuralNetwork Nodes)