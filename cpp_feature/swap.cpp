#include <iostream>
using namespace std;

void swap (int&, int&);
void swap (int*, int*);


int main() {
int q = 3;
int p = 5;


swap (p,q);

cout << "q=" << q << " p=" << p << endl;

swap (&p,&q);

cout << "q=" << q << " p=" << p << endl;
}


void swap(int &a, int &b) {
int t = a;
a = b;
b = t;
}

void swap(int *a, int *b) {
int t = *a;
*a = *b;
*b = t;
}

