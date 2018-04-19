#include <iostream>
using namespace std;

class Add
{

void operator + (Add);
friend istream &operator >> (istream &input, Add &i);

public:
    double x;
    double y;
    void add(double, double);

};
