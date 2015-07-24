#include <iostream>
#include "primer.h"
using namespace cpp_primer;
using namespace std;

int main() {

  Matrix m1(3,4);
  cout << "Row dimension: " << m1.nrows() << endl;
  cout << "Col dimension: " << m1.ncols() << endl;
  m1.indgen();
  m1.show();

  matrix t2(3, vector<int>(4));
  matrix t3(3, vector<int>(4));
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 4; j++) {
      t2[i][j] = i*3 + j;
      t3[i][j] = i*3 + j + 1;
    }

  // test wrapper
  Matrix m2(t2);
  m2.show();

  Matrix m3(t3);
  m3.show();

  cout << "test add\n";
  m1 = m2 + m3;
  m1.show();

  cout << "test transpose\n";
  m1.transpose();
  m1.show();

  cout << "test multiplication\n";
  Matrix t4(3, 4, 2);
  Matrix t5(4, 3, 1);
  Matrix t6(3, 3, -1);
  t6 = t4 * t5;
  t6.show();


  return 0;
}
