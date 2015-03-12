#include <deque>                                                       
#include <algorithm>                                            
#include <iostream>                                                        
#include <cassert>                                                        
using namespace std;                                                    

class Object {
public:
  int value;
  // redefine the '<' operator, so when 2 Object objects are
  // compared, the 'value' fields of the objects are compared.
  const bool operator<(const Object &rhs) const
        { return this->value < rhs.value; }

  // construtor
  Object(int v) {
    value = v;
  }
};
                                                                       
int main()                                                                 
{                                                             
 deque<Object> Q;       //  An empty, elastic, container.

 for (int i = 2; i >= 0; i--) {
   Object s(i);
   Q.push_back(s); 
 }

 for(int i=0;i<Q.size(); i++){
   cout << Q[i].value;
   cout << " ";
 }
 cout <<endl;

 // Sort uses the '<' operator that we created in the 'Object' class   
 sort(Q.begin(), Q.end());

 // iterator style
 deque<Object>::iterator it;
 for (it = Q.begin();it != Q.end(); it++) {
   cout << it->value;
   cout << " ";
 }
 cout <<endl; 

 // Output: 0 1 2
}

