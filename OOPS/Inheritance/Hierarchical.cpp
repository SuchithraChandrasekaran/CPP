/* multiple(many) classes inherit from a single base class
*/
#include <iostream>

class Shape 
{
public:
    void setDimension(int x) 
    { 
        dimension = x; 
    }

protected:
    int dimension;  // generic name, to be used as radius or side
};

class Circle : public Shape 
{
public:
    double area() 
    { 
        return 3.14 * dimension * dimension; // π * r²
    }
};

class Square : public Shape 
{
public:
    int area() 
    { 
        return dimension * dimension; // side²
    }
};

int main() 
{
    Circle circle;
    Square square;
    
    circle.setDimension(10);  // radius for circle
    square.setDimension(10);  // side for square
    
    std::cout << "Circle area: " << circle.area() << std::endl;
    std::cout << "Square area: " << square.area() << std::endl;

    return 0;
}
/* Expected output:
Circle area: 314
Square area: 100
*/
