#include <algorithm>
#include <iostream>
#include <vector>

// -std=c++11

using namespace std;

// This is the incorrect implementaion!
class FunctorClassBug
{
  public:
    // The required constructor for this example.
    explicit FunctorClassBug(int& evenCount) : m_evenCount(evenCount) { }

    // The function-call operator prints whether the number is
    // even or odd. If the number is even, this method updates
    // the counter. 
    void operator()(int n) {
      cout << n;
      if (n % 2 == 0) {
        cout << " is even " << endl;
        ++m_evenCount;
      } else {
        cout << " is odd " << endl;
      }
    }

  private:
    int m_evenCount; // the number of even variables in the vector.
};

// Without lambda
class FunctorClass
{
  public:
    // The required constructor for this example.
    explicit FunctorClass(int& evenCount) : m_evenCount(evenCount) { }

    // The function-call operator prints whether the number is
    // even or odd. If the number is even, this method updates
    // the counter. Notice it is a constant member function that
    // increments the reference variable m_evenCount
    void operator()(int n) const {
      cout << n;
      if (n % 2 == 0) {
        cout << " is even " << endl;
        ++m_evenCount;
      } else {
        cout << " is odd " << endl;
      }
    }

  private:
    int &m_evenCount; // the number of even variables in the vector.
};

int main() {
  vector<int> v;
  for (int i = 0; i < 10; i++) 
    v.push_back(i);

  // using Lambda
  int cnt = 0;
  for_each(v.begin(), v.end(), 
      [&cnt](int n) {
        cout << n << " is ";
        if (n % 2 == 0) {
          cout << "even" << endl;
          cnt++;
        } else {
          cout << "odd" << endl;
        }
      });
  cout << "Lambda: There are " << cnt << " even numbers\n";

  // using Functor
  cnt = 0;
  for_each(v.begin(), v.end(), FunctorClass(cnt));
  cout << "Functor: There are " << cnt << " even numbers\n";

  // using Buggy Functor
  cnt = 0;
  for_each(v.begin(), v.end(), FunctorClassBug(cnt));
  cout << "Functor: There are " << cnt << " even numbers\n";
}
