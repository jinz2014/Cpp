#include <cassert>
#include "OptionFactoryCfg.h"

int main() {
  //
  // cannot declare f of an abstract class type!!
  //
  OptionFactory *f;
  ExecutiveOption* o1;
  ExactEuropeanOption* o2;

  f = new OptionFactoryCfg();

  o1 = f->createExecutiveOption();
  assert(2 == o1->price());

  o2 = f->createExactEuropeanOption();
  assert(4 == o2->price());

  delete f;
  delete o1;
  delete o2;
}
