/*
   
   quicksort(list lst):
     if lst.size() < 1
       return 1st;

       pivot=lst[0];
       lower =new list;
       higher=new list;
       foreach e in lst
        if (e < pivot)
          add e to lower list
        else
          add e to higher list

       sorted_lower = quicksort(lower)  
       sorted_higher = quicksort(higher)  
       return sorted_lower+ pivot + sorted_higher

   1 quicksort (none in-place implementation using list
     std::distance(std::list.begin(), ::list.end()) is equivalent
     to size()
 */

// g++ -o quicksort quicksort.cpp -std=c++11

#include <list>
#include <iostream>
#include <cassert>

using namespace std;

list<int> quicksort (list<int> lst) {

  if (distance(lst.begin(), lst.end()) < 2)
    return lst;

  list<int> lower, higher;
  list<int>::iterator it; 

  it = lst.begin();
  int pvt = *it++;
  assert(lst.front() == pvt);

  while (it != lst.end()) {
    if (*it < pvt) 
      lower.push_front(*it);
    else
      higher.push_front(*it);
    it++;
  }

  list<int> sorted;
  sorted = quicksort(lower);
  sorted.push_back(pvt);
  sorted.splice(sorted.end(), quicksort(higher));

  return sorted;
}


int main() {

  list<int> tin = {5,7,1,4,3,2,6};
  list<int> tout;

  tout = quicksort(tin);

  // list's inplace sort
  tin.sort();

  assert(tin.size() == tout.size());

  list<int>::iterator a,b; 
  for (a = tout.begin(), b = tin.begin(); 
      a != tout.end(); a++, b++)
    assert(*a == *b);
}








