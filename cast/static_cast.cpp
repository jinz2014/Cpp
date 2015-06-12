#include <iostream>
using namespace std;

class B {
  virtual void Test() {}  
  // add it so g++ doesn't report error of dynamic_cast
  // error: cannot dynamic_cast ‘pb’ (of type ‘class B*’) 
  // to type ‘class D*’ (source type is not polymorphic)

};

class D : public B {};

typedef unsigned char BYTE;

void f(B* pb, D* pd) {
  D* pd1 = dynamic_cast<D*>(pb);

  D* pd2 = static_cast<D*>(pb);  // Not safe, D can have fields
                                 // and methods that are not in B.
                                 // programmer must verify pb

  B* pb2 = static_cast<B*>(pd);   // Safe conversion, D always
                                 // contains all of B.
  cout << "pd1 = " << pd1 << endl;
  cout << "pd2 = " << pd2 << endl;
  cout << "pb2 = " << pb2 << endl;
}

void g() {
  char ch;
  int i = 65;
  float f = 2.5;
  double dbl;

  ch = static_cast<char>(i);   // int to char
  dbl = static_cast<double>(f);   // float to double
  i = static_cast<BYTE>(ch);
}

int main() {
  B *b = new B();
  D *d1 = new D();
  D *d2 = new D();
  f(b, d1); // pd1 = 0;

  delete b;
  b = d2; 
  f(b, d2);

  delete d1;
  delete d2;

  g();
}
