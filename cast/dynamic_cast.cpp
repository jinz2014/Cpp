#include <iostream>
using namespace std;

class B {
  virtual void test() {}
};

class C : public B { };
class D : public C { };

class E : public B {
  virtual void test() {}
};

void upcast(D* pd) {
  C* pc = dynamic_cast<C*>(pd);   // ok: C is a direct base class
                                  // pc points to C subobject of pd 
  B* pb = dynamic_cast<B*>(pd);   // ok: B is an indirect base class
                                  // pb points to B subobject of pd

  cout << "pd = " << pd << endl;
  cout << "pc = " << pc << endl;
  cout << "pb = " << pb << endl;
}

void downcast(B* pb) {
  cout << "pb = " << pb << endl;

  C* pc = dynamic_cast<C*>(pb);   
  D* pd = dynamic_cast<D*>(pb);   
  E* pe = dynamic_cast<E*>(pb);   

  cout << "pc = " << pc << endl;
  cout << "pd = " << pd << endl;
  cout << "pe = " << pe << endl;
}

int main() {
  B *b = new B();
  C *c = new C();
  D *d = new D();
  upcast(d);

  downcast(b);
  
  B *b1 = new C();
  downcast(b1);

  delete b;
  delete c;
  delete b1;
}
