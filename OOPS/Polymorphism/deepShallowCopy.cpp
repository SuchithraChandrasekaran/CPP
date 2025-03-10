/*
Shallow Copy (Issue)
When obj1 is copied to obj2, both objects point to the same memory location.
When the destructor is called for obj2, it deletes the memory, and then when obj1 is destroyed, 
it tries to delete the same memory, causing a double delete issue.

Deep Copy (Solution)
When obj3 is copied to obj4, a new memory location is allocated for obj4, avoiding memory corruption.
Each object has its own copy of the allocated memory, preventing double deletion.
-----------------------
Purpose of Deep(int val)

It is used when we create a new Deep object using an integer value (e.g., Deep obj3(100);).
This constructor is necessary for objects that are instantiated without copying another object.
Deep Copy Constructor (Deep(const Deep& other))

This constructor ensures a separate memory allocation when copying another object (e.g., Deep obj4 = obj3;).
Without this, a shallow copy would occur, leading to double deletion issues.


*/

#include <iostream>
using namespace std;

class Shallow 
{

    int* data;
    public:
    Shallow(int val) 
    { 
        data = new int(val); 
        cout << "Shallow Constructor: Allocated memory at " << data << " with value " << *data << endl;
    }
    
    ~Shallow() 
    { 
        cout << "Shallow Destructor: Deleting memory at " << data << endl;
        delete data; 
    }
};

class Deep 
{

    int* data2;
    public:   
    Deep(int val) 
    { 
        data2 = new int(val); 
        cout << "Deep Constructor: Allocated memory at " << data2 << " with value " << *data2 << endl;
    }
    
    // Deep Copy Constructor
    Deep(const Deep& other)
    {
        data2 = new int(*other.data2);
        cout << "Deep Copy Constructor: Allocated new memory at " << data2 << " with copied value " << *data2 << endl;
    }
    
    ~Deep()
    { 
        cout << "Deep Destructor: Deleting memory at " << data2 << endl;
        delete data2; 
    }
};

int main() 
{
    cout << "Creating Shallow Object obj1" << endl;
    Shallow obj1(10);
    cout << "Copying Shallow Object obj1 to obj2" << endl;
    Shallow obj2 = obj1; // Problem: Same memory address copied
    
    cout << "\nCreating Deep Object obj3" << endl;
    Deep obj3(100);
    cout << "Copying Deep Object obj3 to obj4" << endl;
    Deep obj4 = obj3; 
    
    return 0;
}
/* Expected Output

Creating Shallow Object obj1
Shallow Constructor: Allocated memory at 0x5ead2da736c0 with value 10
Copying Shallow Object obj1 to obj2

Creating Deep Object obj3
Deep Constructor: Allocated memory at 0x5ead2da736e0 with value 100
Copying Deep Object obj3 to obj4
Deep Copy Constructor: Allocated new memory at 0x5ead2da73700 with copied value 100
Deep Destructor: Deleting memory at 0x5ead2da73700
Deep Destructor: Deleting memory at 0x5ead2da736e0
Shallow Destructor: Deleting memory at 0x5ead2da736c0
Shallow Destructor: Deleting memory at 0x5ead2da736c0
free(): double free detected in tcache 2

*/
