// Notes
// First, even though Display is a friend of Storage, Display has no direct access to the *this pointer of Storage objects.
// Second, just because Display is a friend of Storage, that does not mean Storage is also a friend of Display. If you want two classes to be friends of each other, both must declare the other as a friend. 
// Finally, if class A is a friend of B, and B is a friend of C, that does not mean A is a friend of C.
#include <iostream>
using namespace std;
class Storage
{
private:
    int m_nValue;
    double m_dValue;
public:
    Storage(int nValue, double dValue)
    {
        m_nValue = nValue;
        m_dValue = dValue;
    }
 
    // Make the Display class a friend of Storage
    friend class Display;
};
 
class Display
{
private:
    bool m_bDisplayIntFirst;
 
public:
    Display(bool bDisplayIntFirst) { m_bDisplayIntFirst = bDisplayIntFirst; }
 
    void DisplayItem(Storage &cStorage)
    {
        if (m_bDisplayIntFirst)
            std::cout << cStorage.m_nValue << " " << cStorage.m_dValue << std::endl;
        else // display double first
            std::cout << cStorage.m_dValue << " " << cStorage.m_nValue << std::endl;
    }
};

int main()
{
    Storage cStorage(5, 6.7);

    Display cDisplay_f(false);
    cDisplay_f.DisplayItem(cStorage);
 
    Display cDisplay_t(true);
    cDisplay_t.DisplayItem(cStorage);

    return 0;
}

