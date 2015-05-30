#include <string>
#include <iostream>
using namespace std;

class Person
{
private:
    string m_strName;
    int m_nAge;
    bool m_bIsMale;
 
public:
    // constructor
    Person(string strName = "", int nAge = 0, bool bIsMale = false)
        : m_strName(strName), m_nAge(nAge), m_bIsMale(bIsMale)
    {}

    string GetName() { return m_strName; }

    int GetAge() { return m_nAge; }

    bool IsMale() { return m_bIsMale; }

    virtual void display() {
      cout << "Name: " << GetName() 
           << " Age:  " << GetAge()
           << " Sex:  " << IsMale();
    }
 
};

// BaseballPlayer publicly inheriting Person
class BaseballPlayer : public Person
{
public:
    double m_dBattingAverage;
    int m_nHomeRuns;
 
    BaseballPlayer(string strName = "", int nAge = 0, bool bIsMale = false,
        double dBattingAverage = 0.0, int nHomeRuns = 0)
        // call Person(string, int, bool) to initialize these fields
        : Person(strName, nAge, bIsMale), 
          m_dBattingAverage(dBattingAverage),
          m_nHomeRuns(nHomeRuns)
    {
    }

    void display() {
      Person::display();
      cout << " Home runs: " << m_nHomeRuns << endl;
    }
};

int main()
{
  // two equivalent ways to create an object
    BaseballPlayer p1("Pedro Cerrano", 32, true, 0.342, 42);
    p1.display();

    BaseballPlayer p2 = BaseballPlayer("Pedro Cerrano", 35, true, 0.342, 42);
    p2.display();
 
    BaseballPlayer p3;
    p3.display();

    /* not allowed
    p3.BaseballPlayer("Pedro Cerrano", 38, true, 0.342, 42);
    */

    return 0;
}

