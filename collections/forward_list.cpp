// g++ -o forward_list forward_list.cpp -std=c++11

#include <forward_list>
#include <iostream>
using namespace std;

int main() {
  forward_list<int> fwd_lst = {1,2,3};

  forward_list<int>::iterator it; 
  for (it = fwd_lst.begin(); it != fwd_lst.end(); it++)
    cout << *it << endl;

  return 0;
}
