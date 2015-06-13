#include <iostream>
using namespace std;

/*
   MIT course reference
   There are some syntax oddities when using friend functions with (templated) classes. In order
   to declare the function as a friend of the class, you need a function prototype (or the full
   function definition) to appear before the class definition. This is a problem, because you’ll
   often need to have the class already defined in order for the function prototype to make
   sense. To get around this issue, when writing friend functions with (templated) classes, you
   should include declarations in the following order:
   1. A (templated) forward declaration of the class. (A forward declaration is a statement
   like class SomeClass;, with no class body, that just alerts the compiler that the class
   definition is coming.)
   2. A (templated) function prototype for the friend function (or the entire function definition).
   3. The full (templated) class definition, including the friend statement
 */

class Humidity;
 
class Temperature
{
  private:
      int m_nTemp;

  public:
      Temperature(int nTemp) { m_nTemp = nTemp; }
   
      friend void PrintWeather(Temperature &cTemperature, Humidity &cHumidity);
};
 
class Humidity
{
  private:
      int m_nHumidity;
  public:
      Humidity(int nHumidity) { m_nHumidity = nHumidity; }
   
      friend void PrintWeather(Temperature &cTemperature, Humidity &cHumidity);
};
 
void PrintWeather(Temperature &cTemperature, Humidity &cHumidity)
{
    cout << "The temperature is "   << cTemperature.m_nTemp 
         << " and the humidity is " << cHumidity.m_nHumidity << endl;
}

int main() {
	Temperature t(20);
	Humidity h(70);
	PrintWeather(t, h);
	return 0;
}

