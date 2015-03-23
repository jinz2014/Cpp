#ifndef  ExactEuropeanOption_H
#define  ExactEuropeanOption_H

#include "Option.h"

class ExactEuropeanOption : public Option {
  public:
    virtual double price() const;
};

#endif
