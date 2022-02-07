#include "ModelDuck.h"
#include "QuackBehavior.h"
#include "FlyBehavior.h"
#include <iostream>
#include <memory>
ModelDuck::ModelDuck() {

    FlyNoWay *f_ptr = new FlyNoWay();
    QuackNoWay  *q_ptr = new QuackNoWay();
    setquackBehavior(q_ptr);
    setFlyBehavior(f_ptr);
}

ModelDuck::~ModelDuck() {}

void ModelDuck::display() {
    std::cout<<"I am a model. "<<std::endl;
}
