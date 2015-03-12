#include <iostream>                                                        
using namespace std;                                                    

class A {
public:
	// a default constructor
	A() { 
		cout << "A: default constructor" << endl;
	}

	// this is not default constructor
	A(int x) { 
		cout << "A: constructor x = " << x << endl;
	}
};

class B {
	public:
	// default constructor can have a default value for every arg
	B(int x = 0) { 
		cout << "B: default constructor x = " << x << endl;
	}
};

int main() {
	A arrayA[5]; // call default constructor
	A *ptrArrayA[5]; // no default constructor
	for (int i = 0; i < 5; i++)
		ptrArrayA[i] = new A(i);
	for (int i = 0; i < 5; i++)
		delete ptrArrayA[i];
	B arrayB[5]; // call default constructor
	B instB(1); // call default constructor
}
