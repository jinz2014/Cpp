namespace cpp_primer {
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

}


