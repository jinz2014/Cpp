#include <iostream>
using namespace std;

class Rational {
  private:
    int num;
    int denom;

  public:
    //explicit 
      Rational (int num = 0, int denom = 1) 
      : num(num), denom(denom) {}

    operator double() const {
      return static_cast<double>(num) / denom;
    }
};

int main() {
  Rational r1(1,2);
  double d = 2;
  // implicit conversion from Rational to double
  cout << d + r1 << endl;

  // allows ints to be converted to Rational only when
  // the class constructor has default parameter values
  //
  // However, this is not allowed when the constructor is explicit
  Rational r2 = 5;
}
