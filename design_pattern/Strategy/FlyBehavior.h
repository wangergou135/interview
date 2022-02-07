#ifndef STRATEGY_PATTERN_FLYBEHAVIOR_H
#define STRATEGY_PATTERN_FLYBEHAVIOR_H
class FlyBehavior {
public:
    virtual void fly()=0;
};
class FlyNoWay:public FlyBehavior{
public:
    virtual void fly();
};
class FlyWithWings:public FlyBehavior{
public:
    virtual void fly();
};
#endif //STRATEGY_PATTERN_FLYBEHAVIOR_H
