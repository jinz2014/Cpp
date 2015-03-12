// for_each example
#include <iostream>     // cout
#include <algorithm>    // for_each
#include <vector>       // vector
#include <iterator>       // vector
#include <fstream>       // vector

using namespace std;

void myStringFunction (string s) {  // function:
    cout << ' ' << s + ";";
}

void myfunction (int i) {
    cout << ' ' << i;
}

struct mystruct {           // function object type:
    void operator() (int i) {
      cout << ' ' << i;
    }
} myobject;

class myclass {           // function object type:
  public:
    void operator() (int i) {
      cout << ' ' << i;
    }
};

int main () {
  vector<int> myvector;
  myvector.push_back(10);
  myvector.push_back(20);
  myvector.push_back(30);

  cout << "myvector contains:";
  for_each (myvector.begin(), myvector.end(), myfunction); // function pointer
  cout << '\n';

  cout << "myvector contains:";
  for_each (myvector.begin(), myvector.end(), myobject); // struct
  cout << '\n';

  //myclass f = myclass();
  cout << "myvector contains:";
  for_each (myvector.begin(), myvector.end(), myclass()); // class
  cout << '\n';

  // display input file
  typedef istream_iterator<string> in;
  typedef ostream_iterator<string> out;

  ifstream ifs("data.txt");
  for_each(in(ifs), in(), myStringFunction);
  // ifstream has no member seekp: ifs.seekp(0);
  ifs.close();

  // data.txt must be closed before reading from the start
  // read input file to a container
  vector<string> txt;
  copy(in(ifs),  in(), back_inserter(txt));

  // sort the container
  sort(txt.begin(), txt.end());

  // write the container data to a file
  fstream fs("sorted_data.txt");  // i/o operation
  copy(txt.begin(), txt.end(), out(fs, " "));
  fs.seekp(0); // must close the file

  // display output file
  for_each(in(fs), in(), myStringFunction);

  return 0;
}
