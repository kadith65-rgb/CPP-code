

#include<conio.h>
#include<iostream.h>
class abc
{
public:
int num1, num2;
float result;
void getData()
{
}
cout << "Enter 1st Number";
cin >> num1;
cout << "Enter 2nd Number: ";
cin >> num2;
result = 0
};
class calculation public abc {
public:
void add()
{
result = num1+num2;
}
void subtract()

};

result = num1+num2;

}

void subtract()

{

}

result num1-num2;

void multiple()

{

result = num1*num2;

}

void divide()

{

result = num1/num2;

}

void modulus()

I

{

result = num1%num2;

}

class displayData: public calculation

{

public:

void display()

{public:

void display()

{

cout << "Result: " << result;

}

};

void main()

{

clrscr();

int op;

displayData obj;

obj.getData();

cout << "1.Add\n.2Sub\n3.Mult\n4.Div\n5.Mod\nSelect Operator: ";

cin >> op;

switch(op)

{

case 1:

obj.add();

break;

case 2:

obj.subtract();

break;

case 3:

obj.multiply();
switch(op)

{

4

case 1:

obj.add();

break;

case 2:

obj.subtract();

break;

case 3:

obj.multiply();

break;

case 4:

obj.divide();

break;

case 5:

obj.modulus(); I

break;

default:

}

cout << "Enter Valid Option";

obj.display();

getch()

}