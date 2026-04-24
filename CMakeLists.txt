
cmake_minimum_required(VERSION 3.10)
project(m0ss1_attendance)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Use g++-13 if available
set(CMAKE_CXX_COMPILER g++-13)

add_executable(code main.cpp)
