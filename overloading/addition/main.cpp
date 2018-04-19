#include <iostream>
#include "overload.h"

using namespace std;
int main()
{
   Add add;
   double sum;
cout<<"Enter values to add: (ex. X + Y ) \n";
cin>>add.x>> add.y;
   sum = add.x + add.y;
   cout<<sum;

    return 0;
}
//need to implement the allowance of any data type example 2x + x 
//or have value as string by defeault then have the ability to add either as a string (2x + x = 3x) or as double or int(x = 3, so x + 6 = 9)
