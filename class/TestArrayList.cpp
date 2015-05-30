#include <iostream>
#include <cassert>
#include "ArrayList.cpp"

using namespace std;


int main() {
  ArrayList<int> list(5);
  assert(list.isEmpty() == true);
  list.insert(20).insert(6).insert(10);
  list.insert(1,8);
  assert(list.length == 4);

  cout << list << endl;

  int e = 8;
  assert(e == list.get(1));

  list.remove(2);
  cout << list << endl;

  list.remove(0);
  cout << list << endl;

  // check clone
  ArrayList<int> list1 = list.clone();
  list1.set(0, 1);
  cout << "cloner: " << list << endl;
  cout << "clonee: " << list1 << endl;

  int *a = list1.toArray();
  for (int i = 0; i < list1.length; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
  delete[] a;

  return 0;
}
