#include <iostream>

using namespace std;

typedef enum index {A, B, OP, R} index_t;

class static_enum {
	private:
		// in-class initialization of non-const static member is not allowed
		// i.e. static int s_nNextID = 1;
      
	 
	public:
		static index_t idx;

		// in-class initialization of const static member is allowed
    const static index_t iR = R;
    const static index_t iA = A;
    const static index_t iB = B;
    const static index_t iOP = OP;

    // ctor
    static_enum() {
    };

    // static member function cannot access non-static members
    static int GetNextID() { 
    }

    // nonstatic member function cannot access non-static members
    int getIndex() {
    }
};

// must be defined outside the class header file
index_t static_enum::idx = R;
 
// We'll start generating IDs at 1
//int IDGenerator::s_nNextID = 1;
 
int main()
{

  cout << static_enum::idx;
  cout << static_enum::iR;
  cout << static_enum::iA;
  cout << static_enum::iB;
 
  return 0;
}

