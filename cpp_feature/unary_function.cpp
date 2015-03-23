#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <class A, class R>
struct my_unary_function {
  typedef A arg_type;
  typedef R res_type;
};

class Greater1 : public my_unary_function<int, bool> {
  private:
    arg_type mark;

  public:
    Greater1(arg_type k = 10) {
      mark = k;
    }

    res_type operator() (arg_type k) {
      return (k > mark) ? true : false;
    }
};

template <class T1, class T2>
class Greater2 : public my_unary_function<T1, T2> {
  private:
    typename my_unary_function<T1,T2>::arg_type mark;

  public:
    Greater2(typename my_unary_function<T1,T2>::arg_type k = 10) {
      mark = k;
    }

    typename my_unary_function<T1,T2>::res_type operator() (
        typename my_unary_function<T1,T2>::arg_type k) {
      return (k > mark) ? true : false;
    }
};


int main() {
  vector<int> v;
  for (int i = 5; i < 20; i++) {
    v.push_back(i);
  }
  int num = count_if(v.begin(), v.end(), Greater1());
  cout << num << endl;

  num = 0;
  num = count_if(v.begin(), v.end(), Greater2<int, bool>());
  cout << num << endl;
}


