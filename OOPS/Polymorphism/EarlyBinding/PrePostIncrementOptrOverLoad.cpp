//Pre-increment, Post-increment operator overloading

#include <iostream>
using namespace std;

class Counter 
{
    int value;

public:
    Counter(int v = 0) 
    {
        value= v;
    }

    // Pre-increment
    Counter& operator++() 
    {
        ++value;              // Increase first
        return *this;         // Return the updated object
    }

    // Post-increment
    Counter operator++(int) 
    {
        Counter temp = *this; // Save original
        value++;              // Then increase
        return temp;          // Return original (before increment)
    }

    void display() 

    {
        cout << "Value: " << value << endl;
    }
};

int main() 
{
    Counter c(5);

    ++c;       // Pre-increment
    c.display();  // Value: 6

    c++;       // Post-increment
    c.display();  // Value: 7
}

