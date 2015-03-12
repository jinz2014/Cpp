#include <list>
#include <iostream>
using namespace std;

int main() {
  // not supported without c++11
  list<int> lst = {1,2,3};

  list<int>::iterator it; 

  for (it = lst.begin(); it != lst.end(); it++)
    cout << *it << endl;

  list<int>::reverse_iterator rit; 

  // support iteration from the back as compared to
  // the forward list
  for (rit = lst.rbegin(); rit != lst.rend(); rit++)
    cout << *rit << endl;

  return 0;
}
