//============================================================================
// Name        : polynomials.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "nomial.hpp"
#include "nomials\fundemental\fundemental.hpp"
#include "nomials\arithmetic\arithmetic.hpp"
#include "nomials\trigenometry\trigenometry.hpp"
using namespace std;

void testnomial(nomial<double> * func);
constant<double> & c(double a);
sine<double> nsin(nomial<double> & a);
cosine<double> ncos(nomial<double> & a);
tangent<double> ntan(nomial<double> & a);
int main() {
	nomial<double> & X = *new identity<double>();
	//
	//testfunction
	//func1 = sin(x)+x
	nomial<double> * func1 = &( nsin(X)+X );
	testnomial(func1);

	//func2 = 3x
	nomial<double> * func2 = &( c(3)*X );
	testnomial(func2);

	//func3 = (3+x)/x
	nomial<double> * func3 = &( (c(3)+X)/X );
	testnomial(func3);

	//func4 = (3+x*sin(x) - tan(x))/(x*cos(3.3x)) = (3 + ((x*sin(x)) - tan(x))) / (x*cos(3.3*x))
	nomial<double> * func4 = &(  (c(3) + X * nsin(X) - ntan(X)) / ( X * ncos(c(3.3)*X) )  );
	testnomial(func4);


	return 0;
}

constant<double> & c(double a)
{
	return(*new constant<double>(a));
}
sine<double> nsin(nomial<double> & a)
{
	return(*new sine<double>(a));
}
cosine<double> ncos(nomial<double> & a)
{
	return(*new cosine<double>(a));
}
tangent<double> ntan(nomial<double> & a)
{
	return(*new tangent<double>(a));
}


void testnomial(nomial<double> * func)
{
	cout << "1: " << func->eval(1) << endl;
	cout << "2: " << func->eval(2) << endl;
	cout << "3: " << func->eval(3) << endl;
	cout << "4: " << func->eval(4) << endl << endl;
}
