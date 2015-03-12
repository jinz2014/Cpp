#include <iostream>
using namespace std;
 
// create a tree with the number of max children equals the candidates
 
const int sz = 7;
 
struct node {
    int data;
    struct node *children[sz];
    struct node *parent;
};
 
 
void printSum(node *n) {
  while (n->parent != NULL){
    if (n->data != 0) {
        if (n->parent->data == 0) {
            cout << n->data;
        }
        else {
            cout << n->data << "+";
        }
        n = n->parent;
    }
    else {
        break;
    }
  }
  cout << endl;
}
 
 
bool solve(int target, int candidates[], node *root, int val, int sum) {
    root->data = val;
    sum = root->data + sum;
    //cout << "value:" << root->data << ", sum:" << sum << endl;
    if (sum > target) {
        return false;
    }
    if (sum == target) {
        printSum(root);
        return true;
    }
    for (int i = 0; i < sz; i++) {
        // remove duplicates (1+3 = 3+1)
        if (candidates[i] >= root->data) {
            root->children[i] = new node;
            root->children[i]->parent = root;
            if (solve(target, candidates, root->children[i], candidates[i], sum)) {
                // if the path is already solved, no need to continue with larger numbers
                break;
            }
        } 
    }
    return false;
}
 
 
int main() {
    //int target = 7;
    //int can[sz] = {2, 3, 6, 7};
    /*
    int target = 1;
    int can[sz] = {1,1};
*/
int can[sz] = {1,1,2,5,6,7,10};
int target = 8;
    node *root = new node;
    solve(target, can, root, 0, 0);
    
    return 0;
}

