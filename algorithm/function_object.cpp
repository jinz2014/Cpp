#include <iostream>

using namespace std;

class gt_n {
  int value;

  public:
  gt_n(int val) : value(val) {}
  bool operator()(int n) { return n > value; }
};

int main() {
  gt_n f(4);
  cout << f(3) << endl;

  gt_n fo = gt_n(3);
  cout << fo(4) << endl;
}
