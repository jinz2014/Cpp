#include <iostream>
#include <cstring>
#include <cassert>
#include <string>

// C++ string is mutable as compared to immutable Java string

using namespace std;

bool operator==(const string& lhs, const char *rhs) {
  string s2 = rhs;
  if (lhs.compare(s2) == 0) 
    return true;
   return false;
}

bool operator==(const string &lhs, const string& rhs) {
  if (lhs.compare(rhs) == 0) 
    return true;
   return false;
}

bool operator==(const char *lhs, const string& rhs) {
  string s1 = lhs;
  if (s1.compare(rhs) == 0) 
    return true;
   return false;
}

// Pass by reference, not pass by value
void reverse(string& s) {
  for (int i = 0; i < s.size()/2; i++) {
    char t = s[i];
    int end = s.size() - i - 1;
    s[i] = s[end];
    s[end] = t;
  }
}

int main() {
	string s1 ("Hello");
	string s2 ("olleH");
	string s3;
	string s4("");
  reverse(s1);

  assert(s3.empty() == true);
  assert(s4.empty() == true);

  cout << s1 << endl;
  assert(s1.compare(s2) == 0);
  assert(s2 == "olleH");
    
}

