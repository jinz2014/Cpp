#include <iostream>
#include <vector>
#include <string>

using namespace std;

void generate(int l, int r, vector<string>& res, string s)
{
    if (l > r) return;
    if (l == 0)
    {
        for (int i = 0; i < r; i++) s+= ")";
        res.push_back(s);
        return;
    }
    generate(l - 1, r, res, s + "(");
    generate(l, r - 1, res, s + ")");
}

vector<string> generateParen(int n) {
    vector<string> res;
    generate(n,n,res,"");
    return res;
}


int main() {
	vector<string> s = generateParen(3);
	for (int i = 0; i < s.size(); i++)
	cout << s[i] << " " << endl;
	return 0;
}

