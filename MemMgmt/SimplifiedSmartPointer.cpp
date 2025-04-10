#include <iostream>
#include <memory> // Required for smart pointers

using namespace std;

int main() 
{
    cout << "unique_ptr" << endl;

    // unique_ptr owns the object exclusively
    unique_ptr<int> uPtr(new int(100));  // Creating a unique_ptr
    cout << "unique_ptr value: " << *uPtr << endl;

    // unique_ptr cannot be copied, only moved
    unique_ptr<int> movedPtr = move(uPtr); // Ownership transferred
    if (!uPtr) 
    {
        cout << "uPtr is now nullptr after move." << endl;
    }
    cout << "movedPtr value: " << *movedPtr << endl;

    cout << "\nshared_ptr" << endl;

    // shared_ptr allows multiple owners
    shared_ptr<int> sPtr1 = make_shared<int>(200);
    shared_ptr<int> sPtr2 = sPtr1; // Shared ownership

    cout << "shared_ptr value from sPtr1: " << *sPtr1 << endl;
    cout << "shared_ptr value from sPtr2: " << *sPtr2 << endl;
    cout << "Reference count: " << sPtr1.use_count() << endl;

    cout << "\nweak_ptr" << endl;

    // weak_ptr does not own the object, just observes shared_ptr
    weak_ptr<int> wPtr = sPtr1;

    // Lock weak_ptr to safely access the value
    if (auto temp = wPtr.lock()) 
    {
        cout << "Accessing value from weak_ptr: " << *temp << endl;
        cout << "Reference count from temp: " << temp.use_count() << endl;
    }
    else
    {
        cout << "Object no longer exists." << endl;
    }

    return 0;
}
/*Expected output
unique_ptr
unique_ptr value: 100
uPtr is now nullptr after move.
movedPtr value: 100

shared_ptr
shared_ptr value from sPtr1: 200
shared_ptr value from sPtr2: 200
Reference count: 2

weak_ptr
Accessing value from weak_ptr: 200
Reference count from temp: 3
*/
