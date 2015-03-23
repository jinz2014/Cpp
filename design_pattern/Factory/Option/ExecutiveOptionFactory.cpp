#include "ExecutiveOptionFactory.h"
#include "ExecutiveOption.h"  

Option* ExecutiveOptionFactory::createOption() {
  return new ExecutiveOption();
}

