#ifndef IntegratorImp_hpp
#define IntegratorImp_hpp



#include "Numintegrator.hpp"

class IntegratorImp {
public:


	virtual double value(const NumIntegrator& f) const = 0;

};

class TanhRule: public IntegratorImp { 

private:


public:

	virtual double value(const NumIntegrator& f) const;


};

class MidpointRule: public IntegratorImp { 

private:

public:

	virtual double value(const NumIntegrator& f) const;

};

#endif
