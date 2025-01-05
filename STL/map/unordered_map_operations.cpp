/******************************************************************************

Map (Key-Value Pairs)

A map is a collection of key-value pairs where each key is unique

*******************************************************************************/
#include <iostream>
#include <unordered_map>

using namespace std;
int main() 
{
    unordered_map<int, string> mp;
    mp[1] = "one";
    mp[2] = "two";
    mp[3] = "three";

    // Iterating through unordered_map
    cout << "Map contents:\n";
    for ( auto &pair : mp) 
    {
        cout << pair.first << ": " << pair.second << "\n";
    }
  
    // Accessing elements
    cout << "First Number: " << mp[1] << "\n";

    // Iterating through unordered_map
    cout << "Map contents:\n";
    for (auto& pair : mp) 
    {
        cout << pair.first << ": " << pair.second << "\n";
    }

    // Modifying values
    mp[1] = "ONE";
    
    // Iterating through unordered_map
    cout << "Map contents after modification:\n";
    for (auto& pair : mp) 
    {
        cout << pair.first << ": " << pair.second << "\n";
    }
    
    // Inserting an element using insert
    mp.insert({4, "four"});

    // Iterating through unordered_map
    cout << "Map contents after insertion:\n";
    for (auto& pair : mp) 
    {
        cout << pair.first << ": " << pair.second << "\n";
    }
    
    // Checking if a key exists
    if (mp.find(2) != mp.end()) 
    {
        cout << "2 is in the map.\n";
    } 
    else 
    {
        cout << "2 is not in the map.\n";
    }

    // Removing an element
    mp.erase(3);
    
    // Iterating through unordered_map
    cout << "Map contents after erase() of 1 key value pair:\n";
    for (auto& pair : mp) 
    {
        cout << pair.first << ": " << pair.second << "\n";
    }

    // Size and clear
    cout << "Size of map: " << mp.size() << "\n";
    mp.clear();
    cout << "Size after clearing: " << mp.size() << "\n";

    return 0;
}
