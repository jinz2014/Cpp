// NumIntegrator.hpp
//
// A class that integrates a real-valued function of one variable.
// We have used the Bridge pattern to allow us flexibility in choosing 
// how to integrate the function numericallly.
//
//
// (C) Datasim Education BV 2004

#ifndef NumIntegrator_hpp
#define NumIntegrator_hpp



#include "Range.h"

class IntegratorImp;


class NumIntegrator
{

private:

	int nSteps;				      // Number of subdivisions of interval
	Range<double> interval;	// Interval of interest
	double (*f)(double x);	// C style function	
	IntegratorImp* imp;		  // The actual integrator implementation

public:
	NumIntegrator(double (*fp)(double x), 
                const Range<double>& myRange, 
                IntegratorImp& implementor,
						    int numSteps = 30);

	void function(double (*fp)(double x)); 
	void setRange (const Range<double>& myRange);
	
	int getSteps() const;
	Range<double> getRange() const;

	double calculate(double x) const;		// Calculate value at value == x

	// Calculating the integral of the function. Functions that are
	// delegated to the Bridge implementation.
	double value() const;

	// Vector<double, int> mesh() const;
	// double accuracy() const;	


};



#endif

