#include <iostream>
#include <memory> // Required for smart pointers

using namespace std;
int main() 
{
    // unique_ptr: Only one owner
    unique_ptr<int> uPtr = make_unique<int>(10);
    cout << "unique_ptr: " << *uPtr << endl;

    // unique_ptr cannot be copied, only moved
    unique_ptr<int> movedPtr = move(uPtr);// Ownership transferred
    if (!uPtr)
        cout << "uPtr is empty after move\n";
    cout << "movedPtr: " << *movedPtr << endl;

    // shared_ptr: Multiple owners
    shared_ptr<int> sPtr1 = make_shared<int>(20);
    shared_ptr<int> sPtr2 = sPtr1;
    cout << "shared_ptr: " << *sPtr1 << ", count: " << sPtr1.use_count() << endl;

    // weak_ptr: Just observing shared_ptr
    weak_ptr<int> wPtr = sPtr1;
    if (auto temp = wPtr.lock())
        cout << "weak_ptr: " << *temp << endl;

    return 0;
}
/* Expected output
unique_ptr: 10
uPtr is empty after move
movedPtr: 10
shared_ptr: 20, count: 2
weak_ptr: 20
*/
