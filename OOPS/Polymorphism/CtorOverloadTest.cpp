//CtorOverloadTest- Ctor Overloading, types & initialization
//CtorOverloadTest
#include <iostream>

class Test {
private:
    int* data1;
    int* data2;
    int* data3;

public:
    // Default Constructor
    Test() 
    {
        data1 = nullptr;
        data2 = nullptr;
        data3 = nullptr;
    }

    // Parameterized Constructors
    Test(int a)
    {
        /* if data2 and data3 are not initialized, it will take garbage values
         & delete data2; is called in the destructor. 
         This can cause a segmentation fault.*/
        data1 = new int(a);
        data2 = nullptr;
        data3 = nullptr;
    }

    Test(int a, int b) 
    {
        data1 = new int(a);
        data2 = new int(b);
        data3 = nullptr;
    }

    Test(int a, int b, int c) 
    {
        data1 = new int(a);
        data2 = new int(b);
        data3 = new int(c);
    }

    // Copy Constructor (Deep Copy)
    Test(const Test& other) 
    {
        if (other.data1)
            data1 = new int(*other.data1);
        else
            data1 = nullptr;

        if (other.data2)
            data2 = new int(*other.data2);
        else
            data2 = nullptr;

        if (other.data3)
            data3 = new int(*other.data3);
        else
            data3 = nullptr;
    }

    // Assignment Operator (Deep Copy)
    Test& operator=(const Test& other) 
    {
        if (this == &other) return *this; // Self-assignment check

        // Free existing memory
        if (data1) delete data1;
        if (data2) delete data2;
        if (data3) delete data3;

        // Allocate new memory and copy values
        if (other.data1)
            data1 = new int(*other.data1);
        else
            data1 = nullptr;

        if (other.data2)
            data2 = new int(*other.data2);
        else
            data2 = nullptr;

        if (other.data3)
            data3 = new int(*other.data3);
        else
            data3 = nullptr;

        return *this;
    }

    // Display Function
    void display() 
    {
        if (data1) std::cout << "Data1: " << *data1 << " ";
        if (data2) std::cout << "Data2: " << *data2 << " ";
        if (data3) std::cout << "Data3: " << *data3 << " ";
        std::cout << std::endl;
    }

    // Destructor (To Free Memory)
    ~Test() {
        if (data1) delete data1;
        if (data2) delete data2;
        if (data3) delete data3;
    }
};

int main() 
{
    Test t;
    {
        int a = 1;
        Test t1(a);
        t1.display();
    }
    Test t1(1);
    t1.display();
    
    Test t2(1, 2);
    t2.display();
    
    Test t3(1, 3, 4);
    t3.display();
    
    Test t4(t1);  // Copy constructor
    t4.display();
    
    Test t5 = t4; // Copy constructor
    t5.display();
    
    Test t6;
    t6 = t5;      // Assignment operator
    t6.display();
    
    Test* tPtr = new Test(1);
    tPtr->display();
    delete tPtr;  // Proper deletion
}
