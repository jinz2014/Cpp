#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <class A, class B, class R>
struct my_binary_function {
  typedef A arg1_type;
  typedef B arg2_type;
  typedef R res_type;
};


// Average of two arguments
template <class T>
class Average : my_binary_function<T, T, T> {
  public:
    typename my_binary_function<T,T,T>::res_type operator() ( 
        typename my_binary_function<T,T,T>::arg1_type a, 
        typename my_binary_function<T,T,T>::arg2_type b) {
      return (a + b) * 0.5;
    }
};

template <class T>
class Equal : my_binary_function<T, T, bool> {
  public:
    typename my_binary_function<T,T,bool>::res_type operator() (
        typename my_binary_function<T,T,bool>::arg1_type a, 
        typename my_binary_function<T,T,bool>::arg2_type b) {
      return a == b ? true : false;
    }
};

int main() {
  vector<double>v1(10, 2.1);
  vector<double>v2(v1); 
  vector<double>v3(v1.size());


  transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), Average<double>());

  vector<double>::iterator i;
  for (i = v3.begin(); i != v3.end(); i++)
    cout << *i << " ";
  cout << endl;

  v2[5] = 2.2;
  transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), Equal<double>());
  for (i = v3.begin(); i != v3.end(); i++)
    cout << *i << " ";
  cout << endl;
}
