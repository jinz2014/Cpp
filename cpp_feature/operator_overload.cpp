// Notes
/*
First, at least one of the operands in any overloaded operator must be a user-defined type.
This means you can not overload the plus operator to work with one integer and one double.
However, you could overload the plus operator to work with an integer and a Mystring.

Second, you can only overload the operators that exist.
You can not create new operators. For example, you could not create an operator ** to do exponents.

Third, all operators keep their current precedence and associativity, regardless of what they're used for. 
For example, the bitwise XOR operator (^) could be overloaded to do exponents, 
except it has the wrong precedence and associativity and there is no way to change this.
*/ 

#include <iostream>
using namespace std;

class CVector {
  private:
    int x;
    int y;
  public:
    CVector() {}
    CVector(int a, int b) : x(a), y(b) {}

    CVector operator+ (const CVector &p) {
      CVector t;  // must provide default constructor above!
      t.x = x + p.x;
      t.y = y + p.y;
      return t;
    }

    friend CVector operator+ (const CVector& lhs, const CVector& rhs) {
      CVector temp;
      temp.x = lhs.x + rhs.x;
      temp.y = lhs.y + rhs.y;
      return temp;
    }

    /*
      The compiler reports error "must take zero or one argument" when
      the overload function is defined as a member function
      
      It also reports error when the function is defined outside the class
      as a non-member function

      So we must define the member or non-member function as 
      a friend of the class. 

    1 CVector operator+ (const CVector& lhs, const CVector& rhs);

    2 CVector operator+ (const CVector& lhs, const CVector& rhs) {
      CVector temp;
      temp.x = lhs.x + rhs.x;
      temp.y = lhs.y + rhs.y;
      return temp;
    }
    */
};



class MinMax
{
private:
    int m_nMin; // The min value seen so far
    int m_nMax; // The max value seen so far
 
public:
    MinMax(int nMin, int nMax)
    {
        m_nMin = nMin;
        m_nMax = nMax;
    }
 
    int GetMin() { return m_nMin; }
    int GetMax() { return m_nMax; }
 
    // friend : because m_nMin and m_nMax are private members!
    // If they are public, then remove the keyword friend.
    friend MinMax operator+(const MinMax &cM1, const MinMax &cM2);
    friend MinMax operator+(const MinMax &cM, int nValue);
    friend MinMax operator+(int nValue, const MinMax &cM);
};
 
MinMax operator+(const MinMax &cM1, const MinMax &cM2)
{
    // Get the minimum value seen in cM1 and cM2
    int nMin = cM1.m_nMin < cM2.m_nMin ? cM1.m_nMin : cM2.m_nMin;
 
    // Get the maximum value seen in cM1 and cM2
    int nMax = cM1.m_nMax > cM2.m_nMax ? cM1.m_nMax : cM2.m_nMax;
 
    return MinMax(nMin, nMax);
}
 
MinMax operator+(const MinMax &cM, int nValue)
{
    // Get the minimum value seen in cM and nValue
    int nMin = cM.m_nMin < nValue ? cM.m_nMin : nValue;
 
    // Get the maximum value seen in cM and nValue
    int nMax = cM.m_nMax > nValue ? cM.m_nMax : nValue;
 
    return MinMax(nMin, nMax);
}
 
MinMax operator+(int nValue, const MinMax &cM)
{
    // call operator+(MinMax, nValue)
    return (cM + nValue);
}
 
int main()
{
  // test CVector
  CVector c1(3,1);
  CVector c2(1,2);

  // for member operator overloads
  CVector r1 = c1 + c2;
  CVector r2 = c1.operator+(c2);

  // for non-member operator overloads 
  CVector r3 = r1 + r2;


  // test MinMax
    MinMax cM1(10, 15);
    MinMax cM2(8, 11);
    MinMax cM3(3, 12);
 
    MinMax cMFinal = cM1 + cM2 + 5 + 8 + cM3 + 16;
 
    std::cout << "Result: (" << cMFinal.GetMin() << ", " <<
        cMFinal.GetMax() << ")" << std::endl;
 
    return 0;
}

