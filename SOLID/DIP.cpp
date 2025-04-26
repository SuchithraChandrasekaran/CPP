/*	

The Dependency Inversion Principle (DIP) 
High-level modules should not depend on low-level modules. Both should depend on abstractions.
Abstractions should not depend on details. Details should depend on abstractions.
In simpler terms, 
the DIP encourages us to depend on interfaces or abstract classes 
instead of directly depending on concrete classes. 
This way, you can change the concrete implementation without affecting the high-level logic.

SwitchableDevice    	 -Abstract class (interface) with turnOn and turnOff.
LightBulb	             - Implements SwitchableDevice, provides real behavior.
Switch	               - High-level class. It depends on the interface, not on LightBulb directly.
main()	               - Creates a LightBulb, passes it to Switch, and controls it.
*/

#include <iostream>

// Abstract class (interface)
class SwitchableDevice 
{
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual ~SwitchableDevice() {}
};

// Low-level class
class LightBulb : public SwitchableDevice
{
public:
    void turnOn() 
    {
        std::cout << "LightBulb turned ON" << std::endl;
    }
    void turnOff()
    {
        std::cout << "LightBulb turned OFF" << std::endl;
    }
};

// High-level class depends on the interface, not directly on LightBulb
class Switch
{
private:
    SwitchableDevice& device;
public:
    Switch(SwitchableDevice& dev) 
    {
    device = dev;
    }
    void operateSwitch(bool on)
    {
        if (on)
        {
            device.turnOn();
        } 
        else 
        {
            device.turnOff();
        }
    }
};

int main()
{
    LightBulb bulb;
    Switch lightSwitch(bulb);

    lightSwitch.operateSwitch(true);   // LightBulb turned ON
    lightSwitch.operateSwitch(false);  // LightBulb turned OFF

    return 0;
}
