// strings and c-strings
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class CharArray {
  public:
    // convert to a mutable char array
    CharArray(string s) {
      c = new char [s.length()+1];
      strcpy(c, s.c_str());
    }

    ~CharArray() {
      delete[] c;
    }

    char* get() { return c; }

  private:
    char *c;

};


int main () {
  string str ("Please split this sentence into tokens");
  CharArray c(str);

  // cstr now contains a c-string copy of str
  char * p = strtok (c.get(), " ");
  while (p != NULL) {
    cout << p << '\n';
    p = strtok(NULL, " ");
  }
  return 0;
}
