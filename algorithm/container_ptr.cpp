/*********************************************************************
 * WARNING: This example must be compiled using the C++0X standard.  *
 *                                                                   *
 * g++  name_of_this_file.cc    -std=c++0x -o runme                  *
 *                                                                   *
 *********************************************************************/
#include <algorithm>
#include <set>
#include <string>
#include <sstream>
#include <iterator>
#include <iostream>

using namespace std;

const string TEXT = "The quick brown fox jumps over the lazy dog";

// function object
struct StringComparator {
    bool operator() (string *a, string *b) 
    {
        return *a < *b;
    }

};

set<string> words;
set<string*> words_ptr;
set<string*,StringComparator> words_ptr_sorted;

void insert (string s)
{
    words.insert (s);

    string *sptr = new string(s);
    words_ptr.insert (sptr);
    words_ptr_sorted.insert (sptr);
}

int main()
{
    stringstream ss (TEXT);

#if 0
    copy (istream_iterator<string>(ss), istream_iterator<string>(),
            ostream_iterator<string> (cout, "\n"));

    The above copy algorithm is equivalent to the following loop

    for (auto iter = istream_iterator<string>(ss);
            iter != istream_iterator<string>(); ++iter)
        cout << *iter << "\n";
#endif
    for_each (istream_iterator<string>(ss), // begin range
            istream_iterator<string>(),     // end range
            insert);                        // operation
#if 0
    The above for_each algorithm is equivalent to the following for-loop

    for (auto iter = istream_iterator<string>(ss);
            iter != istream_iterator<string>(); ++iter)
        insert (*iter);
#endif
    cout << "From words: ";
    copy (words.begin(), words.end(), ostream_iterator<string>(cout, " "));
    cout << endl;
    cout << "=====================================" << endl;

    cout << "From words_ptr: " << endl;
    for (auto iter = words_ptr.begin(); iter != words_ptr.end(); ++iter)
        cout  << *iter << " ==> " << **iter << endl;
    cout << "=====================================" << endl;
    cout << endl << "From words_ptr_sorted: ";
    for (auto iter = words_ptr_sorted.begin(); 
            iter != words_ptr_sorted.end(); ++iter)
        cout  << **iter << " ";
    cout << endl;

    return 0;
}
