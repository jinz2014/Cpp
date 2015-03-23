#include <iostream>
using namespace std;

class Base {
	public:
	virtual ~Base() { 
		cout << "~Base()" << endl;
  }

	virtual Base* Copy() const {
		cout << "Base::Copy()" << endl;
		return new Base(*this);
	}
};

class Derived : public Base {
	public:
	~Derived() { 
		cout << "~Derived()" << endl;
  }

	Derived *Copy() const {
		cout << "Derived::Copy()" << endl;
		return new Derived(*this);
	}
};

// Base is a concrete class instead of an abstract class
int main() {

	Derived d;

  //----------------------
  // virtual disabled 
	Base b = d;
	Base *b0 = b.Copy();
	delete b0;

  //----------------------
  // virtual enabled 
	Base &b1 = d;

  // Derive's copy
	Base *b2 = b1.Copy();
	delete b2;

  // Derive's copy
	Base *b3 = d.Copy();
	delete b3;

  // normal derived to derived
	Derived *d2 = d.Copy();
	delete d2;

  // invalid convert from base to derived
	//Derived *d3 = b1.Copy();
	//delete d3;

  // valid convert from base to derived
	Derived *d3 = dynamic_cast<Derived*>(b1.Copy());
	delete d3; 

    
  // release d3 instance
  // ~Derived
  // Base

  // release b instance
  // Base

  // release d instance
  // ~Derived
  // Base

  /*
  // Base instances
  Base a;
  Base *b = a.Copy();
  delete (b);
  */


	return 0;
}

