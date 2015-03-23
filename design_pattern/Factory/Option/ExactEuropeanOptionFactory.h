#ifndef  ExactEuropeanOptionFactory_H
#define  ExactEuropeanOptionFactory_H

#include "OptionFactory.h"

class ExactEuropeanOptionFactory : public OptionFactory {
  virtual Option* createOption();
};


#endif
