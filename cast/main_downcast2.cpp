#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Security {
  public:
    virtual ~Security() {
      cout << "~Security()" << endl;
    }
};

class Stock : public Security {};

class Bond : public Security {};

class Investment : public Security {
  public:
    void special() {
      cout << "show an additional method" << endl;
    }
};

int main() {
  vector<Security*>p; // portfolio
  Investment *o1 = new Investment;
  Bond       *o2 = new Bond;
  Stock      *o3 = new Stock;

  p.push_back(o1);
  p.push_back(o2);
  p.push_back(o3);

  //--------------------------------------------------
  // dynamic_cast with pointer
  //
  // Dynamic cast implemented with dynamic_cast which
  // requires that the types is polymorphic, which in
  // turn requires that the class must have at least
  // one virtual function. 
  //--------------------------------------------------
  vector<Security*>::iterator i; // portfolio
  for (i = p.begin(); i != p.end(); i++) {
    Investment* cm = dynamic_cast<Investment*>(*i);
    if (cm)
      cm->special();
  }

  Security *bp = new Bond;
  Investment* s1 = dynamic_cast<Investment*>(bp);
  assert(s1 == 0);
  Bond* s2 = dynamic_cast<Bond*>(bp);
  assert(s2 != 0);

  delete bp;
  delete o1;
  delete o2;
  delete o3;

  return 0;
}
