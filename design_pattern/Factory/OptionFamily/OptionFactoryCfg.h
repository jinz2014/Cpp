#ifndef  OptionFactoryCFG_H
#define  OptionFactoryCFG_H

#include "ExactEuropeanOption.h"
#include "ExecutiveOption.h"
#include "OptionFactory.h"

class OptionFactoryCfg : public OptionFactory {
  public:
    virtual ExactEuropeanOption* createExactEuropeanOption();
    virtual ExecutiveOption* createExecutiveOption();
};

#endif
