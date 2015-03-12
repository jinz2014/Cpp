#include <string>
#include <iostream>
#include "Creature.h"

using namespace std;
 
int main()
{
    using namespace std;
    cout << "Enter a name for your creature: ";
    string cName;
    cin >> cName;
    Creature cCreature(cName, Point3D(4, 7, 10));
 
    while (1)
    {
        cout << cCreature << endl;
        cout << "Enter new X location for creature (-1 to quit): ";
        int nX=0;
        cin >> nX;
        if (nX == -1)
            break;
 
        cout << "Enter new Y location for creature (-1 to quit): ";
        int nY=0;
        cin >> nY;
        if (nY == -1)
            break;
 
        cout << "Enter new Z location for creature (-1 to quit): ";
        int nZ=0;
        cin >> nZ;
        if (nZ == -1)
            break;

        cCreature.MoveTo(nX, nY, nZ);
        }
 
    return 0;
}

