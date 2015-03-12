#include <iostream>
using namespace std;


//----------------------------------------------------------------
// Base case
// PoweredDevice got constructed twice
//----------------------------------------------------------------
namespace B {

class PoweredDevice
{
public:
    PoweredDevice(int nPower)
    {
        cout << "PoweredDevice: " << nPower << endl;
    }
};
 
class Scanner: public PoweredDevice
{
public:
    Scanner(int nScanner, int nPower)
        : PoweredDevice(nPower)
    {
        cout << "Scanner: " << nScanner << endl;
    }
};
 
class Printer: public PoweredDevice
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
        : Scanner(nScanner, nPower), Printer(nPrinter, nPower)//, PoweredDevice(nPower)
    {
    }
};

} // namespace B

//----------------------------------------------------------------
// Virtual Base case
// PoweredDevice got constructed only once
//----------------------------------------------------------------
namespace V {

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

} // namespace V


int main(void)
{
	B::Copier c1(1, 2, 3);
	V::Copier c2(1, 2, 3);
	return 0;
}

