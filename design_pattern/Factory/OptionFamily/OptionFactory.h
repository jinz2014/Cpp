#ifndef  OptionFactory_H
#define  OptionFactory_H

#include "Option.h"

class OptionFactory {
  public:
    virtual ExactEuropeanOption* createExactEuropeanOption() = 0;
    virtual ExecutiveOption* createExecutiveOption() = 0;
};

#endif
