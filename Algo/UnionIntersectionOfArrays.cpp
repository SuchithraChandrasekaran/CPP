#include <iostream>

using namespace std;

void findUnion(int arr1[], int size1, int arr2[], int size2) 
{
    bool isDuplicate;
    cout << "Union: ";

    // Print elements of arr1
    for (int i = 0; i < size1; i++)
    {
        cout << arr1[i] << " ";
    }

    // Print elements of arr2 that are not in arr1 (no duplicates)
    for (int i = 0; i < size2; i++) 
    {
        isDuplicate = false;
        for (int j = 0; j < size1; j++) 
	{
            if (arr2[i] == arr1[j]) 
	    {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate) 
	{
            cout << arr2[i] << " ";
        }
    }
    cout << endl;
}

void findIntersection(int arr1[], int size1, int arr2[], int size2) 
{
    cout << "Intersection: ";
    bool found = false;

    for (int i = 0; i < size1; i++) 
    {
        for (int j = 0; j < size2; j++) 
	{
            if (arr1[i] == arr2[j]) 
	    {
                cout << arr1[i] << " ";
                found = true;
                break;
            }
        }
    }
    if (!found) 
    {
        cout << "No intersection found.";
    }
    cout << endl;
}

int main() 
{
    int array1[] = {1, 2, 3, 4, 5};
    int array2[] = {4, 5, 6, 7, 8};

    int size1 = sizeof(array1) / sizeof(array1[0]);
    int size2 = sizeof(array2) / sizeof(array2[0]);

    findUnion(array1, size1, array2, size2);
    findIntersection(array1, size1, array2, size2);

    return 0;
}

