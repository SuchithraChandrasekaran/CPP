/*
The array is sorted before applying binary search.

Time Complexity:
Best case:             O(1) (if the element is found at the middle)
Worst & Average case: O(log n) (as we keep dividing the array by half)

*/
#include <iostream>

using namespace std;

// Function to perform binary search
int binarySearch(int arr[], int left, int right, int key) 
{
    while (left <= right) 
    {
        int mid = left + (right - left) / 2;

        // Check if key is at mid
        if (arr[mid] == key)
            return mid;

        // If key is smaller, ignore right half
        if (arr[mid] > key)
            right = mid - 1;
        else // If key is larger, ignore left half
            left = mid + 1;
    }
    return -1; // Key not found
}

int main() 
{
    int arr[] = {2, 3, 4, 10, 15, 20, 25};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key;

    cout << "Enter the number to search: ";
    cin >> key;

    int result = binarySearch(arr, 0, size - 1, key);

    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}

/* Expected Output
Enter the number to search: 15
Element found at index 4
Enter the number to search: 5
Element not found
*/
