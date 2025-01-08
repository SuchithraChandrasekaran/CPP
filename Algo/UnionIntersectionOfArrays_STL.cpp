#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
void findUnion( vector<int> arr1,  vector<int> arr2)
 {
    set<int> unionSet(arr1.begin(), arr1.end());
    unionSet.insert(arr2.begin(), arr2.end());

    cout << "Union: ";
    for ( int element : unionSet) 
    {
        cout << element << " ";
    }
    cout << endl;
}

void findIntersection( vector<int> arr1,  vector<int> arr2) 
{
    set<int> set1(arr1.begin(), arr1.end());
    vector<int> intersection;

    for ( int element : arr2) 
    {
        if (set1.find(element) != set1.end()) 
	{
            intersection.push_back(element);
        }
    }

    cout << "Intersection: ";
    for ( int element : intersection) 
    {
        cout << element << " ";
    }
    cout << endl;
}

int main() 
{
    vector<int> array1 = {1, 2, 3, 4, 5};
    vector<int> array2 = {4, 5, 6, 7, 8};

    findUnion(array1, array2);
    findIntersection(array1, array2);

    return 0;
}

