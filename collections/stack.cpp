
#include <iostream>
#include <stack>
#include <cassert>

// empty(), size(), 
// pop, top, push(item)

using namespace std;

int main() {
	stack<int> istack;
	int i;
	const int sz = 4;
	int a[sz]={0, 2, 4, 5};
	for (i = 0; i < sz; i++)
	  istack.push(a[i]);
	assert (istack.size() == sz);

	while (!istack.empty()) {
	  assert(istack.top() == a[--i]);
	  istack.pop();
	}
	assert (istack.size() == 0);
}
