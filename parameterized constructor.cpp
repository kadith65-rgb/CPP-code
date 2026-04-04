#include <iostream>

class A {
public:
    int val;
  
    A(int x) {
        val = x;
    }
};

void  main() {
  
    A a(10);
    cout << a.val;
}