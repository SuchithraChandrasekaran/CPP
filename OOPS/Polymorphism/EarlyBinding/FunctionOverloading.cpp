#include <iostream>
using namespace std;

class FOTest
{
public:
    void Display(int x) { cout << "Integer: " << x << endl; }
    void Display(double x) { cout << "Double: " << x << endl; }
};

int main() 
{
    FOTest obj;
    obj.Display(10);    // Calls Display(int)
    obj.Display(10.5);  // Calls Display(double)
    return 0;
}
/* Expected output
Integer: 10
Double: 10.5 */
