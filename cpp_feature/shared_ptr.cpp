//
// The process starts when the managed object is dynamically allocated, and the first shared_ptr ( sp1) is created to point to it; the shared_ptr constructor creates a manager object (dynamically allocated). The manager object contains a pointer to the managed object; the overloaded member functions like shared_ptr::operator-> access the pointer in the manager object to get the actual pointer to the managed object.  The manager object also contains 1 two reference counts:  The shared count counts the number of shared_ptr s pointing to the manager object, and the weak count counts the number of weak_ptrs pointing to the manager object. When sp1 and the manager object are first created, the shared count will be 1, and the weak count will be 0.  If another shared_ptr ( sp2)  is created by copy or assignment from sp1 , then it also points to the same manager object, and the copy constructor or assignment operator increments the shared count to show that 2 shared_ptr s are now pointing to the managed object. Likewise, when a weak pointer is created by copy or assignment from a shared_ptr or another weak_ptr for this object, it points to the same manager object, and the weak count is incremented.  Whenever a shared_ptr is destroyed, or reassigned to point to a different object, the shared_ptr destructor or assignment operator decrements the shared count. Similarly, destroying or reassigning a weak_ptr will decrement the weak count. Now, when the shared count reaches zero, the shared_ptr destructor deletes the managed object and sets the pointer to 0. If the weak count is also zero, then the manager object is deleted also, and nothing remains.  But if the weak count is greater than zero, the manager object is kept. If the weak count is decremented to zero, and the shared count is also zero, the weak_ptr destructor deletes the manager object. Thus the managed object stays around as long as there are shared_ptr s pointing to it, and the manager object stays around as long as there are either shared_ptr s or weak_ptr s referring to it.  Here's why the weak_ptr is more useful than a built-in pointer. It can tell by looking at the manager object whether the managed object is still there: if the pointer and/or shared count are zero, the managed object is gone, and no attempt should be made to refer to it. If the pointer and shared count are non-zero, then the managed object is still present, and weak_ptr can make the pointer to it available. This is done by a weak_ptr member function that creates and returns a new shared_ptr to the object; the new shared_ptr increments the shared count, which ensures that the managed object will stay in existence as long as necessary. In this way, the weak_ptr can point to an object without affecting its lifetime, but still make it easy to refer to the object, and at the same time, ensure that it stays around if someone is interested in it.  But shared_ptr and weak_ptr have a fundamental difference: shared_ptr can be used syntactically almost identically to a built-in pointer. However, a weak_ptr is much more limited. You cannot use it like a built-in pointer  — in fact, you can't use it to actually refer to the managed object at all! Almost the only things you can do are to interrogate it to see if the managed object is still there, or construct a shared_ptr from it. If the managed object is gone, the shared_ptr will be an empty one (e.g. it will test as zero); if the managed object is present, then the 
#include <iostream>
#include <memory>
#include <cassert>

using namespace std;

class Point {
  private:
    int x, y;
  public:
    Point(int x, int y) : x(x), y(y) {
      cout << "create the Point(" 
           << x << "," << y << ")\n";
    }
    Point() : x(0), y(0) {
      cout << "create the Point(" 
           << x << "," << y << ")\n";
    }
    ~Point() {
      cout << "destruction of the Point(" 
           << x << "," << y << ")\n";
    }
};

int main() {
  // raw pointer
  Point *p = new Point;
  delete p;

  // smart pointer
  auto sp = make_shared<Point>(1,2);
  //shared_ptr<Point> sp(new Point(1,2));

  cout << sp.use_count() << endl;

  //Point *p = sp;     // compiler error
  
  // owenership of object that is already allocated
  shared_ptr<Point> sp2(sp);

  cout << sp.use_count() << endl;     // 2
  cout << sp2.use_count() << endl;     // 2

  Point *p1 = sp.get();  // not recommended
  Point *p2 = sp2.get(); // not recommended
  assert(p1 == p2);

  // raw -> smart (to rewrite old c++ code such
  // that the new code uses smart pointers
  p = new Point(2,3);
  shared_ptr<Point> sp3(p);

  // replace the manager object with a new object
  sp3.reset(new Point(4,5));
  cout << sp3.use_count() << endl;  // 1

  sp3 = sp2;
  cout << sp3.use_count() << endl;  // 3

}
