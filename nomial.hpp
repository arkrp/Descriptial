#ifndef NOMIAL
#define NOMIAL
template<class T>
class nomial
{
public:
	//virtual nomial & copy();
	virtual T eval(T asdf)
	{

		//nomial(const nomial &){}
		//this is holder class not meant to be used directly
		return(asdf);
	}
};
#endif
