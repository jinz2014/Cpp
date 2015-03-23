#ifndef  ExecutiveOption_H
#define  ExecutiveOption_H

#include "Option.h"

class ExecutiveOption : public Option {
  virtual double price() const;
};

#endif
