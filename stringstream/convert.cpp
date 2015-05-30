#include <iostream>
#include <sstream>
using namespace std;

template <typename T>
string NumberToString ( T Number ) {
  ostringstream ss;
  ss << Number;
  return ss.str();
}

template <typename T>
T StringToNumber ( const string &Text ) {
  istringstream ss(Text);
  T result;
  return ss >> result ? result : 0;
}

int main() {
  int n = 123;

  // type deduction doesn't work ...

  string s = NumberToString<int>(n);
  //string s = NumberToString(n);

  string ns = "123";
  int m = StringToNumber<int>(ns);
  //int m = StringToNumber(ns);

  cout << s << " " << m << endl;
}

