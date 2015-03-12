
#include <iostream>
#include <queue>
#include <cassert>

// empty(), size(), 
// top (priority queue only)
// front, back
// pop, push(item)

using namespace std;

int main() {
	queue<int> iqueue;
	int i;
	const int sz = 4;
	int a[sz]={0, 2, 4, 5};

	for (i = 0; i < sz; i++)
	  iqueue.push(a[i]);
	assert (iqueue.size() == sz);
	assert (iqueue.back() == a[sz-1]);

	i = 0;
	while (!iqueue.empty()) {
	  assert(iqueue.front() == a[i++]);
	  iqueue.pop();
	}

	assert (iqueue.size() == 0);

	//  0, 5
	cout << iqueue.front() << endl;
	cout << iqueue.back() << endl;
}

