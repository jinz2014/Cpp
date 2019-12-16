#include <iostream>
#include <set>
#include <string>


using namespace std;

template<class T>
void display(set<T> &v) {
	typename set<T>::iterator iter;
	for (iter = v.begin(); iter != v.end(); iter++)
		cout << (*iter) << endl;
	cout << endl;
}

void test2 () {
	set<int> int_set;
	set<int>::iterator it;
	pair<set<int>::iterator, bool> ret;
	for (int i=1; i<=5; i++) int_set.insert(i*10);
	ret = int_set.insert(20);
	if (ret.second == false) it=ret.first;  // 'it' now points to element 20
	int_set.insert(it, 25);
	int_set.insert(it, 24);
	int_set.insert(it, 26);
	int myints[] = {5,10,15};
	int_set.insert(myints, myints+3);
	display(int_set);
}

void test1() {
	set<string> str_set;
	str_set.insert("yesterday");
	str_set.insert("today");
	str_set.insert("tomorrow");
	str_set.insert("Today");
	str_set.insert("tomorrow");
	display(str_set);
}

int main() {
	test1();
	test2();
	return 0;
}

