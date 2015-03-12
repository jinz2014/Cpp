#include <iostream>
#include <strstream>
#include <string.h>
#include <string>     // std::char_traits



using namespace std;

int main() {
 
  //char buf[20] = "Hello 3.1 2";
  char buf[20] = "3.1 2";

  istrstream istr(buf);


  double dval;
  int ival;
  
  istr >> dval >> ival; // extraction
  cout << dval << endl;
  cout << ival << endl;
  cout << "c strlen  = " << strlen(buf) << endl; // 5
  cout << "c++ strlen  = " << char_traits<char>::length(buf) << endl; // 5
  cout << "sizeof  = " << sizeof buf << endl; // 20

  // dynamic buffer
  ostrstream ostr1;
  ostr1 << ival << "-" << dval << ends;
  cout << ostr1.str() << endl;  

  // fixed size buffer
  ostrstream ostr2(buf, sizeof(buf));
  ostr2 << ival << "+" << dval << ends;
  cout << ostr2.str() << endl;

  return 0;
}
