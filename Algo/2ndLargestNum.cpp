#include <iostream>
#include <vector>
using namespace std;

int findSecondLargest( vector<int> nums) 
{
    int first = 0;
    int second = 0;

    for (int i = 0; i < nums.size(); i++) 
    {
        if (nums[i] > first) 
        {
            second = first;
            first = nums[i];
        } 
        else if (nums[i] > second && nums[i] < first) 
        {
            second = nums[i];
        }
    }

    if (second == 0) 
    {
        cout << "Second largest does not exist." << endl;
        return -1;  // Or any other appropriate value
    }
    else 
    {
        return second;
    }
}

int main() 
{
    vector<int> v = {45, 67, 89, 89, 23, 67};
    int result = findSecondLargest(v);
    if (result != -1)
    {
        cout << "Second largest number is: " << result << endl;
    }
    return 0;
}
