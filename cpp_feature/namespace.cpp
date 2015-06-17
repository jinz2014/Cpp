#include <iostream>
using namespace std;

// Foo.h
namespace Foo
{
    // This DoSomething() belongs to namespace Foo
    int DoSomething(int nX, int nY)
    {
        return nX + nY;
    }
} // namespace Foo

// Goo.h
namespace Goo
{
    // This DoSomething() belongs to namespace Goo
    int DoSomething(int nX, int nY)
    {
        return nX - nY;
    }
} // namespace Goo

// global namespace
int DoSomething(int nX, int nY)
{
  return nX * nY;
}


int main(void)
{
    cout << Foo::DoSomething(4, 3) << endl; // 7
    cout << Goo::DoSomething(4, 3) << endl; // 1

    cout << ::DoSomething(4, 3) << endl; // 12
    cout << DoSomething(4, 3) << endl; // 12
    return 0;
}

