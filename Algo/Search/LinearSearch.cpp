#include <iostream>
using namespace std;

int main() 
{
    int arr[] = {2, 3, 4, 10, 15, 20, 25};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;
    bool found = false;

    cout << "Enter the number to search: ";
    cin >> target;

    for (int i = 0; i < size; i++) 
    {
        if (arr[i] == target) 
        {
            cout << "Element found at index " << i << endl;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
/* Expected output
test run 1:
Enter the number to search: 15
Element found at index 4
tet run 2:
Enter the number to search: 85
Element not found in the array.
*/
