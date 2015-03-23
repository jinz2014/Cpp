#include "ExactEuropeanOptionFactory.h"
#include "ExactEuropeanOption.h"

Option* ExactEuropeanOptionFactory::createOption() {
  return new ExactEuropeanOption();
}
