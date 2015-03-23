#include <iostream>
#include "CounterObserver.h"

// associate the counter with its observer
CounterObserver::CounterObserver(Counter &c) {
  c.addObserver(this);
}

// Observable 
//
// When using dynamic_cast, the source type must be of type
// polymorphic, otherwise the compiler gives error. So
// the class Observable must have virtual function
// 
void CounterObserver::update (Observable* o) {
  Counter* p = dynamic_cast<Counter*>(o);
  if (p != NULL) {
    std::cout << "Update Event with value " << p->getVal() << std::endl;
  } else {
    std::cout << "Update Event with unknown Observable object " << p->getVal() << std::endl;
  }
};


