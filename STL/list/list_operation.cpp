/******************************************************************************

List (Doubly Linked List)

A list is a doubly linked list, which allows efficient insertion and deletion at any position.

*******************************************************************************/
#include <iostream>
#include <list>

using namespace std;
int main() 
{
    list<int> myList = {10, 20, 30};
    
    // Iterating through list
    cout << "List elements: ";
    for (int x : myList) 
    {
        cout << x << " ";
    }
    cout << "\n";
    
    // Adding elements
    myList.push_back(40);
    myList.push_front(5);

    // Iterating through list
    cout << "List elements after push_back, push_front: ";
    for (int x : myList) 
    {
        cout << x << " ";
    }
    cout << "\n";

    // Removing elements 
    myList.pop_back();
    myList.pop_front();
    
    cout << "List elements after pop_back and pop_front: ";
    for (int x : myList) 
    {
        cout << x << " ";
    }
    cout << "\n";

    // Insert and erase
    auto it = myList.begin();
    advance(it, 1); // Move iterator to the second position
    myList.insert(it, 15);
    cout << "List elements after insert: ";
    for (int x : myList) 
    {
        cout << x << " ";
    }
    cout << "\n";
    it = myList.begin();
    advance(it, 2);
    myList.erase(it);
    
    cout << "List elements after erase: ";
    for (int x : myList) 
    {
        cout << x << " ";
    }
    cout << "\n";
    

    // Reverse and sort
    myList.reverse();
    cout << "List elements after reverse: ";
    for (int x : myList) 
    {
        cout << x << " ";
    }
    cout << "\n";
    myList.sort();

    cout << "List elements after sort: ";
    for (int x : myList) 
    {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}
