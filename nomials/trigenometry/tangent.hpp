#ifndef TANGENT
#define TANGENT
#include "..\..\nomial.hpp"
#include <math.h>
template<class T>
class tangent : public nomial<T>
{
public:
	nomial<T> & nom1;
	//nomial<T> * nom2;
	tangent(nomial<T> & nom1a)//,nomial<T> * nom2a)
	:nom1(nom1a)
	{
		//nom1=nom1a;
		//nom2=nom2a;
	}
	virtual T eval(T thing)
	{
		return(tan(nom1.eval(thing)));//*nom2->eval(thing));
	}
	virtual tangent * clone() const
	{
		return(new tangent(*nom1.clone()));
	}
};
#endif
