#include <iostream>

/*
   when (n & n- 1) = 0, it detect the number is a power of 2
 */
int main() {
  for (int n = 1; n < 4096; n++) {
    if ((n & n-1) == 0)
      std::cout << n << " is a power of 2 number " << std::endl;
  }

  for (int n = 1; n < 32; n++) {
    int m = n & n-1 ;
    std::cout << n << " " << m << std::endl;
  }
}
