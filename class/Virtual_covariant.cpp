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
	Derived *Copy() const {
		cout << "Derived::Copy()" << endl;
		return new Derived(*this);
	}
};

int main() {
  // Base instances
  //Base a;
  //Base *b = a.Copy();
  //delete (b);

	Derived d;

  // convert from derived to base
	Base &b = d;

	Base *b2 = b.Copy();
	delete b2;

	Base *b3 = d.Copy();
	delete b3;

  // derived to derived
	Derived *d2 = d.Copy();
	delete d2;

  //----------------------------------
  // !invalid! 
  // convert from base to derived
  //----------------------------------
	//Derived *d3 = b.Copy();
	//delete d3;

	Derived *d4 = dynamic_cast<Derived*>( b.Copy() );
	delete d4;

	return 0;
}

