#include <iostream>
#include "overload.h"

using namespace std;

void add(double x, double y)
{
    double sum;
    sum = x + y;
    cout<<sum;
}
void Add::operator +(Add aao)
{
    double New;
    New = aao.x + aao.y;
}
istream &operator >> (istream &input, Add &i)
{
input>>i.x>>i.y;
return input;
}

