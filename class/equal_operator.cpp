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
		Base(int v = 0) : x(v) {
      cout << "call Base default constructor" << endl;
    }

		// Add a copy constructor
		Base(const Base& rhs) : x(rhs.x) {
      cout << "call Base copy constructor" << endl;
    }

		void print(string n) {
			cout << n << " x = " << x << endl;
		}
};

class Derived : public Base {
	private:
		int y;

	public:
    // call Base contructor
		Derived(int v = 0) : Base(v), y(v) {}

		// Add a copy constructor
		// Derived(const Derived& rhs) : y(rhs.y) {}  // wrong copy
		Derived(const Derived& rhs) : Base(rhs), y(rhs.y) {}

		// Add a assignment operator
		Derived& operator=(const Derived& rhs) {
      cout << "call Dervied = operator" << endl; 
			if (this == &rhs) return *this;
      // call Base's assignment generated by the compiler
			static_cast<Base&>(*this) = rhs; 
			y = rhs.y;
			return *this;
		}

		void print(string n) {
			Base::print(n);
			cout << n << " y = " << y << endl;
		}
};

int main() {
	Derived d0(0), d1(1), d2(2);
	d0.print("d0"); // d0.x = 0, d0.y = 0
  d1.print("d1"); // d1.x = 1, d1.y = 1
  d2.print("d2"); // d2.x = 2, d2.y = 2

	// test Derived's assignment operator
	d0 = d1 = d2;
	d0.print("d0"); // d0.x = 0, d0.y = 2
	d1.print("d1"); // d1.x = 1, d1.y = 2

	// test Derived's copy operator
	Derived d3(d1); // d3.x = 1, d3.y = 2
	d3.print("d3");
}
