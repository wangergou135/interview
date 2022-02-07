#ifndef STRATEGY_PATTERN_QUACKBEHAVIOR_H
#define STRATEGY_PATTERN_QUACKBEHAVIOR_H
class QuackBehavior{
public:
    virtual void quack()=0;
};

class QuackNoWay:public QuackBehavior {
public:
    virtual void quack();
};


class QuackNormal:public QuackBehavior {
public:
    virtual void quack();
};
#endif //STRATEGY_PATTERN_QUACKBEHAVIOR_H
