//============================================================================
// Name        : polynomials.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "nomial.hpp"
#include "constant.hpp"
#include "identity.hpp"
#include "adder.hpp"
#include "suber.hpp"
using namespace std;

int main() {

	nomial<double> * func1;
	//1+x
	func1 = new adder<double>(new constant<double>(1),new identity<double>());
	cout << func1->eval(1) << endl;
	cout << func1->eval(2) << endl;

	nomial<double> * func2;
	//1-x
	func2 = new suber<double>(new constant<double>(1),new identity<double>());
	cout << func2->eval(1) << endl;
	cout << func2->eval(2) << endl;

	return 0;
}
