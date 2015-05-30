// strings and c-strings
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main () {
  string str ("Please split this sentence into tokens");

  // convert to a mutable char array
  char * cstr = new char [str.length()+1];
  strcpy (cstr, str.c_str());

  // cstr now contains a c-string copy of str
  char * p = strtok (cstr," ");
  while (p != NULL) {
    cout << p << '\n';
    p = strtok(NULL," ");
  }

  delete[] cstr;
  return 0;
}
