// integratorimp.cpp
//
// Two Classes that can perform integartion of one-dimensional functions.
//
// 2 * Integral(a, b, tanh(h/2 * f(x))), h = b - a
// h * Integral(a, b, f(x)), h = b - a

#include <cmath>
#include "integratorimp.hpp"
#include "Range.h"

double TanhRule::value(const NumIntegrator& f) const {
	Range<double> r = f.getRange();

	double a = r.get_lo();
	double b = r.get_hi();
	int    s = (double) f.getSteps();
	double h = r.spread() / s;  // average length of each segment

  // integral sum
	double res = 0.0;

	for (double x = a + (0.5 * h); x < b; x += h)
    res += tanh(f.calculate(x) * 0.5 * h); 

  return 2.0 * res;
}


double MidpointRule::value(const NumIntegrator& f) const {
	Range<double> r = f.getRange();
	double a = r.get_lo();
	double b = r.get_hi();
	int    s = (double) f.getSteps();
	double h = r.spread() / s;  // average length of each segment

	double res = 0.0;
	for (double x = a + (0.5 * h); x < b; x += h)
    res += f.calculate(x);

	return res * h;
}





