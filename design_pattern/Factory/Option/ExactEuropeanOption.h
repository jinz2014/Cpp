#ifndef  ExactEuropeanOption_H
#define  ExactEuropeanOption_H

#include "Option.h"

class ExactEuropeanOption : public Option {
  virtual double price() const;
};

#endif
