#include "HashTable.cpp"

int main() {
  HashTable<int, int> m;
  m.put(80, 1);
  m.put(40, 1);
  m.put(65, 1);
  m.dump();

  m.put(24, 1);
  m.put(58, 1);
  m.dump();

  m.put(35, 1);
  m.dump();
}
