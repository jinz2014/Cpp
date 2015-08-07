#include <iostream>

//-----------------------------------------------------------------------
// 1 definition of a template function
// 2 one template parameter: const Type (&arr)[size]
// 3 one template parameter/one function parameter: Type *arr, int size
// 4 two overloaded template functions 'min_value'
// 5 if the template function min_index is defined as another min_value 
//   template function, the compiler reports ambigous error 
//-----------------------------------------------------------------------

// T is a template type parameter
// size is a nontemplate type parameter. it is a constant value
template <class Type, int size>
Type min_value(const Type (&arr)[size]) {
  Type v = arr[0]; 
  for (int i = 1; i < size; i++) {
    if (arr[i] < v)
      v = arr[i];
  }
  return v;
}

// T is a template type parameter
// size is a function parameter
template <class Type>
Type min_value(const Type *arr, int size) {
  Type v = arr[0]; 
  for (int i = 1; i < size; i++) {
    if (arr[i] < v)
      v = arr[i];
  }
  return v;
}

template <class Type, int size>
int min_index(const Type (&arr)[size]) {
  Type v = arr[0]; 
  int idx = 0;
  for (int i = 1; i < size; i++) {
    if (arr[i] < v)
      idx = i;
  }
  return idx;
}


// a function template is instantiated when
// 1. it is invoked
// 2. or its address is taken *

int main() {

  /*
  int (*pf)(int (&)[10]) = &min_value;
  typedef int (&rai)[10];
  int (*pf)(int (&)[10]) = static_cast<int (*)(rai)>(&min_value);
  */

  int a[] = {2, 3, 3, 5, 1, 8};
  std::cout << min_value(a) << std::endl;
  std::cout << min_value(a, 6) << std::endl;
  float f[] = {2.0f, 2.9f, 3.1f, 5.14f, 1.0f, 0.99f};
  std::cout << min_value(f) << std::endl;
  std::cout << min_value(f, 6) << std::endl;
}
