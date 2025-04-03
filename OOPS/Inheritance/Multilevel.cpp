// Multilevel inheritance is when a derived class inherits from another derived class
#include <iostream>

class Device 
{
public:
    void turnOn() 
    {
        std::cout << "Device turned on" << std::endl;
    }
};

class Computer : public Device
{
public:
    void runProgram() 
    {
        std::cout << "Running program" << std::endl;
    }
};

class Laptop : public Computer 
{
public:
    void closeLid() 
    {
        std::cout << "Lid closed, sleep mode" << std::endl;
    }
};

int main() 
{
    Laptop myLaptop;
    
    // From Device (grandparent)
    myLaptop.turnOn();
    
    // From Computer (parent)
    myLaptop.runProgram();
    
    // From Laptop itself
    myLaptop.closeLid();
    
    return 0;
}
/* Expected output
Device turned on
Running program
Lid closed, sleep mode
*/

