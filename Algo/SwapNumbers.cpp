#include <iostream>
using namespace std;

// 1. Pass by Value (doesn't work for actual swapping)
void swapByValue(int a, int b) 
{
    int temp = a;
    a = b;
    b = temp;
    // Changes only apply to local copies here
}

// 2. Pass by Reference (directly modifies originals)
void swapByReference(int &a, int &b) 
{
    int temp = a;
    a = b;
    b = temp;
}

// 3. Pass by Pointer (modifies originals through addresses)
void swapByPointer(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() 
{
    int x = 10, y = 20;

    // 1. Pass by Value 
    cout << "Original values: " << x << ", " << y << endl;
    swapByValue(x, y);
    cout << "After swapByValue: " << x << ", " << y << endl;
    cout << "(No actual swap occurs - pass by value)" << endl << endl;

    // Reset values
    x = 10; 
    y = 20;

    // 2. Pass by Reference 
    cout << "Original values: " << x << ", " << y << endl;
    swapByReference(x, y);
    cout << "After swapByReference: " << x << ", " << y << endl;
    cout << "(Values successfully swapped)" << endl << endl;

    // Reset values
    x = 10;
    y = 20;

    // 3. Pass by Pointer 
    cout << "Original values: " << x << ", " << y << endl;
    swapByPointer(&x, &y);
    cout << "After swapByPointer: " << x << ", " << y << endl;
    cout << "(Values successfully swapped)" << endl;

    return 0;
}
/*Expected Output
Original values: 10, 20
After swapByValue: 10, 20
(No actual swap occurs - pass by value)

Original values: 10, 20
After swapByReference: 20, 10
(Values successfully swapped)

Original values: 10, 20
After swapByPointer: 20, 10
(Values successfully swapped)
*/
