cmake_minimum_required(VERSION 3.20)
project(MatrixCalculator)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES main.cpp Matrix.cpp)

set(HEADERS Matrix.h)

add_executable(MatrixCalculator ${SOURCES} ${HEADERS})
