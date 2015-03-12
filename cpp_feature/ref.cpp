#include <iostream>
#include <cassert>
using namespace std;

int main() {

int nValue = 5;
int nValue2 = 6;
 
int &rnRef = nValue;
cout << "addr of rnRef: " << &rnRef << endl;

// assigns value 6 to nValue -- does NOT change the reference!
// so reference is like a constant pointer
rnRef = nValue2; 
assert(&rnRef == &nValue);

cout << "addr of nValue: " << &nValue << endl;
cout << "addr of nValue2: " << &nValue2 << endl;
cout << "addr of rnRef: " << &rnRef << endl;

int nValue3 = 5;
const int &c_rnRef = nValue3;
//c_rnRef = 6; // illegal -- rnRef is const


    return 0;
}
