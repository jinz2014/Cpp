// STL for_each example
#include <iostream>     // cout
#include <algorithm>    // for_each
#include <vector>       // vector
#include <iterator>       // vector
#include <fstream>       // vector

using namespace std;

/*
   function object is passed instead of a function pointer(in C).
   When invoked, the callback function is executed just as any
   other member function, and therefore has full access to the
   other members (data or functions) of the object.
 */

void myStringFunction (string s) {  // function:
    cout << ' ' << s + ";";
}

void myfunction (int i) {
    cout << ' ' << i;
}

struct mystruct {           // function object type:
    void operator() (int i) {
      cout << ' ' << i;
    }
} myobject;

class myclass {           // function object type:
  public:
    void operator() (int i) {
      cout << ' ' << i;
    }
};


// The function object multiplies an element by a Factor
template <class Type>
class MultValue
{
  private:
     Type Factor;   // The value to multiply by
  public:
     // Constructor initializes the value to multiply by
     MultValue ( const Type& _Val ) : Factor ( _Val ) {
     }

     // The function call for the element to be multiplied
     void operator ( ) ( Type& elem ) const
     {
        elem *= Factor;
     }
};

// The function object to determine the average
class Average
{
  private:
     long num;      // The number of elements
     long sum;      // The sum of the elements
  public:
     // Constructor initializes the value to multiply by
     Average ( ) : num ( 0 ) , sum ( 0 )
     {
     }

     // The function call to process the next elment
     void operator ( ) ( int elem ) 
     {
        num++;      // Increment the element count
        sum += elem;   // Add the value to the partial sum
     }

     // return Average
     operator double ( )
     {
        return  static_cast<double> (sum) / static_cast<double> (num);
     }
};



int main () {
  vector<int> myvector;
  myvector.push_back(10);
  myvector.push_back(20);
  myvector.push_back(30);

  //----------------------------------------------------------------------
  // Basic example
  //----------------------------------------------------------------------
  // this is straigtform as each vector element is passed as an argument
  // to the function "myfunction"
  cout << "myvector contains:";
  for_each (myvector.begin(), myvector.end(), myfunction); // function pointer
  cout << '\n';

  cout << "myvector contains:";
  for_each (myvector.begin(), myvector.end(), myobject); // struct
  cout << '\n';

  cout << "myvector contains:";
  for_each (myvector.begin(), myvector.end(), myclass()); // class
  cout << '\n';

  //----------------------------------------------------------------------
  // Advanced example
  //----------------------------------------------------------------------
   vector <int> v1;
   vector <int>::iterator Iter1;

   // Constructing vector v1
   int i;
   for ( i = -4 ; i <= 2 ; i++ )
   {
      v1.push_back(  i );
   }

   cout << "Original vector  v1 = ( " ;
   for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
      cout << *Iter1 << " ";
   cout << ")." << endl;

   // Using for_each to multiply each element by a Factor
   for_each ( v1.begin ( ) , v1.end ( ) , MultValue<int> ( -2 ) );

   cout << "Multiplying the elements of the vector v1\n "
        <<  "by the factor -2 gives:\n ( " ;
   for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
      cout << *Iter1 << " ";
   cout << ")." << endl;

   // The function object is templatized and so can be
   // used again on the elements with a different Factor
   for_each (v1.begin ( ) , v1.end ( ) , MultValue<int> (5 ) );

   cout << "Multiplying the elements of the vector v1\n "
        <<  "by the factor 5 gives:\n ( " ;
   for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
      cout << *Iter1 << " ";
   cout << ")." << endl;

   // The local state of a function object can accumulate
   // information about a sequence of actions that the
   // return value can make available, here the Average
   double avemod2 = for_each ( v1.begin ( ) , v1.end ( ) , Average ( ) );
   cout << "The average of the elements of v1 is:\n Average ( v1mod2 ) = "
        << avemod2 << "." << endl;

  //-----------------------------------------------------------------
  // Extended example
  //-----------------------------------------------------------------

  // display input file
  typedef istream_iterator<string> in;
  typedef ostream_iterator<string> out;

  ifstream ifs("data.txt");
  for_each(in(ifs), in(), myStringFunction);
  // ifstream has no member seekp: ifs.seekp(0);
  ifs.close();

  // data.txt must be closed before reading from the start
  // read input file to a container
  vector<string> txt;
  copy(in(ifs),  in(), back_inserter(txt));

  // sort the container
  sort(txt.begin(), txt.end());

  // write the container data to a file
  fstream fs("sorted_data.txt");  // i/o operation
  copy(txt.begin(), txt.end(), out(fs, " "));
  fs.seekp(0); // must close the file

  // display output file
  for_each(in(fs), in(), myStringFunction);

  return 0;
}
