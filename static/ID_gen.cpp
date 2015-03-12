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
    // ctor
    IDGenerator(int ID, bool setID) : ID(ID), setID(setID) {}

    // static member function cannot access non-static members
    static int GetNextID() { 
      // overshadow ID
      int ID = 5;
      return s_nNextID++; 
    }
};
 
// We'll start generating IDs at 1
int IDGenerator::s_nNextID = 1;
 
int main()
{
    for (int i=0; i < 5; i++)
        cout << "The next ID is: " << IDGenerator::GetNextID() << endl;
 
    return 0;
}

