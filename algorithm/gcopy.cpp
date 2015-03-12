#include <algorithm>
#include <cassert>
#include <cstddef>  // size_t
#include <vector>  // size_t
#include <string>  // size_t

using namespace std;

//
// A intro to generic copy on arrays of different types
//
int main() {
  int a[] = {1, 2, 3};
  const size_t SIZE_int = sizeof a / sizeof a[0];
  int b[SIZE_int];

  string s[] = {"1", "2", "3", "4"};
  const size_t SIZE_str = sizeof s / sizeof s[0];
  string sb[SIZE_str];

  copy(a, a+SIZE_int, b);
  assert(equal(a,a+SIZE_int, b));

  copy(s, s+SIZE_str, sb);
  assert(equal(s,s+SIZE_str, sb));

   
  vector<int> v1(a, a+SIZE_int);
  vector<int> v2(SIZE_int);
  copy(v1.begin(), v1.end(), v2.begin());
  assert(equal(v1.begin(), v1.end(), v2.begin()));

}
