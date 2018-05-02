#include <iostream>
#include <iomanip>
#include "nomial.hpp"
#include "fundemental.hpp"
#include "arithmetic.hpp"
#include "trigenometry.hpp"
using namespace std;

double derivative(nomial<double> *, double, int);
double integral(nomial<double> *, double, double, int);
double trigint(nomial<double> *&, double, double, int);

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
    
    double high;
    double low;
    
    cout << endl << endl << "INTEGRAL OF: f(x) = sin(x) + x" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "Integral lower bound: ";
    cin >> low;
    cout << "Integral higher bound: ";
    cin >> high;
    prec = -1;
    while (prec < 0 || prec > 5){
        cout << "To how many decimal places should the result be accurate (max = 5)? ";
        cin >> prec;
        
        if (prec < 0 || prec > 5)
            cout << "Invalid input. Must be in range 0-5." << endl;
    }
    
    cout << "Integral from " << low << " to " << high << " of f(x) = " << fixed << setprecision(prec)<< integral(func1, low, high, prec) << endl;
    
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

double integral(nomial<double> *obj, double low, double high, int prec){
    int n = 1;                  // The number of trapezoids to use
    double residual = 100.0;    // The residual value between trials. Set to some nonzero number at first
    double inttrial = 0.0;
    double prevtrial = 0.0;
    int numResZero = 0; //Number of trials with residual = 0. We want 5 to make sure the integral is accurate enough.
    
    inttrial = trigint(obj, low, high, n);
    prevtrial = inttrial;
    n *= 2;
    
    while (numResZero <= 5){
        inttrial = trigint(obj, low, high, n);
        residual = inttrial - prevtrial;
        // Now truncate residual to the wanted presicion
        
        double trunc = 0.0;
        trunc = (int) (residual*(pow(10, prec)));
        residual = (double) trunc/(pow(10, prec));
        prevtrial = inttrial;
        n *= 2;
        if (residual == 0.0){
            numResZero ++;
        }
    }
    
    return inttrial;
}

double trigint(nomial<double> *&obj, double low, double high, int n){
    double dn = (high-low)/n;   // Trapezoid widths
    double integralapprox = 0.0;
    int i = 0;
    
    integralapprox += obj->eval(low + dn*i);
    for (i = 1; i < (n-1); i ++){
        integralapprox += 2*(obj->eval(low + dn*i));
    }
    i++;
    integralapprox += obj->eval(low + dn*i);
    
    
    integralapprox *= (dn/2);
    
    return integralapprox;
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
