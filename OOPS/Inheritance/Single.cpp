/*
single inheritance-  a derived class inherits from one base class.
*/
#include <iostream>
using namespace std;

// Base class
class Animal 
{
public:
    void eat() 
    {
        cout << "I can eat!" << endl;
    }
};

// Derived class
class Dog : public Animal
{
public:
    void bark() 
    {
        cout << "I can bark!" << endl;
    }
};

int main() 
{
    Dog dog;
    dog.eat();  // Inherited from base class
    dog.bark(); // Defined in derived class
    return 0;
}
/* Expected output
I can eat
I can bark
*/
