#include <vector>

namespace N {
  struct X {};

  template<typename T>
    int* operator+(T, unsigned) {
    }
}

int main() {
  std::vector<N::X> v(5);
  v[0];
}

