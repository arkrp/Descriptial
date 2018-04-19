#ifndef SINE
#define SINE
#include "..\..\nomial.hpp"
#include <math.h>
template<class T>
class sine : public nomial<T>
{
public:
	nomial<T> & nom1;
	//nomial<T> * nom2;
	sine(nomial<T> & nom1a)//,nomial<T> * nom2a)
	:nom1(nom1a)
	{
		//nom1=nom1a;
		//nom2=nom2a;
	}
	virtual T eval(T thing)
	{

		return(sin(nom1.eval(thing)));//*nom2->eval(thing));
	}
	virtual sine * clone() const
	{
		return(new sine(*nom1.clone()));
	}
};
#endif
