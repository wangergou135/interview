#ifndef STRATEGY_PATTERN_MALLARDDUCK_H
#define STRATEGY_PATTERN_MALLARDDUCK_H

#include "Duck.h"

class MallardDuck:public Duck{
public:
   MallardDuck();
   ~MallardDuck();
   void display();
};
#endif //STRATEGY_PATTERN_MALLARDDUCK_H