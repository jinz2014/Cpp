#include <iostream>
#include <cstring>
#include <cassert>
#include <string>

// automatic conversion from c-style char string to c++ string obj
// use .c_str() for conversion from c++ string obj to c-style char string 
// string concat is simply s1 + s2;
// .size() returns the length of the string
// provides string iterator

using namespace std;

int my_bad_strlen(char *s) {
  return 1;
}

int main() {
	string s1 ("Hello World");
	string s2="Bye World";

	cout << s1 << " " << s2 << endl;

	// automatic conversion
	const char *q = "a char array";
	s1 = q;
	
	// c_str returns a ptr to constant array
	const char *p = s2.c_str();

	// auto convert c-syste char string into a string obj
	const char *sp = "; ";
	string s3 = s1 + sp + s2;
	assert(s3.size() == s1.size() + strlen(sp) + s2.size());

	cout << s1 << " | " << s2 << " | " << s3 << endl;

	// use the string iterator
	string::iterator it;
	for (it = s3.begin(); it != s3.end(); it++)
		cout << (*it);
	cout << endl;

  // To deal with the incompatiable argument type
  //my_bad_strlen(sp);
  my_bad_strlen(const_cast<char*>(sp));
}

