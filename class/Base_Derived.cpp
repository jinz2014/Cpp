// C++ also gives us the ability to change a base member’s access specifier in the derived class without even redefining the member!
// This is done by simply naming the member (using the scope resolution operator) to have it’s access changed in the derived class under the new access specifier.
#include <iostream>
using namespace std;

class Base
{
private:
    int m_nValue;
    int m_nValue2;
    int sum (int a, int b) {
      return a + b;
    }
 
public:
    Base(int nValue, int nValue2)
        : m_nValue(nValue), 
          m_nValue2(nValue2)
    {}
 
protected:
    void PrintValue() { 
      cout << m_nValue << endl;
      cout << m_nValue2 << endl;
    }

    void PrintSumValue(bool flg) { 
	    if (flg) 
        cout << sum(m_nValue, m_nValue2) << endl; 
    }
};

class Derived: public Base
{
public:
    Derived(int nValue, int nValue2)
        : Base(nValue, nValue2) {}
 
    // Add a new method
    void debug() {
      // call the inherited, protected method ? YES
      PrintValue();  
      PrintSumValue(true);

      // call the inherited, private member ? NO
      //cout << m_nValue << endl;
    }

    // Base::PrintValue was inherited as protected, so the class object has no access
    // Modify it to public by declaring it in the public section.
    // No "()" for each function
    Base::PrintValue;
    Base::PrintSumValue;
};

int main()
{
  Base cBase(1,2); 

  // is protected still public ? NO
  //cBase.PrintValue();

  Derived cDerived(7, 8);
  cDerived.debug(); 

  cDerived.PrintValue(); 
  cDerived.PrintSumValue(true); 
  return 0;
}


