/* 
 * p359 C++ primer
 * Any modification of the value returned changes the actual object being
 * returned
 *
 * Use const to prevent modification of the returned value
 */

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

/*const*/ int & get_val (vector<int> &vi, int ix) {
  return vi[ix];
}


int main() {
  int ai[4] = {0,1,2,3};
  vector<int> vec (ai, ai+4);   // copy 4 elements of ai into vec

  for (int i = 0; i < 4; i++) {
    int inc_elem = ++get_val(vec, i); // apply increment on the ref
    cout << inc_elem << endl;
    assert(inc_elem == vec[i]);
  }
}

