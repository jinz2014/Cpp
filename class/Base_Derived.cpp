// C++ also gives us the ability to change a base member’s access specifier in the derived class without even redefining the member!
// This is done by simply naming the member (using the scope resolution operator) to have it’s access changed in the derived class under the new access specifier.
#include <iostream>
using namespace std;

class Base
{
private:
    int m_nValue;
    int m_nValue2;
 
public:
    Base(int nValue, int nValue2)
        : m_nValue(nValue), 
          m_nValue2(nValue2)
    {}
 
protected:
    void PrintValue() { cout << m_nValue << endl; }
    void PrintSumValue(bool flg) { 
	    if (flg) cout << (m_nValue + m_nValue2) << endl; 
    }
};

class Derived: public Base
{
public:
    Derived(int nValue, int nValue2)
        : Base(nValue, nValue2)
    {
    }
 
    // Base::PrintValue was inherited as protected, so the public has no access
    // But we CAN change it to public by declaring it in the public section.
    // No "()" for each function
    Base::PrintValue;
    Base::PrintSumValue;
};
int main()
{
    Derived cDerived(7, 8);
 
    // functions are public in Derived, so this is okay
    cDerived.PrintValue(); 
    cDerived.PrintSumValue(true); 
    return 0;
}


