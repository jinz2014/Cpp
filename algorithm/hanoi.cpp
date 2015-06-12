#include <iostream>
using namespace std;

// move n disks from t1 to t2 thru t3
void hanoi(int n, int t1, int t2, int t3) {
  if (n > 0) {
    // move n-1 disks from t1 to t3 thru t2
    hanoi(n-1, t1, t3, t2);

    // move bottom disk from t1 to t2
    cout << "Move top disk from tower " << t1 
         << " to tower " << t2 << endl;

    // move n-1 disks from t3 to t2 thru t1
    hanoi(n-1, t3, t2, t1);
  }
}

int main() {
  hanoi(3, 1, 2, 3);
}
