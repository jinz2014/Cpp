#include <map>
#include <iostream>

using namespace std;

struct MMK {
  string n;
  int s;
};

struct CompareStruct
{
  bool operator()(const MMK &a, const MMK &b) const {
    // Error
    //return a.n.compare(b.n) < 0 && a.s < b.s;

    if (a.n.compare(b.n) == 0) {
      return a.s < b.s;
    }
    return a.n.compare(b.n) < 0;
  }
};

// multimap reference must not be constant!
void print(multimap<MMK, int, CompareStruct> &m, const MMK &k) {
  multimap<MMK, int, CompareStruct>::iterator it;
  for (it = m.equal_range(k).first; it != m.equal_range(k).second; it++) {
    cout << it->second << endl;
  }
  cout << endl;
}

int main() {
  multimap<MMK, int, CompareStruct> m3; 
  multimap<MMK, int, CompareStruct>::iterator it;

  MMK k; 
  for (int i = 0; i < 3; i++) {
    k.n = i == 2 ? "b" : "a";
    k.s = 0;
    m3.insert(make_pair(k, i));
  }

  for (it = m3.begin(); it != m3.end(); it++) {
    cout << m3.count(it->first) << endl;
    print(m3, it->first);
  }
}
