#ifndef MULTIPLY
#define MULTIPLY
#include "..\..\nomial.hpp"
template<class T>
class multiplier : public nomial<T>
{
public:
	nomial<T> & nom1;
	nomial<T> & nom2;
	multiplier(nomial<T>& nom1a,nomial<T>& nom2a)
	:nom1(nom1a),
	nom2(nom2a)
	{
	}
	virtual T eval(T thing)
	{
		return(nom1.eval(thing)*nom2.eval(thing));
	}
	virtual multiplier * clone() const
	{
		return(new multiplier(*nom1.clone(),*nom2.clone()));
	}
	virtual string tostring()
	{
		return("(" + nom1.tostring() + " * " + nom2.tostring() + ")")
	}
};
template<class T> multiplier<T> & operator*(const nomial<T> & a,const nomial<T> & b)
{
	return(*new multiplier<T>( *(a.clone()) , *(b.clone()) ));
}
#endif
