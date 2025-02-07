#include <iostream>
#include <map>
#include <unordered_map>

/*Use Case	
map-       When data needs to be sorted automatically	
unordered- When fast access is needed without sorting	
multimap - When multiple values for the same key are required
*/
void displayMap(std::map<int, std::string>& m) 
{
    std::cout << "Ordered Map: ";
    for (auto& pair : m)
        std::cout << "{" << pair.first << ": " << pair.second << "} ";
    std::cout << "\n";
}

void displayUnorderedMap(std::unordered_map<int, std::string>& um) 
{
    std::cout << "Unordered Map: ";
    for (auto& pair : um)
        std::cout << "{" << pair.first << ": " << pair.second << "} ";
    std::cout << "\n";
}

void displayMultimap(std::multimap<int, std::string>& mm) 
{
    std::cout << "Multimap: ";
    for (auto& pair : mm)
        std::cout << "{" << pair.first << ": " << pair.second << "} ";
    std::cout << "\n";
}

int main() 
{
    std::map<int, std::string> orderedMap;
    std::unordered_map<int, std::string> unorderedMap;
    std::multimap<int, std::string> multiMap;

    // Insertion
    orderedMap[1] = "One"; orderedMap[3] = "Three"; orderedMap[2] = "Two";
    unorderedMap[1] = "One"; unorderedMap[3] = "Three"; unorderedMap[2] = "Two";
    multiMap.insert({1, "One"}); multiMap.insert({2, "Two"}); multiMap.insert({1, "First-One"});

    // Display
    displayMap(orderedMap);
    displayUnorderedMap(unorderedMap);
    displayMultimap(multiMap);

    // Deletion
    orderedMap.erase(2);
    unorderedMap.erase(2);
    multiMap.erase(1);  // Removes all keys with value 1

    // Display after deletion
    std::cout << "\nAfter Deletion:\n";
    displayMap(orderedMap);
    displayUnorderedMap(unorderedMap);
    displayMultimap(multiMap);

    return 0;
}
