/******************************************************************************

Set (Unique Elements)

A set is a collection of unique elements that are stored in a specific order.

*******************************************************************************/

#include <iostream>
#include <unordered_set>

using namespace std;
int main() 
{
    unordered_set<int> mySet = {10, 20, 30};

    // Iterating through unordered_set
    cout << "Set elements: ";
    for (int x : mySet) 
    {
        cout << x << " ";
    }
    cout << "\n";

    // Adding elements
    mySet.insert(40);
    mySet.insert(50);
    
    // Iterating through unordered_set
    cout << "Set elements after insert(): ";
    for (int x : mySet) 
    {
        cout << x << " ";
    }
    cout << "\n";

    

    // Checking for existence
    if (mySet.find(30) != mySet.end()) 
    {
        cout << "30 found in the set.\n";
    }
    else
    {
        cout << "30 not found in the set.\n";
    }

    
    // Removing elements
    mySet.erase(20);

    // Iterating through unordered_set
    cout << "Set elements after erase() of 1 element: ";
    for (int x : mySet) 
    {
        cout << x << " ";
    }
    cout << "\n";

    // Size and clear
    cout << "Size of set: " << mySet.size() << "\n";
    mySet.clear();
    cout << "Size after clearing: " << mySet.size() << "\n";

    return 0;
}
