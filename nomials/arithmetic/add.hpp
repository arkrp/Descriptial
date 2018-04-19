#ifndef ADD
#define ADD
#include "..\..\nomial.hpp"
template<class T>
class adder : public nomial<T>
{
public:
	nomial<T> & nom1;
	nomial<T> & nom2;
	adder(nomial<T> & nom1a,nomial<T> & nom2a)
	:nom1(nom1a),
	nom2(nom2a)
	{
	}
	virtual T eval(T thing)
	{
		return(nom1.eval(thing)+nom2.eval(thing));
	}
	virtual adder * clone() const
	{
		return(new adder(*nom1.clone(),*nom2.clone()));
	}
	virtual string tostring()
	{
		return("(" + nom1.tostring() + " + " + nom2.tostring() + ")")
	}
};

//overloading
template<class T> adder<T> & operator+(const nomial<T> & a,const nomial<T> & b)
{
	return(*new adder<T>( *(a.clone()) , *(b.clone()) ));
}

#endif
