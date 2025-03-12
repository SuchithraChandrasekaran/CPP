/* A smart pointer is a C++ class that 
manages dynamic memory automatically, 
ensuring proper resource cleanup 
to prevent memory leaks */

#include <iostream>

class SmartPtr 
{
private:
    int* ptr;  // Raw pointer

public:
    // Constructor
    SmartPtr(int* p = nullptr) 
    {
        ptr = p;
    }

    // Destructor (to prevent memory leak)
    ~SmartPtr() 
    {
        delete ptr;
    }

    // Function to get raw pointer
    int* get() 
    {
        return ptr;
    }
};

int main() 
{
    SmartPtr sp(new int(10));  // Allocate memory
    std::cout << "Value: " << *(sp.get()) << std::endl;  // Access value

    return 0;  // Memory will be freed when sp goes out of scope
}

/*
Expected output
Value: 10
*/
