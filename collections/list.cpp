#include <list>
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;
using namespace std;

int main() {
  // not supported without c++11
  list<int> lst = {1,2,3};

  //------------------------------------------------
  // list<Type>::iterator rit;
  //------------------------------------------------
  list<int>::iterator it; 

  for (it = lst.begin(); it != lst.end(); it++)
    cout << *it;
  cout << endl;

  //------------------------------------------------
  // list<Type>::reverse_iterator rit;
  // support iteration from the back as compared to
  // the forward list
  //------------------------------------------------
  list<int>::reverse_iterator rit; 
  for (rit = lst.rbegin(); rit != lst.rend(); rit++)
    cout << *rit;
  cout << endl;


  //------------------------------------------------
  // insert_iterator needs <iterator>
  //------------------------------------------------
  list<int> src_list = {3,2,1};
  insert_iterator<list<int> > insert_it (lst, it);
  copy(src_list.begin(), src_list.end(), insert_it); 
  // 1 2 3 3 2 1
  for (it = lst.begin(); it != lst.end(); it++)
    cout << *it;
  cout << endl;

  return 0;
}
