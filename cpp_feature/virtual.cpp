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

    // pure virtual func
    virtual int area (void) =0;    

    virtual void Foo(int x) {
      cout << "base: " << x << endl;
    }

    virtual void Foo(int x, int y) {
      cout << "base: " << x << endl;
      cout << "base: " << y << endl;
    }

    void printarea (void) { cout << this->area() << endl; }
};

class CRectangle: public CPolygon {
  public:
    int area (void) { return (width * height); }

    // override Foo(int x), but Hides the other!
    virtual void Foo(int x) {
      cout << "rect: " << x << endl;
    }

    // bring the other Foo functions into scope 
    using CPolygon::Foo;
};

class CTriangle: public CPolygon {
  public:
    int area (void) { return (width * height / 2); }
    virtual void Foo(int x) {
      cout << "triangle: " << x << endl;
    }
          
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

  ppoly1->Foo(1);
  ppoly1->Foo(1, 2);
  ppoly2->Foo(2);
  ppoly2->Foo(2, 3);

  CRectangle *prect1 = new CRectangle; 
  prect1->Foo(1);

  // Without using CPolygon::Foo; 
  // The compiler reports error:
  // No matching function call ... candidate expects 1 argument
  prect1->Foo(1,2);

  return 0;
}
