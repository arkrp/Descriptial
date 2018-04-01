//POLYNOMIAL HEADER FILE--[draft #1] CHRISTOPHER YANG; MARCH 31; CS 2 FINAL PROJECT

#include <vector>
#include <string>
#include <iomanip>
#include <iostream>
using namespace std;

#ifndef Polynomials_hpp
#define Polynomials_hpp

#include <stdio.h>

class Poly{
protected:
    vector<double> coefficients; //Coefficients of the polynomial are stored in this vector.
public:
    //Input operator overload
    istream friend &operator>>(istream &, Poly &);
    void printCoeff(){
        cout << "Input results: " << endl;
        for (int i = 0; i < coefficients.size(); i ++){
            cout << "Coefficient " << i << ": " << coefficients[i] << endl;
        }
    }
};

#endif /* Polynomials_hpp */
