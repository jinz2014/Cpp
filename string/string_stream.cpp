#include <ostream>
using namespace std;

int main() {

stringstream os;
os << "Hello ";
os << "World!";
cout << os.str();
 
os.str(""); // erase the buffer
os.clear(); // reset error flags
 
os << "World!";
cout << os.str();

string strValue;
os << "12345 67.89"; // insert a string of numbers into the stream
os >> strValue; // extract 1st value
cout << "value1 " << strValue << endl;
os >> strValue; // extract 2nd value
cout << "value2 " << strValue << endl;
cout << "whole string " << os.str() << endl; // print whole string!


}
