#ifndef  ExecutiveOptionFactory_H
#define  ExecutiveOptionFactory_H

#include "OptionFactory.h"

class ExecutiveOptionFactory : public OptionFactory {
  virtual Option* createOption();
};

#endif
