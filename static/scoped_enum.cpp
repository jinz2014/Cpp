// C11 support
// g++ -std=c++11 -o scoped_enum scoped_enum.cpp

#include <iostream>

// enum that takes 16 bits
enum short_num: int16_t { A, B, C };
 
// color may be red (value 0), yellow (value 1), green (value 20), or blue (value 21)
enum color { red, yellow, green = 20, blue };
 
// In scoped enums, the enumerator name must be qualified by the enum type name. T
enum class altitude : char { 
 high='h',
 low='l' // C++11 allows the extra comma
}; 
 
// the constant d is 0, the constant e is 1, the constant f is 3
enum { d, e, f=e+2 };
 
//enumeration types (both scoped and unscoped) can have overloaded operators
// enum -> string conversion
std::ostream& operator<<(std::ostream& os, color c)
{
   switch(c) {
     case red    : os << "red";    break;
     case yellow : os << "yellow"; break;
     case green  : os << "green";  break;
     case blue   : os << "blue";   break;
     default     : os.setstate(std::ios_base::failbit);
   }
   return os;
}

std::ostream& operator<<(std::ostream& os, altitude al)
{
  return os << static_cast<char>(al);
}
 
int main()
{
   short_num n = A;
   std::cout << sizeof(n) << '\n';  // should be 2

   color c = red;
   std::cout << sizeof(c) << '\n';  // should be 4

   // In scoped enums, the enumerator name must be 
   // qualified by the enum type name. T
   altitude a = altitude::low;
               
   std::cout << "color = " << c << '\n'
             << "altitude = " << a << '\n'
             << "f = " << f << '\n';
}

