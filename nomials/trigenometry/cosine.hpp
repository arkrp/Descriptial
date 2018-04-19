#ifndef COSINE
#define COSINE
#include "..\..\nomial.hpp"
#include <math.h>
template<class T>
class cosine : public nomial<T>
{
public:
	nomial<T> & nom1;
	//nomial<T> * nom2;
	cosine(nomial<T> & nom1a)//,nomial<T> * nom2a)
	:nom1(nom1a)
	{
		//nom1=nom1a;
		//nom2=nom2a;
	}
	virtual T eval(T thing)
	{
		return(cos(nom1.eval(thing)));//*nom2->eval(thing));
	}
	virtual cosine * clone() const
	{
		return(new cosine(*nom1.clone()));
	}
};
#endif
