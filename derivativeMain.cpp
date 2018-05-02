#include <iostream>
#include <iomanip>
#include "nomial.hpp"
#include "fundemental.hpp"
#include "arithmetic.hpp"
#include "trigenometry.hpp"
using namespace std;

double derivative(nomial<double> *, double, int);

constant<double> & c(double a);
sine<double> nsin(nomial<double> & a);
cosine<double> ncos(nomial<double> & a);
tangent<double> ntan(nomial<double> & a);

int main() {
    nomial <double> & X = *new identity<double>();
    nomial <double> * func1 = &(nsin(X)+X);
    
    double x = 0.0;
    int prec = -1;
    
    cout << "DERIVATIVE OF: f(x) = sin(x) + x" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "Derivative at x = ";
    cin >> x;
    
    while (prec < 0 || prec > 7){
        cout << "To how many decimal places should the result be accurate (max = 7)? ";
        cin >> prec;
        
        if (prec < 0 || prec > 7)
            cout << "Invalid input. Must be in range 0-7." << endl;
    }
    
    cout << "f'(" << x << ") = " << fixed << setprecision(prec)<< derivative(func1, x, prec) << endl;
    return 0;
}

double derivative(nomial<double> *obj, double x, int prec){
    double h = 0.1;      // The "h" for the derivative
    double residual = 100.0;   // The residual value between trials. Set to some nonzero number at first
    double derivtrial = 0.0;
    double prevtrial = 0.0;
    
    derivtrial = (obj->eval(x + h) - obj->eval(x))/(h);
    prevtrial = derivtrial;
    h = h/10;
    
    while (residual != 0.0){
        derivtrial = (obj->eval(x + h) - obj->eval(x))/(h);
        residual = derivtrial - prevtrial;
        // Now truncate residual to the wanted presicion
        
        double trunc = 0.0;
        trunc = (int) (residual*(pow(10, prec)));
        residual = (double) trunc/(pow(10, prec));
        prevtrial = derivtrial;
        h = h/10;
    }
    
    return derivtrial;
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
