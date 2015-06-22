#include <map>
#include <iostream>

using namespace std;

class CompareIntPtr
{
public:
    bool operator() ( int* p1, int* p2 ) const
    {
        return *p1 < *p2;   
    }
};

int main() {

    // map
    typedef std::map< int*, int, CompareIntPtr > TestMapType;

    int *i1 = new int( 10 );
    int *i2 = new int( 11 );
    int *i3 = new int( 11 );
    int *i4 = new int( 13 );

    TestMapType m;
    m.insert( std::make_pair( i1, 1 ) );
    m.insert( std::make_pair( i2, 2 ) );
    m.insert( std::make_pair( i3, 2 ) );
    m.insert( std::make_pair( i4, 3 ) );

    TestMapType::const_iterator found = m.find( i1 );
    if( found != m.end() )
        std::cout << "Found i1" << endl;

    //------------------------------------------
    // multimap
    //------------------------------------------
    multimap<int*, int, CompareIntPtr> m2;
    m2.insert(make_pair(i1, 1));
    m2.insert(make_pair(i2, 2));
    m2.insert(make_pair(i3, 3));
    m2.insert(make_pair(i4, 4));
    cout << m2.count(i1) << " "
         << m2.count(i2) << " "
         << m2.count(i3) << " "
         << m2.count(i4) << endl;

    delete i1;
    delete i2;
    delete i3;
    delete i4;
}
