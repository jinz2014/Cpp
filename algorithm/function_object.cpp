#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <cmath>

using namespace std;

class GreaterThan {
  int val;

  public:
  GreaterThan(int val) : val(val) {}
  bool operator()(int n) { return n > val; }
};

// MSDN examples
class less_mag: public binary_function<double, double, bool> {
  public:
    bool operator() (double x, double y) {
      return fabs(x) < fabs(y);
    }
};

class adder: public unary_function<double, void> {
  public:
    int sum;
    adder() : sum(0) {}
    void operator() (double o) {
      sum += o;
    }
};

int main() {
  GreaterThan f1(4); // initilization

  cout << f1(3) << endl;

  GreaterThan f2 = GreaterThan(3);
  cout << f2(4) << endl;


  //
  vector<int> v;
  v.push_back(3);
  v.push_back(1);
  v.push_back(-1);
  v.push_back(4);

  sort(v.begin(), v.end(), less_mag());

  adder result = for_each(v.begin(), v.end(), adder());
  cout << "The sum is " << result.sum;

  return 0;
}
