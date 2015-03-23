#include <iostream>

using namespace std;

class IDGenerator {
	private:
		// in-class initialization of non-const static member is not allowed
		// i.e. static int s_nNextID = 1;
		static int s_nNextID;
    int  ID;
    bool setID;
      
	 
	public:
    // dtor
    ~IDGenerator() {
      s_nNextID--;
    }

    // ctor
    IDGenerator(int ID, bool setID) : ID(ID), setID(setID) {
      s_nNextID++;
    }

    // static member function cannot access non-static members
    static int GetNextID() { 
       return s_nNextID; 
    }

    static int show() { 
       cout << "ID is " << s_nNextID << endl; 
    }
};
 
// We'll start generating IDs at 1
//int IDGenerator::s_nNextID = 1;
int IDGenerator::s_nNextID(1);
 
int main()
{
  IDGenerator ig1(1, true);
  IDGenerator ig2(2, true);
  ig1.show();
  IDGenerator::show();

  // introduce local objects using inner block
  {
    IDGenerator ig3(3, true);
    IDGenerator ig4(4, true);
    IDGenerator::show();
  }

  // local objects have been destroyed and ID counters decremented
  IDGenerator::show();
 
  return 0;
}

