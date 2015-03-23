#include <cassert>
#include "ExecutiveOptionFactory.h"
#include "ExactEuropeanOptionFactory.h"

int main() {
  //
  // cannot declare f of an abstract class type!!
  //
  OptionFactory *f;
  Option* o;

  f = new ExecutiveOptionFactory();
  o = f->createOption();
  assert(2 == o->price());
  delete f;

  f = new ExactEuropeanOptionFactory();
  o = f->createOption();
  assert(4 == o->price());
}
