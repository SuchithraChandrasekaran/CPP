/*
Interface Segregation Principle (ISP)

 A client should not be forced to implement interfaces it doesn't use. 
Instead of one large interface, create smaller, more specific ones.

*/
#include <iostream>

// Applying ISP: Separate interfaces
class IWorkable
{
public:
    virtual void work() = 0;
};

class IEatable 
{
public:
    virtual void eat() = 0;
};

class Developer : public IWorkable, public IEatable 
{
public:
    void work()  
    {
        std::cout << "Developer is coding." << std::endl;
    }
    
    void eat()  
    {
        std::cout << "Developer is eating." << std::endl;
    }
};

class Robot : public IWorkable 
{
public:
    void work()  
    {
        std::cout << "Robot is working." << std::endl;
    }
};
