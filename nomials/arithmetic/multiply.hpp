#ifndef MULTIPLY
#define MULTIPLY
#include "..\..\nomial.hpp"
template<class T>
class multiplier : public nomial<T>
{
public:
	nomial<T> * nom1;
	nomial<T> * nom2;
	multiplier(nomial<T> * nom1a,nomial<T> * nom2a)
	{
		nom1=nom1a;
		nom2=nom2a;
	}
	virtual T eval(T thing)
	{
		return(nom1->eval(thing)*nom2->eval(thing));
	}
};
#endif
