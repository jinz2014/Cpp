#include <iostream>                                                        
using namespace std;                                                    
//
// How to write copy constructor and assignment= operator for the Derived class
// when the data member of the Base class is private and the Derived class adds
// more data members
// 
// 1. Derived's copy constructor must call Base's copy constructor
class Base {
	private:
		int x;

	public:
    // default constructor with default argument value
		Base(int v = 0) : x(v) {}

		// Add a copy constructor
		Base(const Base& rhs) : x(rhs.x) {}

		void print() {
			cout << "x = " << x << endl;
		}
};

class Derived : public Base {
	private:
		int y;

	public:
		Derived(int v = 0) : Base(v), y(v) {}

		// Add a copy constructor
		// Derived(const Derived& rhs) : y(rhs.y) {}  // wrong copy
		Derived(const Derived& rhs) : Base(rhs), y(rhs.y) {}

		// Add a assignment operator
		Derived& operator=(const Derived& rhs) {
			if (this == &rhs) return *this;
			static_cast<Base&>(*this) = rhs;
			y = rhs.y;
			return *this;
		}
		void print() {
			Base::print();
			cout << "y = " << y << endl;
		}
};

int main() {
	Derived d0(0), d1(1), d2(2);
	d0.print(); d1.print(); d2.print();
	// test Derived's assignment operator
	d0 = d1 = d2;
	d0.print(); 
	d1.print(); 

	// test Derived's copy operator
	Derived d3(d1);
	d3.print();
}
