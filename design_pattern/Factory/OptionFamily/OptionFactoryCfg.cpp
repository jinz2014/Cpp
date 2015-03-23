#include "OptionFactoryCfg.h"

ExactEuropeanOption* OptionFactoryCfg::createExactEuropeanOption() {
  return new ExactEuropeanOption();
}


ExecutiveOption* OptionFactoryCfg::createExecutiveOption() {
  return new ExecutiveOption();
}
