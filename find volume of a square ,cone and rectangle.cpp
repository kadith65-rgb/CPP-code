#include <iostream>
using namespace std;
class volume {
public:
float vol (float side)
{
return (side*side*side);
}
float vol (float radies,float height)
{
return((3.14*radies*radies*height)/3);
}
float vol (float length,float width,float height)
{
return (length*width*height);
}
};
int main ()
{
float side,radius,height,length,width, result;
volume obj;
cout << "Enter side of cube";
cin >> side;
result = obj.vol(side);
cout << "Volume of Cube:" << result;
cout << "Enter radius of cone";
cin>>radius;
cout <<" Enter height";
result= obj.vol (radius, height);
cout << "Volume of Cone="<<height;
cout <<"Enter length of rectangle";
cin>> length;
cout<<"Enter width of rect";
cin >>width;
cout << " Enter rectangle of rect";
cin>>height;
result = obj.vol (length, width, height);
cout << "Volume of Rectangle "<<result;
return 0;
}