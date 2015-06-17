#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValid(string s) {
        stack<char> stk;
        stk.push('#');
        char top;
        for(int i=0; i < s.size(); i++) {
            top = stk.top();
                 if(top == '(' && s[i] == ')') stk.pop(); 
            else if(top == '[' && s[i] == ']') stk.pop(); 
            else if(top == '{' && s[i] == '}') stk.pop();
            else stk.push(s[i]);
        }
        top = stk.top();
        if(top == '#') return true;
        else           return false;
    }

int main() {
	string s0 = "()[]";
	string s1 = "([])";
	cout << isValid(s0) << endl;
	cout << isValid(s1) << endl;
	return 0;
}

~

