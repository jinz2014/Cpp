#ifndef ARRAY1D_HPP
#define ARRAY1D_HPP

#include <iostream>
#include <cstring>

using namespace std;

template < class T >
class Array1D {
  friend ostream& operator<< (ostream& out, const Array1D<T>& s) {
    for (int i = 0; i < s.size; i++) 
      out << s.elem[i] << " ";
    return out;
  }

  public:
    // ctor
    Array1D(int size = 0);
    Array1D(const Array1D<T>& s);
    T& operator[](int i) const;
    Array1D<T>& operator=(const Array1D<T>& s);
    Array1D<T>& operator+=(const Array1D<T>& s);
    Array1D<T>  operator+(const Array1D<T>& s);
    ~Array1D();

  private:
    int size;
    T *elem;
};

// 
template < class T >
Array1D<T>::Array1D (int sz) {
  //assert (sz >= 0);
  size = sz;
  elem = new T[sz];
}

// copy an object of Array1D 
template < class T >
Array1D<T>::Array1D(const Array1D<T>& s) {
  size = s.size;
  elem = new T[size];
  memcpy(elem, s.elem, sizeof(T)*size);
}

// overloaded []
template < class T >
T& Array1D<T>::operator[](int i) const {
  return elem[i];
}

// overloaded =
template < class T >
Array1D<T>& Array1D<T>::operator=(const Array1D<T>& s) {
  cout << "assignment: operator= " << endl;
  if (this != &s) {
    size = s.size;
    delete[] elem;
    elem = new T[size];
    memcpy(elem, s.elem, sizeof(T)*size);
  }
  return *this; // 
}

// overloaded +
template < class T >
Array1D<T> Array1D<T>::operator+(const Array1D<T>& s) {
  if (size != s.size) 
    cerr << "Error: + operators size mismatch" << endl;

  Array1D<T> w(size);
  for (int i = 0; i < size; i++)
    w.elem[i] = elem[i] + s.elem[i];
  return w;
}

// overloaded +=
template < class T >
Array1D<T>& Array1D<T>::operator+=(const Array1D<T>& s) {
  if (size != s.size) 
    cerr << "Error: + operators size mismatch" << endl;

  for (int i = 0; i < size; i++)
    elem[i] += s.elem[i];

  return *this;
}


template < class T >
Array1D<T>::~Array1D () {
  cout << "~Array1D(): delete the array memory" << endl;
  delete[] elem;
}

#endif
