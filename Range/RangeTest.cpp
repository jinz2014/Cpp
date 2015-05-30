//
// Program to test the Range class
//

#include <iostream>
#include <cassert>
#include "Range.h"

using namespace std;

int main()
{
   cout << "hello vc 2010 " << endl;

	// The default type is double
	double closingPrice (45.7);
	double openingPrice (60.0);
	Range<double> bearish (closingPrice, openingPrice);

	// Looking at some prices
	double currentPrice = 50.0;

	bool test1 = bearish.left(currentPrice);
	bool test2 = bearish.right(currentPrice);
	bool test3 = bearish.contains(currentPrice);
	
	if (test1 == false && test2 == false && test3 == true)
		cout << "bearish price test OK\n";

	// Create a range with float as underlying type
	float closingPrice2 (90.0);
	float openingPrice2 (60.0);
	float currentPrice2 = 70.0;
	Range<float> bullish (openingPrice2, closingPrice2);

	test1 = bullish.left(currentPrice2);
	test2 = bullish.right(currentPrice2);
	test3 = bullish.contains(currentPrice2);
	
	if (test1 == false && test2 == false && test3 == true)
		cout << "bullish price test OK\n";

  bullish.set_lo(30);
  bullish.set_hi(80);
  assert(bullish.get_lo() == 30);
  assert(bullish.get_hi() == 80);

  Range<float>bullish2(bullish);
  assert(bullish2.get_lo() == 30);
  assert(bullish2.get_hi() == 80);
  
  return 0;
}
