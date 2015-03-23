#ifndef  OptionFactory_H
#define  OptionFactory_H

#include "Option.h"

class OptionFactory {
  public:
    virtual Option* createOption() = 0;
};

#endif
