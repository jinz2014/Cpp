#include <iostream>
#include <cassert>
using namespace std;

class B {
  virtual void Test() {}  
  // add it so g++ doesn't report error of dynamic_cast
  // error: cannot dynamic_cast ‘pb’ (of type ‘class B*’) 
  // to type ‘class D*’ (source type is not polymorphic)

};

class D : public B {};

typedef unsigned char UBYTE;
typedef char BYTE;

B* class_upcast(D* pd) {
  B* pb1 = dynamic_cast<B*>(pd);

  B* pb2 = static_cast<B*>(pd);   // Safe conversion, D always contain all B

  return pb1;

}

D* class_downcast(B* pb) {
  D* pd1 = dynamic_cast<D*>(pb);

  D* pd2 = static_cast<D*>(pb);  // Not safe, D can have fields
                                 // and methods that are not in B.
                                 // programmer must verify pb
  return pd1;
}

void test_primitive() {
  BYTE ch;
  int i = 65;
  float f = 2.5;
  double dbl;

  ch = static_cast<char>(i);   // int to char
  dbl = static_cast<double>(f);   // float to double
  i = static_cast<UBYTE>(ch);  // byte to unsigned byte
}

int main() {
  B *b = new B();
  assert(0 == class_downcast(b)); 

  B *d = new D();
  assert(d == class_downcast(d)); 

  delete b;
  delete d;

  D *d1 = new D();
  assert(d1 == class_upcast(d1));

  delete d1;

  test_primitive();
}
