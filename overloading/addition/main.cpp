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
