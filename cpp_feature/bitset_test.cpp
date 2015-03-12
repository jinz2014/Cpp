#include <iostream>
#include <string>
#include <bitset>
#include <limits>
using namespace std ;
int main()
{
  string str = "00000100" ;
  //cout << bitset<numeric_limits<unsigned long>::digits>(str).to_ulong() << '\n' ;
  cout << bitset<8>(str).to_ulong() << '\n' ;
}
