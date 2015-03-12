#include <iostream>
#include <map>
#include <string>
#include <cassert>

// 1 The use of subscriptor may cause an instance to be inserted into the map 
// 2 map defines a type value_type that represents its associated key/value pair
//   typedef map<string, int>::value_type pair;
// 3 key is unique

// map functions: size(), begin(), end(), empty(), insert()

using namespace std;

void display(map<string, int> &v) {
  map<string, int>::iterator iter;
  for (iter = v.begin(); iter != v.end(); iter++)
    cout << iter->first << " " << iter->second << endl;
  cout << endl;
}

int main() {
  map<string, int> word_count;

  word_count["Anna"] = 1;
  word_count["Danny"] = 2;
  word_count["Ben"] = 3;
  word_count["Cathy"] = 2;
  word_count["Ben"] = 4;   // key is unique, overriding Ben,3

  int count;
  count = word_count["Anna"];

  // This causes the pair ("Cam", 0) inserted into the map, as shown
  // by the size of the word_count
  count = word_count["Cam"];

  cout << "Size of map word_count: " << word_count.size() << endl;

  //---------------------------------------------------------
  // container search 
  //---------------------------------------------------------
  map<string, int>::iterator iter = word_count.find("Emma");
  // discover if the key Emma exists
  if (iter != word_count.end())
    count = (*iter).second;

  // Or use count (note the keys are unique)
  assert( 0 == word_count.count("Emma")); // not found
  assert( 1 == word_count.count("Anna")); // found


  for (iter = word_count.begin(); iter != word_count.end(); iter++) {
    if (iter->second == 2)
      cout << "When count = 2, key is " << iter->first << endl;
  }

  //---------------------------------------------------------
  // iterator's first and second 
  //---------------------------------------------------------
  if (!word_count.empty()) // if (word_count.size())
    display(word_count);

  //---------------------------------------------------------
  // fancy container insert 
  //---------------------------------------------------------
  typedef map<string, int>::value_type pair;
  word_count.insert(pair("the", 8));
  word_count.insert(pair("is", 5));
  word_count.insert(pair("the", 10));

  map<string, int> word_count2;
  word_count2.insert(word_count.begin(),word_count.end());
  display(word_count2);

  return 0;

}
