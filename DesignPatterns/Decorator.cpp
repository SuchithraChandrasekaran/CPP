// Decporator - Adds behavior to objects dynamically without modifying their structure.
#include <iostream>

using namespace std;
// Step 1: Base Component (House)
class House 
{
    public:
        virtual void show()
        {
            cout << "Basic House";
        }
        virtual ~House() {}
};

// Step 2: Decorator Base Class (inherits from House)
class HouseDecorator : public House
{
    protected:
        House* house; // Pointer to the house being decorated
    public:
        HouseDecorator(House* h) 
        { 
            house = h; // Traditional constructor assignment
        }
    
        virtual void show() 
        {
            house->show(); // Delegates to the wrapped object
        }
};
// Step 3: Concrete Decorators (Windows, Doors)
class Windows : public HouseDecorator 
{
    public:
        Windows(House* h) : HouseDecorator(h) {}

        void show() 
        {
            house->show();
            cout << " + Windows";
        }
};

class Doors : public HouseDecorator 
{
public:
    Doors(House* h) : HouseDecorator(h) {}

    void show() 
    {
        house->show();
        cout << " + Doors";
    }
};

// Step 4: Client Code
int main() 
{
    House* myHouse = new House();
    cout << "Initial: ";
    myHouse->show();
    cout << endl;

    myHouse = new Windows(myHouse);  // Add Windows
    cout << "After Adding Windows: ";
    myHouse->show();
    cout << endl;

    myHouse = new Doors(myHouse);  // Add Doors
    cout << "After Adding Doors: ";
    myHouse->show();
    cout << endl;

    delete myHouse; // Free memory
    return 0;
}
/* Expected output

Initial: Basic House
After Adding Windows: Basic House + Windows
After Adding Doors: Basic House + Windows + Doors

*/

