#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int main() 
{
    vector<int> v = {45, 67, 89, 85, 23, 67};
    
    //4 bytes (32 bits) int value range :-2,147,483,648 to 2,147,483,647 ; INT_MAX =2147483647 
    int smallest    = INT_MAX;
    int secondsmall = INT_MAX;
    
    for (int i=0; i<v.size(); i++)
    {
            if(v[i]< smallest)
            {
                secondsmall = smallest;
                smallest = v[i];
            }
            else if(v[i] <secondsmall && v[i] != smallest)
            {
                secondsmall = v[i];
            }
    }
    if (secondsmall == INT_MAX) 
        cout << "Second largest does not exist." << endl;
    else
        cout << "Second smallest value : " << secondsmall << endl;

    return 0;
}
