#ifndef  ExecutiveOption_H
#define  ExecutiveOption_H

#include "Option.h"

class ExecutiveOption : public Option {
  public:
    virtual double price() const;
};

#endif
