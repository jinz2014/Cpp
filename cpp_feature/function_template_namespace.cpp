#include <iostream>
#include "function_template_namespace.h"

// Add compiler flag: -fpermissive

class SmallInt {
  public:
    SmallInt() : value(0) {}
    SmallInt(int ival) : value(ival) {}
    void set(int ival) {
      value = ival;
    }
    friend bool lt (const SmallInt &a, const SmallInt &b);
    friend bool eq (const SmallInt &a, const SmallInt &b);
  private:
    int value;
};

bool lt (const SmallInt &a, const SmallInt &b) {
  return a.value < b.value;
}

bool eq (const SmallInt &a, const SmallInt &b) {
  return a.value == b.value;
}

// Define the template specialization outside its namespace definition
// This is all called explicit specialization definition
// 
// Requirement
// 1 the function must be qualified with the namespace
// 2 const qualifier is required for the array pointer as 
//   it is specified in the generic template functions

template<> SmallInt 
cpp_primer::min_value<SmallInt>(const SmallInt* arr, int size) {
  SmallInt v = arr[0]; 
  for (int i = 1; i < size; i++) {
    if (lt(arr[i], v))
      v = arr[i];
  }
  return v;
}


int main() {

  int a[] = {2, 3, 3, 5, 1, 8};
  std::cout << cpp_primer::min_value(a) << std::endl;
  std::cout << cpp_primer::min_value(a, sizeof(a)/sizeof(a[0])) << std::endl;
  float f[] = {2.0f, 2.9f, 3.1f, 5.14f, 1.0f, 0.99f};
  std::cout << cpp_primer::min_value(f) << std::endl;
  std::cout << cpp_primer::min_value(f, sizeof(f)/sizeof(f[0])) << std::endl;

  // 
  //SmallInt *p = new SmallInt[5];
  SmallInt p[5];
  for (int i = 0; i < 5; i++)
    p[i].set(6 - i);

  SmallInt m = cpp_primer::min_value(p, 5);
  std::cout << eq(m, SmallInt(2)) << std::endl;

  //delete[] p;
}
