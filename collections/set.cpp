#include <iostream>
#include <set>
#include <string>


using namespace std;

  void display(set<string> &v) {
	set<string>::iterator iter;
	for (iter = v.begin(); iter != v.end(); iter++)
		cout << (*iter) << endl;
	cout << endl;
  }

int main() {
	set<string> my_set;
	my_set.insert("yesterday");
	my_set.insert("today");
	my_set.insert("tomorrow");
	my_set.insert("Today");
	my_set.insert("tomorrow");
	display(my_set);
  return 0;
}

