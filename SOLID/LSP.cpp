/*
The Liskov Substitution Principle (LSP) states that
 subtypes must be substitutable for their base types without altering the correctness of the program.
*/
//Instead of forcing Square to inherit from Rectangle, we create a separate base class for both
#include <iostream>
using namespace std;

class Shape 
{
public:
    virtual int getArea() = 0; // Abstract method
    virtual ~Shape() {}
};

class Rectangle : public Shape 
{
protected:
    int width, height;
public:
    Rectangle(int w, int h) 
    {
        width=w; height=h;
    }

    int getArea() 
     { return width * height; }
};

class Square : public Shape
{
protected:
    int side;
public:
    Square(int s) 
    {
        side =s;
    }

    int getArea() 
     { return side * side; }
};

void printArea(Shape& s) 
{
    cout << "Area: " << s.getArea() << endl;
}

int main() 
{
    Rectangle rect(4, 5);
    Square sqr(5);

    printArea(rect); // Output: Area: 20
    printArea(sqr);  // Output: Area: 25

    return 0;
}
