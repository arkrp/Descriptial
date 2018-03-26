#ifndef SUB
#define SUB
#include "nomial.hpp"
template<class T>
class suber : public nomial<T>
{
public:
	nomial<T> * nom1;
	nomial<T> * nom2;
	suber(nomial<T> * nom1a,nomial<T> * nom2a)
	{
		nom1=nom1a;
		nom2=nom2a;
	}
	virtual T eval(T thing)
	{
		return(nom1->eval(thing)-nom2->eval(thing));
	}
};
#endif
