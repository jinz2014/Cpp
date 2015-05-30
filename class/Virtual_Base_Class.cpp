#include <iostream>
using namespace std;

/*
Now, when you create a Copier class, you will get only one copy of PoweredDevice that will be shared by both Scanner and Printer.

However, this leads to one more problem: if Scanner and Printer share a PoweredDevice base class, who is responsible for creating it? The answer, as it turns out, is Copier. The Copier constructor is responsible for creating PoweredDevice. Consequently, this is one time when Copier is allowed to call a non-immediate-parent constructor directly:

1 virtual base classes are created before non-virtual base classes, which ensures all bases get created before their derived classes.

2 the Scanner and Printer constructors still have calls to the PoweredDevice constructor. If we are creating an instance of Copier, these constructor calls are simply ignored because Copier is responsible for creating the PoweredDevice, not Scanner or Printer. However, if we were to create an instance of Scanner or Printer, the virtual keyword is ignored, those constructor calls would be used, and normal inheritance rules apply.

Third, if a class inherits one or more classes that have virtual parents, the most derived class is responsible for constructing the virtual base class. In this case, Copier inherits Printer and Scanner, both of which have a PoweredDevice virtual base class. Copier, the most derived class, is responsible for creation of PoweredDevice. Note that this is true even in a single inheritance case: if Copier was singly inherited from Printer, and Printer was virtually inherited from PoweredDevice, Copier is still responsible for creating PoweredDevice.

*/


class PoweredDevice
{
  public:
      PoweredDevice(int nPower)
      {
          cout << "PoweredDevice: " << nPower << endl;
      }
};
 
class Scanner: virtual public PoweredDevice
{
  public:
      Scanner(int nScanner, int nPower)
          : PoweredDevice(nPower)
      {
          cout << "Scanner: " << nScanner << endl;
      }
};
 
class Printer: virtual public PoweredDevice
{
  public:
      Printer(int nPrinter, int nPower)
          : PoweredDevice(nPower)
      {
          cout << "Printer: " << nPrinter << endl;
      }
};
 
class Copier: public Scanner, public Printer
{
  public:
      Copier(int nScanner, int nPrinter, int nPower)
          : Scanner(nScanner, nPower), Printer(nPrinter, nPower), PoweredDevice(nPower)
      {
      }
};

int main(void)
{
	Copier  c1(1, 2, 3);
	Scanner s1(1, 3);
	Printer p1(2, 3);
	return 0;
}

