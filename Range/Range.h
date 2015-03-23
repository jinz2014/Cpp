#ifndef _RANGE_H
#define _RANGE_H

template <class Type> 
class Range {
  private:
    Type lo;
    Type hi;

  public:
    Range();
    Range(const Type& lo, const Type& hi);
    Range(const Range& r);  // copy

    virtual ~Range();
    void set_lo (const Type& lo);
    void set_hi (const Type& hi);
    Type get_lo () const;
    Type get_hi () const;
    Type spread() const;

    bool left(const Type& value) const;
    bool right(const Type& value) const;
    bool contains(const Type& value) const;

    Range<Type>& operator = (const Range<Type>& r);
};

template <class Type> 
Range<Type>::Range() {
  lo = 0;
  hi = 0;
}

template <class Type> 
Range<Type>::Range(const Type& lo, const Type& hi) {
  this->lo = lo;
  this->hi = hi;
}

template <class Type> 
Range<Type>::Range(const Range<Type>& r) {
  lo = r.lo;
  hi = r.hi;
}

template <class Type> 
Range<Type>::~Range() {
}

template <class Type> 
void Range<Type>::set_lo (const Type& lo) {
  this->lo = lo;
}


template <class Type> 
void Range<Type>::set_hi (const Type& hi) {
  this->hi = hi;
}


template <class Type> 
Type Range<Type>::get_lo () const {
  return lo;
}

template <class Type> 
Type Range<Type>::get_hi () const {
  return hi;
}

template <class Type> 
Range<Type>& Range<Type>::operator = (const Range<Type>& r) {
  if (this == &r) return *this;
  lo = r.lo;
  hi = r.hi;
  return *this;
}

template <class Type> 
Type Range<Type>::spread () const {
  return hi - lo;
}


template <class Type> 
bool Range<Type>::left(const Type& value) const {
  return (value < lo) ? true : false;
}

template <class Type> 
bool Range<Type>::right(const Type& value) const {
  return (value > hi) ? true : false;
}

template <class Type> 
bool Range<Type>::contains(const Type& value) const {
  return (value >= lo && value <= hi) ? true : false;
}



#endif
