#ifndef DIVIDE
#define DIVIDE
#include "..\..\nomial.hpp"
template<class T>
class divider : public nomial<T>
{
public:
	nomial<T> & nom1;
	nomial<T> & nom2;
    divider(nomial<T> & nom1a,nomial<T> & nom2a)
	:nom1(nom1a),
	nom2(nom2a)
	{
	}
    virtual T eval(T thing)
    {
    	return(nom1.eval(thing)/nom2.eval(thing));
    }
	virtual divider * clone() const
	{
		return(new divider(*nom1.clone(),*nom2.clone()));
	}
	virtual string tostring()
	{
		return("(" + nom1.tostring() + " / " + nom2.tostring() + ")")
	}
};
template<class T> divider<T> & operator/(const nomial<T> & a,const nomial<T> & b)
{
	return(*new divider<T>( *(a.clone()) , *(b.clone()) ));
}
#endif
