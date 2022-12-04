#include "QuackBehavior.h"
#include <iostream>

void QuackNoWay::quack() {
    std::cout<<"<<Silence>>"<<std::endl;
}

void QuackNormal::quack(){
    std::cout<<"quack!" <<std::endl;
}
