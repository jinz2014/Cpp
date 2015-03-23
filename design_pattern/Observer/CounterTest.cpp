#include <cassert>

#include "Counter.h"
#include "CounterObserver.h"

int main() {

  Counter c1;
  c1.increment();
  assert(1 == c1.getVal());

  // 
  CounterObserver co1(c1);

  // increment the counter and notify the observer
  c1.increment();

  Counter c2;
  CounterObserver co2(c2);
  c2.increment();

  c1.increment();

  return 0;
}
