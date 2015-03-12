#include <string>
using namespace std;

class Person
{
private:
    string m_strName;
    int m_nAge;
    bool m_bIsMale;
 
public:
    string GetName() { return m_strName; }
    int GetAge() { return m_nAge; }
    bool IsMale() { return m_bIsMale; }
 
    Person(string strName = "", int nAge = 0, bool bIsMale = false)
        : m_strName(strName), m_nAge(nAge), m_bIsMale(bIsMale)
    {
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
        : Person(strName, nAge, bIsMale), // call Person(string, int, bool) to initialize these fields
            m_dBattingAverage(dBattingAverage), m_nHomeRuns(nHomeRuns)
    {
    }
};

int main()
{
    BaseballPlayer cPlayer("Pedro Cerrano", 32, true, 0.342, 42);
    cout << cPlayer.GetName() << endl;
    cout << cPlayer.GetAge() << endl;
    cout << cPlayer.IsMale() << endl;
    cout << cPlayer.m_nHomeRuns;
 
    return 0;
}

