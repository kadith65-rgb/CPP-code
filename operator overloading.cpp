#include <iostream>
class complex {
    public:
    double real,img;
    complex(double r=0,double i=0) {
        real=r;
        img=i;
    }
    friend complex operator + (const complex& c1,const complex& c2) {
        complex temp;
        temp.real = c1.real+c2.real;
        temp.img = c1.img+c2.img;
        return temp;
    }
    void display() {
        cout << "Real:" << real << "Imaginary:" << img;
    }
};
void main() {
    complex c1(3,4),c2(1,2);
    complex c3 = c1+c2;
    c3.display();
}