#include <iostream>
using namespace std;
class Sample{
public:
static int count;
public:
Sample()
{
count++;
}
static void showcount()
{
cout<<"Number of objects created"<<count;
}
};
int Sample::count = 0;

int main()
{
Sample obj1;
Sample obj2;
Sample obj3;
Sample obj4;
Sample::showcount();
return 0;
}