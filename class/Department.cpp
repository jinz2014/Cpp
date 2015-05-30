// In an aggregation, we also add other subclasses to our complex aggregate class as member variables.
// However, these member variables are typically either references or pointers that are used to point 
// at objects that have been created outside the scope of the class. Consequently, an aggregate class
// usually either takes the objects it is going to point to as constructor parameters, 
// or it begins empty and the subobjects are added later via access functions or operators.
#include <string>
#include <iostream>
using namespace std;
 
class Teacher
{
private:
    string m_strName;
public:
    Teacher(string strName)
        : m_strName(strName)
    { }
 
    string GetName() { return m_strName; }
};

class Chair
{
private:
    string m_strName;
public:
    Chair(string strName)
        : m_strName(strName)
    { }
 
    string GetName() { return m_strName; }
};
 
 
class Department
{
private:
    Teacher *m_pcTeacher; // Assume this dept holds only one teacher
    Chair &m_rcChair; 
 
public:
    // what is default value for rcChair
    Department(Teacher *pcTeacher, Chair &rcChair)
        : m_pcTeacher(pcTeacher), m_rcChair(rcChair)
    {
    }

    void DisplayName() {
	    cout << "Teacher's name is " << m_pcTeacher->GetName() << endl;
	    cout << "Chair's name is " << m_rcChair.GetName() << endl;
    }
};
 
int main()
{
    // Create a teacher outside the scope of the Department
    Teacher *pTeacher = new Teacher("Bob"); // create a teacher
    Chair rChair("Matt"); // create a chair
    {
        // Create a department and use the constructor parameter to pass
        // the teacher to it.
        Department cDept(pTeacher, rChair);

	// test member function
        cDept.DisplayName();
 
    } // cDept goes out of scope here and is destroyed
 
    // pTeacher still exists here because cDept did not destroy it
    delete pTeacher;
}

