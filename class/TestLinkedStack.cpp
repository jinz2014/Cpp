#include <iostream>
#include <cassert>
#include "LinkedStack.cpp"

int main() {
  LinkedStack<int> s;
  int i;
  for (i = 0; i < 4; i++) {
    s.push(i);
  }
  int t = s.top();
  assert((i-1) == t);
  s.pop(i);
  assert(i == t);
  s.pop();
  s.pop();
  s.pop();
  //assert(true == s.isEmpty());

  return 0;
}
