#ifndef ObSERVER_H
#define ObSERVER_H

class Observer;
#include "Observable.h"

class Observer {
  public:
    virtual void update(Observable* o) = 0;
};

#endif

