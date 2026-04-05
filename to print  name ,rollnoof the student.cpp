#include<iostream>
using   namespace std;
class Student
{
public:
std::string name;
int rollno;
void getData()
{
cout<<" Enter student Name"<<endl;
cin>> name;
cout<<" Enter Roll Number"<<endl;
cin>> rollno;
}
void displayData()
{
cout << "Student Name" <<name<<endl;
cout <<" Roll Number" <<rollno;
}
};
int main()
{
Student obj;

obj.getData();
obj.displayData();
}
