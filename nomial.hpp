#ifndef NOMIAL
#define NOMIAL
#include<iostream>
template<class T>
class nomial
{
public:
	//virtual nomial & copy();
	virtual nomial * clone() const
	{
		std::cout << "ERROR: NOMIAL CLONE CALLED" << std::endl;
		return(new nomial());
	}
	virtual T eval(T asdf)
	{

		//this is holder class not meant to be used directly
		return(asdf);
	}
	virtual string tostring();
};
#endif
