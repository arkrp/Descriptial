#ifndef IDENTITY
#define IDENTITY
#include "..\..\nomial.hpp"
template<class T>
class identity : public nomial<T>
{
public:
	virtual T eval(T thing)
	{
		return(thing);
	}
};
#endif
