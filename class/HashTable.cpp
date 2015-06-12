#ifndef _HASH_TABLE
#define _HASH_TABLE

#include <iostream>

template<class K, class V>
class HashTable {
  private:
    int _search(const K& key) const;
    int D; 
    K *kt;  // key table
    V *vt;  // value table
    bool *empty;

  public:
    HashTable(int divisor = 11);
    ~HashTable() {
      delete[] kt;
      delete[] vt;
      delete[] empty;
    }
    bool get(const K& key, V& val) const;
    HashTable<K, V>& put(const K& key, const V& val); 
    void dump() const {
      for (int i = 0; i < D; i++) {
        if (empty[i])
          std::cout << "E ";
        else
          std::cout << kt[i] << ":" << vt[i] << " ";
      }
      std::cout << std::endl;
    }
};


// Constructor
template<class K, class V>
HashTable<K, V>::HashTable(int divisor) {
  D = divisor;
  vt = new V[D];
  kt = new K[D];
  empty = new bool[D];

  for(int i = 0; i < D; i++) empty[i] = true;
}

template<class K, class V>
int HashTable<K, V>::_search(const K& key) const {
  int i = key % D;
  int j = i;
  do {
    if (kt[j] == key || empty[j]) 
      return j;
    else
      j = (j + 1) % D;
  } while (j != i);
  return j;
}

template<class K, class V>
bool HashTable<K, V>::get(const K& key, V& val) const {
  int i = _search(key);
  if (kt[i] == key && !empty[i]) {
    val = vt[i];
    return true;
  }
  else 
    return false;
}

// linear open addressing

template<class K, class V>
HashTable<K, V>& HashTable<K, V>::put(const K& key, const V& val) {
  int i = _search(key);
  if (empty[i]) {
    empty[i] = false;
    kt[i] = key;
    vt[i] = val;
    return *this;
  } else if (key == kt[i]) {
    vt[i] = val; // replace the old value
    return *this;
  } else {
    std::cout << "Operation aborted due to full hash table: key= " << key 
         << "value = " << val << std::endl;
  }
}

#endif
