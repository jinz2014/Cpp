#ifndef COUNTER_H
#define COUNTER_H

#include "Observable.h"

// Counter is a observable object

class Counter : public Observable {
  private:
    long count;
  public:
    Counter();
    long getVal() const;
    void increment(); 
};

#endif
