#include <iostream>
using namespace std;
int main()
{ 
int totalseconds, hours, minutes,seconds;
cout<<"Enter total seconds:";
cin>>totalseconds;

hours=totalseconds/3600;
minutes=(totalseconds % 3600)/60;
seconds=totalseconds %60;
cout << "Hour: "<< hours;
cout << "Minutes:"<< minutes;
cout << "Seconds: " << seconds;
return 0;
}