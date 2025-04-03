/* multiple(many) classes inherit from a single base class
*/
#include <iostream>

class Shape 
{
    public:
    void setDimensions(int x) 
    { 
        width = height = x; 
    }
    protected:
    int width, height;
};

class Circle : public Shape 
{
public:
    double area() 
    { 
        return 3.14 * width * width / 4; 
    }
};

class Square : public Shape 
{
public:
    int area() 
    { 
        return width * width; 
    }
};

int main() 
{
    Circle circle;
    Square square;
    
    circle.setDimensions(10);  // From Shape
    square.setDimensions(10);  // From Shape
    
    std::cout << "Circle area: " << circle.area() << std::endl;
    std::cout << "Square area: " << square.area() << std::endl;
}
