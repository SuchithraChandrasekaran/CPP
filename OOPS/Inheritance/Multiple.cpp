/*
Multiple Inheritance- a derived class inherits from multiple base classes.
*/
# include <iostream>
using namespace std;

class ElectricalDevice 
{
public:
    void turnOn() { cout << "Device powered on" << endl; }
    void turnOff() { cout << "Device powered off" << endl; }
};

class MediaStorage
{
public:
    void storeData(int amount) 
    { 
        cout << "Storing " << amount << "GB of data" << endl; 
    }
};

class SmartPhone : public ElectricalDevice, public MediaStorage 
{
public:
    void makeCall() 
	{ 
        cout << "Making a phone call" << endl; 
    }
};

int main() 
{
    SmartPhone myPhone;
    
    // Using methods from ElectricalDevice
    myPhone.turnOn();
    
    // Using methods from MediaStorage
    myPhone.storeData(64);
    
    // Using methods from SmartPhone itself
    myPhone.makeCall();
 
    // Shutting down, Using methods from ElectricalDevice
    myPhone.turnOff();
    
    return 0;
}
/*
Expected output:

Device powered on
Storing 64GB of data
Making a phone call
Device powered off
*/
