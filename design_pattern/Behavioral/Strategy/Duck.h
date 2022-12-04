#ifndef STRATEGY_PATTERN_DUCK_H
#define STRATEGY_PATTERN_DUCK_H


#include "QuackBehavior.h"
#include "FlyBehavior.h"
#include <memory>
class Duck {
public:
    virtual  ~Duck();
    void performFly();
    void performQuack();
    virtual void display()=0;
    void swim();
    void setFlyBehavior(FlyBehavior* flyBehavior);
    void setquackBehavior(QuackBehavior* quackBehavior) ;

protected:
    std::shared_ptr<FlyBehavior> flyBehavior_ptr;
    std::shared_ptr<QuackBehavior> quackBehavior_ptr;

};

#endif //STRATEGY_PATTERN_DUCK_H