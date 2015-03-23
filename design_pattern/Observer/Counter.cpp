#include "Counter.h"

Counter::Counter() {
  count = 0;
}

long Counter::getVal() const {
  return count;
}

void Counter::increment() {
  count++;
  notifyObservers();
}

