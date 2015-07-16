#include <iostream>
#include <vector>
#include <algorithm>

// vector has no push_front/pop_front methods

using namespace std;

void display(string name, const vector<int> &v) {
  cout << name << " ";
  vector<int>::const_iterator c_iter;
  for (c_iter = v.begin(); c_iter != v.end(); c_iter++)
    cout << *c_iter << " ";
  cout << endl;
}


int main() {

  // an empty vector
  vector<int> E = vector<int>();
  cout << "vector size : " << E.size() << endl;

  // a simple way
  vector<int> A(5, -1);

  // a verbose way
  //vector<int> A = vector<int>(5, -1);

  cout << "vector size : " << A.size() << endl;

  // random access of vector
  for (int i = 0; i < 5; i++)
    cout << A[i] << " ";
  cout << endl;

  //---------------------------------------------------------
  // Use (constant) iterator to iterate over (constant) 
  // vector or deque
  //---------------------------------------------------------

  display("A", A);

  /* a pointer variant
  vector<int> *p = &A;
  for (iter = p->begin(); iter !=p->end(); iter++)
    cout << *iter << " ";
  cout << endl;
  */

  const vector<int> B(2, 1);
  display("B", B);

  //---------------------------------------------------------
  // container insert 
  //---------------------------------------------------------
  int iarr[3] = {3, 2, 1};
  A.insert(A.begin(), 5);
  A.insert(A.begin()+A.size()/2, iarr, iarr+3);
  A.insert(A.end(), 5);
  A.insert(A.begin()+A.size()/2, B.begin(), B.end());
  display("A", A);

  //---------------------------------------------------------
  // container assignment 
  //---------------------------------------------------------
  vector<int> C = B;
  vector<int> D(B);
  C.insert(C.end(), B.begin(), B.end());
	display("C", C);
	display("D", D);
	display("B", B);

	//A.swap(C);



  //---------------------------------------------------------
  // container search using genetic algorithms <algorithm>
  //---------------------------------------------------------
  
  vector<int>::iterator iter;
  iter = find(A.begin(), A.end(), 2);
  if (iter != A.end()) cout << "find 2" << endl;  // 2

  iter = find(A.begin(), A.end(), 7);
  if (iter != A.end()) cout << "find 7" << endl;  // 0


  //---------------------------------------------------------
  // 2D container as a matrix
  //---------------------------------------------------------
  int r = 2, c = 3;
  typedef vector<int> Row; // One row of the matrix
  typedef vector<Row> Matrix; // Matrix: a vector of rows
  Matrix matrix(r,Row(c)); // The same matrix as above
  matrix[0][1] = 1;
  matrix[1][1] = 2;
  //matrix[1][3] = 3; // out-of-bound
  //matrix[2][1] = 3;

  return 0;
}
