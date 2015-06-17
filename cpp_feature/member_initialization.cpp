// member initialization
//
// In this example, class Cylinder has a member object whose 
// type is another class (base's type is Circle). Because objects
// of class Circle can only be constructed with a parameter, 
// Cylinder's constructor needs to call base's constructor, and 
// the only way to do this is in the member initializer list.

#include <iostream>
using namespace std;

class Circle {
  double radius;
  public:
    Circle(double r) : radius(r) { }
    double area() {return radius*radius*3.14159265;}
};

class Cylinder {
  Circle base;
  double height;
  public:
  // Circle base(r) create an object of Circle;
    Cylinder(double r, double h) : base (r), height(h) {}
    double volume() {return base.area() * height;}
};

int main () {
  Cylinder foo (10,20);

  cout << "foo's volume: " << foo.volume() << '\n';
  return 0;
}
