#include <iostream>
using namespace std;

// Base class for dynamic_cast demonstration
class Base {
public:
    virtual void print() { cout << "This is Base class" << endl; }
    virtual ~Base() {} // Virtual destructor for proper polymorphic behavior
};

// Derived class
class Derived : public Base {
public:
    void print() override { cout << "This is Derived class" << endl; }
    void derivedOnly() { cout << "This method only exists in Derived" << endl; }
};

int main() {
    // Implicit typecasting (done automatically by the compiler)
    int integer_value = 10;
    double double_value = integer_value;  // int implicitly cast to double
    
    cout << "Implicit casting from int to double: " << double_value << endl;
    
    // Explicit typecasting using C-style cast
    double pi = 3.14159;
    int rounded_pi = (int)pi;  // double explicitly cast to int (decimal part is truncated)
    
    cout << "Explicit C-style casting from double to int: " << rounded_pi << endl;
    
    // Explicit typecasting using C++ static_cast
    float float_value = 7.9;
    int integer_result = static_cast<int>(float_value);  // modern C++ style cast
    
    cout << "Explicit static_cast from float to int: " << integer_result << endl;

    // dynamic_cast example: works with pointers to polymorphic classes (with virtual functions)
    cout << "\n--- dynamic_cast examples ---" << endl;
    
    // Create a Derived object but point to it with a Base pointer
    Base* base_ptr = new Derived();
    base_ptr->print();  // Will call Derived's implementation due to virtual function
    
    // Safe downcasting using dynamic_cast
    Derived* derived_ptr = dynamic_cast<Derived*>(base_ptr);
    
    // Check if cast was successful
    if (derived_ptr)
    {
        cout << "dynamic_cast successful!" << endl;
        derived_ptr->derivedOnly();  // Can now call Derived-specific methods
    }
    else {
        cout << "dynamic_cast failed!" << endl;
    }
  
    // Clean up allocated memory
    delete base_ptr;
    delete actual_base_ptr;

    return 0;
}
