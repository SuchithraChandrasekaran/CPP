/* similar terms
Late Binding           = Function resolution happens at runtime.(Dynamic Binding)
Runtime Polymorphism   = Polymorphism that occurs at runtime using late binding.
Function Overriding    = Redefining a base class function in a derived class (essential for runtime polymorphism).
Dynamic Dispatch       = The actual process of selecting and calling the function

1. Abstract Class
    A class that cannot be instantiated and is meant to be a base class for other classes. 
    It contains at least one pure virtual function.
    You cannot create objects of an abstract class.

2. Abstract Function (Pure Virtual Function)
    A pure virtual function is declared in a base class but must be overridden in derived classes.
*/

#include <iostream>
using namespace std;

// Abstract Class
class Shape 
{
public:
    // Pure virtual function (Abstract function)
    virtual void draw() = 0;  // Makes Shape an abstract class
};

// Derived class implementing the abstract function
class Circle : public Shape 
{
public:
    void draw() 
   {
        cout << "Drawing Circle" << endl;
    }
};

// Derived class implementing the abstract function
class Square : public Shape 
{
public:
    void draw() 
    {
        cout << "Drawing Square" << endl;
    }
};

int main() {
    // Shape obj; // Error: Cannot instantiate abstract class
    Shape* s1 = new Circle();
    Shape* s2 = new Square();

    s1->draw();  // Output: Drawing Circle
    s2->draw();  // Output: Drawing Square

    delete s1;
    delete s2;
    
    return 0;
}
