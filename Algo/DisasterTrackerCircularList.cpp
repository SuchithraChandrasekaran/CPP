/*Problem Statement: Disaster Management Tracker using STL Unordered Map and Circular List
Objective:
Develop a disaster tracking system that maintains records of disasters occurring in different areas.
The system should efficiently store, update, and remove disaster records while ensuring 
a maximum limit of 100 entries using an unordered map and a circular list.

Requirements:

Data Storage:
1.Use an unordered_map where the key is the area name and the value is the disaster in that area.
2.Maintain a circular list (FIFO behavior) with a maximum capacity of 100 entries.

Functionality:
1.Log a Disaster:
If an area already exists in the list, update its disaster information and move it to the most recent position.
If an area does not exist, add it to the tracker.
If the tracker reaches its maximum limit (100 entries), remove the oldest entry before adding a new one.
2.Resolve a Disaster:
When an issue is resolved, remove the corresponding area and its disaster entry from the tracker.
3.Display All Disasters:
Print the list of active disasters along with the respective area names in the order they were logged.

*/
#include <iostream>
#include <unordered_map>
#include <list>
#include <string>

class DisasterTracker 
{
private:
    std::unordered_map<int, std::pair<std::string, std::string>> disasterMap; // areaID -> (areaName, disaster)
    std::list<int> areaOrder; // Maintains insertion order
    int maxSize;

public:
    DisasterTracker(int size = 100) 
    {
        maxSize = size;
    }

    void logDisaster(int areaID, const std::string& areaName, const std::string& disaster) 
    {
        // If area already exists, update the disaster info
        if (disasterMap.find(areaID) != disasterMap.end()) 
        {
            disasterMap[areaID] = {areaName, disaster};  // Update disaster info
            return;  // No need to re-add in order list
        }

        // Reject entry if the max size is reached
        if (disasterMap.size() >= maxSize)
        {
            std::cout << "Cannot log new disaster! Max limit reached.\n";
            return;
        }

        // Add new entry
        disasterMap[areaID] = {areaName, disaster};
        areaOrder.push_back(areaID); // Add the area ID to the order list
    }

    void resolveDisaster(int areaID) 
    {
        if (disasterMap.find(areaID) != disasterMap.end()) 
        {
            // Remove only the resolved area from the list
            disasterMap.erase(areaID);
            areaOrder.remove(areaID);
            std::cout << "Removing disaster in Area " << areaID << "\n";
            std::cout << "Resolved disaster in: Area " << areaID << "\n";
        } 
        else 
        {
            std::cout << "No disaster found for Area ID: " << areaID << "\n";
        }
    }

    void displayDisasters() 
    {
        for (int areaID : areaOrder) 
        {
            std::cout << "ID: " << areaID << " | Area: " << disasterMap[areaID].first
                      << " | Disaster: " << disasterMap[areaID].second << "\n";
        }
    }
};

int main() 
{
    DisasterTracker tracker(5);  // Example with max 5 entries for testing

    tracker.logDisaster(101, "Velacherry", "Flood");
    tracker.logDisaster(102, "Madipakkam", "Powercut");
    tracker.logDisaster(103, "Rameshwaram", "Cyclone");
    tracker.logDisaster(104, "Royapuram", "Tsunami");
    tracker.logDisaster(105, "Ooty", "Landslide");

    tracker.displayDisasters();
    
    std::cout << "Logging Area3 again with a new disaster...\n";
    tracker.logDisaster(103, "Rameshwaram", "Hurricane");

    tracker.displayDisasters();

    std::cout << "Logging new disaster, should NOT remove the oldest...\n";
    tracker.logDisaster(106, "Pondicherry", "Hurricane");

    tracker.displayDisasters();

    std::cout << "Resolving disaster in Area3...\n";
    tracker.resolveDisaster(103);

    tracker.displayDisasters();

    return 0;
}

