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
#include "nomials\arithmetic\divide.hpp"
using namespace std;

void testnomial(nomial<double> * func);

int main() {

	//testfunction
	//func1 = sin(x)+x
	nomial<double> * func1 = new adder<double>(new sine<double>(new identity<double>()),new identity<double>());
	testnomial(func1);

	//func2 = 3x
	nomial<double> * func2 = new multiplier<double>(new constant<double>(3),new identity<double>());
	testnomial(func2);

	//func3 = (3+x)/x
	nomial<double> * func3 = new divider<double>(new adder<double>(new constant<double>(3), new identity<double>() ) ,new identity<double>());
	testnomial(func3);

	//func4 = (3+x*sin(x) - tan(x))/(x*cos(3.3x)) = (3 + ((x*sin(x)) - tan(x))) / (x*cos(3.3*x))
	nomial<double> * func4 = new divider<double>(new suber<double>(new adder<double>(new constant<double>(3), new multiplier<double>(new identity<double>(), new sine<double>(new identity<double>()) )), new tangent<double>(new identity<double>())), /*denom*/ new multiplier<double>(new identity<double>(), new cosine<double>(new multiplier<double>(new constant<double>(3.3), new identity<double>()))));
	testnomial(func4);



	return 0;
}

void testnomial(nomial<double> * func)
{
	cout << "1: " << func->eval(1) << endl;
	cout << "2: " << func->eval(2) << endl;
	cout << "3: " << func->eval(3) << endl;
	cout << "4: " << func->eval(9) << endl;
	cout << "----------------" << endl;
}
