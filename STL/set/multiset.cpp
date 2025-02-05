/******************************************************************************
Multiset (Allows Duplicates)

A multiset allows multiple occurrences of the same element.
*******************************************************************************/
#include <iostream>
#include <set>

using namespace std;
int main() 
{
    multiset<int> ms = {1, 2, 2, 3};
    ms.insert(2);  // Insert duplicate element

    for (int i : ms) 
    {
        cout << i << " ";
    }
    return 0;
}
