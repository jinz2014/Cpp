#include <iostream>
using namespace std;

/* Notice how we appended =0 to virtual int area () instead of specifying an 
 * implementation for the function. This type of function is called a pure virtual
 * function, and all classes that contain at least one pure virtual function are
 * abstract base class
 */
class CPolygon {
  protected:
    int width, height;
  public:
    void set_values (int a, int b) { width=a; height=b; }
    virtual int area (void) =0;    // pure virtual func
    void printarea (void) { cout << this->area() << endl; }
};

class CRectangle: public CPolygon {
    public:
      int area (void) { return (width * height); }
};

class CTriangle: public CPolygon {
    public:
      int area (void) { return (width * height / 2); }
            
};

/*
CPolygon poly;

would not be valid for the abstract base class we have just declared,
because tries to instantiate an object. Nevertheless, the following pointers:

CPolygon * ppoly1;
CPolygon * ppoly2;

would be perfectly valid.

This is so for as long as CPolygon includes a pure virtual function and 
therefore it's an abstract base class.

However, pointers to this abstract 
base class can be used to point to objects of derived classes.
*/

int main () {
  /*
  CRectangle rect;
  CTriangle trgl;
  CPolygon * ppoly1 = &rect;
  CPolygon * ppoly2 = &trgl;
  */
  CPolygon * ppoly1 = new CRectangle; 
  CPolygon * ppoly2 = new CTriangle;

  ppoly1->set_values (4,5);
  ppoly2->set_values (4,5);
  ppoly1->printarea();
  ppoly2->printarea();
  return 0;
}
