#include <iostream>
#include <cassert>
using namespace std;

class myclass {
  public:
    int _i;
    int _j;

    myclass() 
      : _i(0), _j(0) 
    {}

    myclass(int i, int j) 
      : _i(i), _j(j) 
    {}

    void display() {
      cout << "i = " << _i << " j = " << _j << endl;
    }
};

void add(int *p) {
  *p = *p + 1;
}

void add(int &r) {
  r = r + 1;
}

void add(myclass& r) {
  r._i++;
  r._j++;
}

void add(myclass* p) {
  p->_i++;
  p->_j++;
}


int main() {
  //------------------------------------------------------
  // Builtin primitives
  //------------------------------------------------------

  // C: change a variable's value via its pointer
  // C++: change a variable's value via its reference
  int nValue = 5;
  int nValue2 = 6;
   
  int &rnRef = nValue;
  cout << "addr of rnRef: " << &rnRef << endl;

  // assigns value 6 to nValue -- does NOT change the reference!
  // so reference is like a constant pointer
  rnRef = nValue2; 

  cout << "addr of nValue: " << &nValue << endl;
  cout << "addr of nValue2: " << &nValue2 << endl;
  cout << "addr of rnRef: " << &rnRef << endl;

  assert(&rnRef == &nValue);
  assert(nValue == nValue2);

  int nValue3 = 5;
  const int &c_rnRef = nValue3;
  //c_rnRef = 6; // illegal -- rnRef is const


  //add(rnRef);
  add(nValue);
  cout << nValue << endl;

  add(&nValue);
  cout << nValue << endl;

  //------------------------------------------------------
  // Class 
  //------------------------------------------------------
  myclass a;
  add(a);
  a.display();

  add(&a);
  a.display();

  return 0;
}
