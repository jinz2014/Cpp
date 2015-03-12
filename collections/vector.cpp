#include <iostream>
#include <vector>
#include <algorithm>

// vector has no push_front/pop_front methods

using namespace std;

  void display(vector<int> &v) {
	vector<int>::iterator iter;
	for (iter = v.begin(); iter != v.end(); iter++)
		cout << *iter << " ";
	cout << endl;
  }

void main() {
  vector<int> A(5, -1);
  const vector<int> B(2, 1);

  cout << "vector size : " << A.size() << endl;

  //---------------------------------------------------------
  // Use (constant) iterator to iterate over (constant) 
  // vector or deque
  //---------------------------------------------------------
  for (int i = 0; i < 5; i++)
    cout << A[i] << " ";
  cout << endl;

  vector<int>::iterator iter;
  for (iter = A.begin(); iter != A.end(); iter++)
    cout << *iter << " ";
  cout << endl;

  vector<int> *p = &A;
  for (iter = p->begin(); iter !=p->end(); iter++)
    cout << *iter << " ";
  cout << endl;

  // must use constant iterator for a constant vector
  vector<int>::const_iterator c_iter;
  for (c_iter = B.begin(); c_iter != B.end(); c_iter++)
    cout << *c_iter << " ";
  cout << endl;

  //---------------------------------------------------------
  // container insert 
  //---------------------------------------------------------
  int iarr[3] = {3, 2, 1};
  A.insert(A.begin(), 5);
  A.insert(A.begin()+A.size()/2, iarr, iarr+3);
  A.insert(A.end(), 5);
  A.insert(A.begin()+A.size()/2, B.begin(), B.end());
  display(A);

  //---------------------------------------------------------
  // container assignment 
  //---------------------------------------------------------
  vector<int> C = B;
  for (int i = 0; i < 2; i++) {
	  A.swap(C);
	  display(A);
	  display(C);
  }


  //---------------------------------------------------------
  // container search using genetic algorithms <algorithm>
  //---------------------------------------------------------
  
  iter = find(A.begin(), A.end(), 2);
  if (iter != A.end()) cout << "find 2" << endl;  // 2

  iter = find(A.begin(), A.end(), 7);
  if (iter != A.end()) cout << "find 7" << endl;  // 0

}
