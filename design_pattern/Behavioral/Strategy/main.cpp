#include <iostream>
#include "Duck.h"
#include "ModelDuck.h"
#include "MallardDuck.h"
int main() {
    Duck* duck;
    duck = new MallardDuck();
    duck->display();
    duck->performQuack();
    duck->performFly();
    delete duck;
    duck = new ModelDuck();
    duck->display();
    duck->performQuack();
    duck->performFly();
    delete duck;
    return 0;
}
