/*
Open/Closed
Open for extension: You can add a Triangle or Square class without modifying existing code.
Closed for modification: The Shape base class remains untouched when adding new shapes.
*/
#include <iostream>
using namespace std;

// Base class
class Shape 
{
public:
    virtual void draw() { cout << "Drawing Shape" << endl; }
};

// Extended class without modifying the base class
class Circle : public Shape |
{
public:
    void draw()  { cout << "Drawing Circle" << endl; }
};

// Extended class without modifying the base class
class Rectangle : public Shape 
{
public:
    void draw()  { cout << "Drawing Rectangle" << endl; }
};

int main() 
{
    Shape* s1 = new Circle();
    Shape* s2 = new Rectangle();

    s1->draw(); // Output: Drawing Circle
    s2->draw(); // Output: Drawing Rectangle

    delete s1;
    delete s2;
    return 0;
}
