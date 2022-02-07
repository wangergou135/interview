cmake_minimum_required(VERSION 3.0)
project(Strategy_Pattern)

set(CMAKE_CXX_STANDARD 11)

add_library(Duck Duck.cpp MallardDuck.cpp ModelDuck.cpp)
add_library(Behavior FlyBehavior.cpp  QuackBehavior.cpp)
target_link_libraries(Duck Behavior)

add_executable(Strategy_Pattern main.cpp)
target_link_libraries(Strategy_Pattern Duck)
