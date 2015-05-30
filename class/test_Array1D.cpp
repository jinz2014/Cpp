#include <iostream>
#include <cassert>
#include "Array1D.cpp"

using namespace std;

int main() {
  // test base constructor
  Array1D<int> a(5);
  for (int i = 0; i < 5; i++)
    a[i] = i+1; // test overloaded []

  // test copy constructor
  Array1D<int> b(a);
  for (int i = 0; i < 5; i++)
    assert(b[i] == a[i]);

  // gdb shows that there is no assignment = operation.
  // It only calls copy constructor!
  Array1D<int> c = b;
  for (int i = 0; i < 5; i++)
    assert(c[i] == a[i]);

  // test assignment
  Array1D<int> d;
  d = b;
  for (int i = 0; i < 5; i++)
    assert(d[i] == a[i]);

  // test +
  Array1D<int> sum;
  sum = a + b;
  for (int i = 0; i < 5; i++)
    assert(sum[i]/2 == a[i]);

  // test +=
  a += a;
  a += b;
  for (int i = 0; i < 5; i++)
    assert(3*c[i] == a[i]);

  // test <<
  cout << a << endl;
  cout << c << endl;

  return 0;
}
