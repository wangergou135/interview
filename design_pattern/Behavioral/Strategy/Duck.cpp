#include <iostream>
#include "Duck.h"
Duck::~Duck() {

}
void Duck::swim() {
    std::cout<<"As a duck, swim is a default skill!"<<std::endl;
}
void Duck::performFly() {
    flyBehavior_ptr->fly();
}

void Duck::performQuack() {
     quackBehavior_ptr->quack();
}
void Duck::setFlyBehavior(FlyBehavior* flyBehavior) {
    flyBehavior_ptr.reset(flyBehavior);
}

void Duck::setquackBehavior(QuackBehavior* quackBehavior) {
    quackBehavior_ptr.reset(quackBehavior);
}
