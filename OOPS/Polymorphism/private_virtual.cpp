#include <iostream>
using namespace std;

class A 
{
public:
    virtual void display() 
    { // Virtual function for runtime polymorphism
        cout << "I am A display\n";
    }
};

class B : public A 
{
protected:
    void display() override 
    {  // Now accessible via A*
        cout << "I am B display\n";
    }
};

int main() 
{
    A* aPtr = new B();  
    B bObj;
    A& aObj = bObj;

    aObj.display();   // Calls B::display()
    aPtr->display();  // Calls B::display()

    delete aPtr;
    return 0;
}
