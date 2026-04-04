#include <iostream>

class Animal {
public:
    void eat() {
        cout << "I can eat!" << endl;
    }
};
class Dog : public Animal {
public:
    void bark() {
        cout << "I can bark! Woof woof!!" << endl;
    }
};

void main() {
    Dog myDog;
    myDog.eat();
    myDog.bark();
}
