#ifndef STRATEGY_PATTERN_MODELDUCK_H
#define STRATEGY_PATTERN_MODELDUCK_H

#include "Duck.h"
class ModelDuck:public Duck{
public:
   ModelDuck();
   ~ModelDuck();
   void display();
};


#endif //STRATEGY_PATTERN_MODELDUCK_H
