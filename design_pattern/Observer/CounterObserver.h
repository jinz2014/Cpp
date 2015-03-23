#ifndef COUNTER_OBSERVER_H
#define COUNTER_OBSERVER_H

#include "Observer.h"
#include "Counter.h"

class CounterObserver : public Observer {
  public:
    CounterObserver(Counter& obj);
    virtual void update(Observable* obj);
};
#endif
