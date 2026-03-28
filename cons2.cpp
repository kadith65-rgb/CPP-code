#include <iostream.h>
#include<conio.h>

class abc
{
public:
int num1,num2;
 float result;
abc()
{
cout << " Enter 1st Number: ";
cin >> num1;
cout << "Enter 2nd Number: ";
cin >> num2;
result = 0;
}
void add()
{
result = num1+num2;
}
void displaydata()
{
cout <<"Displaydata Data=" << result;
} };

void main()
{
abc obj;
obj.displaydata();
 obj.add();
}