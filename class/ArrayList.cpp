#include <ostream>
#include <cstring>
#include <sstream>
#include <exception>

using namespace std;


class ArrayIndexOutofBoundException : public exception {
  private:
   int index;

  public:

    // Constructor
    ArrayIndexOutofBoundException(int index) {
      this->index = index;
    }

    // Override
    virtual const char* what() const throw() {
      ostringstream convert; 
      convert << index;
      string result = "Index " + convert.str() + " out of bounds";
      return result.c_str();
    }
};


template<class T>
class ArrayList {
  public:
    int length;

    // constructors
    ArrayList(); 

    ArrayList(int size); 

    // destructor
    ~ArrayList() {
      delete[] elem;
    }

    bool isEmpty() const {
      return length == 0;
    }

    T get(int index) const;

    T set(int index, T e);

    int indexOf(const T& x) const;

    T* toArray() const;

    ArrayList<T>& clone() const;

    ArrayList<T>& clear();

    ArrayList<T>& remove(int index);

    ArrayList<T>& insert(int index, const T& x);

    ArrayList<T>& insert(const T& x);

    ArrayList<T>& reverse();

    T operator[](int i) const;

    friend ostream& operator<<(ostream& out, const ArrayList<T>& list) {
      for (int i = 0; i < list.length; i++)
        out << list.get(i) << " ";
      out << endl;
      return out;
    }

  private:
    int size;  // capacity
    T* elem;
};


/* constructs an empty list with an initial capacity of ten.*/
template<class T>
ArrayList<T>::ArrayList() {
  this->size = 10;
  elem      = new T[size];
  length    = 0;
}

/* constructs an empty list with the specified capacity.*/
template<class T>
ArrayList<T>::ArrayList(int size) {
  this->size = size;
  elem      = new T[size];
  length    = 0;
}

/* Returns an array containing all the elements in the ArrayList instance. */
template<class T>
T* ArrayList<T>::toArray() const {
  T *a = new T[length];
  memcpy(a, elem, length * sizeof(T));
  return a;
}

/* Returns a shallow copy of this ArrayList instance. */
template<class T>
ArrayList<T>& ArrayList<T>::clone() const {
  ArrayList<T> *c = new ArrayList<T>(size);
  c->length = length;
  memcpy(c->elem, elem, size * sizeof(T));
  return *c;
}

/* 
   Replaces the element at the specified position in this
   list with the specified element.
   Return the element previously at the specified position
 */
template<class T>
T ArrayList<T>::set(int index, T e) {
  if (index < 0 || index >= length)
    throw new ArrayIndexOutofBoundException(index);
  T t = elem[index];
  elem[index] = e;
  return t;
}

template<class T>
T ArrayList<T>::get(int index) const {
  if (index < 0 || index >= length) 
    throw new ArrayIndexOutofBoundException(index);
  return elem[index];
}

/* search the list for the position of element x */
template<class T>
int ArrayList<T>::indexOf(const T& x) const {
  for (int i = 0; i < length; i++)
    if (x == elem[i])
      return i;
  return -1;
}

/* reverse the array in place */
template<class T>
ArrayList<T>& ArrayList<T>::reverse() {
  if (false == isEmpty()) {
    for (int i = 0; i < length / 2; i++) {
      T t = elem[i];
      elem[i] = elem[length-i-1];
      elem[length-i-1] = t;
    }
  }
  return *this;
}

/* clear the array */
template<class T>
ArrayList<T>& ArrayList<T>::clear() {
  length = 0;
  return *this;
}

/* delete the element at index index */
template<class T>
ArrayList<T>& ArrayList<T>::remove(int index) {
  if (index < 0 || index >= length) 
    throw new ArrayIndexOutofBoundException(index);

  // the last element index in an array is length - 2
  for (int i = index; i < length - 1; i++) {
    elem[i] = elem[i+1];
  }
  length--;

  return *this;
}

/* 
   Appends the specified element to the end of this list.
 */
template<class T>
ArrayList<T>& ArrayList<T>::insert(const T& x) {

  if (length == size) {
    T* new_elem = new T[2*size];
    memcpy(new_elem, elem, size * sizeof(T));
    delete[] elem;
    elem = new_elem;
    size = 2*size;
  }

  // at index length
  elem[length] = x;

  length++;
}

/* 
   Inserts the specified element at the specified position index in this list. 
   Shifts the element currently at that position (if any) and any subsequent
   elements to the right (adds one to their indices).
 */
template<class T>
ArrayList<T>& ArrayList<T>::insert(int index, const T& x) {
  if (index < 0 || index > length) 
    throw new ArrayIndexOutofBoundException(index);

  if (length == size) {
    T* new_elem = new T[2*size];
    memcpy(new_elem, elem, size*sizeof(T));
    delete[] elem;
    elem = new_elem;
    size = 2*size;
  }

  length++;

  for (int i = length; i > index; i--) {
    elem[i] = elem[i-1];
  }
  elem[index] = x;

  return *this;
}

// operators 
template <class T>
T ArrayList<T>::operator[](int index) const {
  if (index < 0 || index >= length) 
    throw new ArrayIndexOutofBoundException(index);
  return elem[index];
}

