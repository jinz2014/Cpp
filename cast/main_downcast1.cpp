#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Security {
  protected:
    enum { BASEID = 0 };
  public:
    virtual ~Security() {
      cout << "~Security()" << endl;
    }
    virtual bool isA(int id) { return (id == BASEID); }
};

class Stock : public Security {
  protected:
    enum { OFFSET = 1, TYPEID = BASEID + OFFSET };
  public:
    bool isA(int id) { 
      return (id == TYPEID || Security::isA(id));
    }

    // downcast from base to derived
    static Stock* dynacast(Security* s) {
      return s->isA(TYPEID) ? static_cast<Stock*>(s) : 0;
    }

};

class Bond : public Security {
  protected:
    enum { OFFSET = 2, TYPEID = BASEID + OFFSET };
  public:
    bool isA(int id) { 
      return (id == TYPEID || Security::isA(id));
    }
    static Bond* dynacast(Security* s) {
      return s->isA(TYPEID) ? static_cast<Bond*>(s) : 0;
    }
};

class Investment : public Security {
  protected:
    enum { OFFSET = 3, TYPEID = BASEID + OFFSET };
  public:
    bool isA(int id) { 
      return (id == TYPEID || Security::isA(id));
    }
    static Investment* dynacast(Security* s) {
      return s->isA(TYPEID) ? static_cast<Investment*>(s) : 0;
    }
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
  // Dynamic cast implemented with static_cast, 
  // TYPEID of each class
  //--------------------------------------------------
  vector<Security*>::iterator i; // portfolio
  for (i = p.begin(); i != p.end(); i++) {
    // get Investment product from all Security products
    Investment* cm = Investment::dynacast(*i);
    if (cm)
      cm->special();
  }

  Security *bp = new Bond;
  Investment* s1 = Investment::dynacast(bp);
  assert(s1 == 0);
  Bond* s2 = Bond::dynacast(bp);
  assert(s2 != 0);


  delete bp;
  delete o1;
  delete o2;
  delete o3;

  return 0;
}
