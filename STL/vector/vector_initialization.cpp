/******************************************************************************
8 ways to initialize vectors
Reference : Gfg
*******************************************************************************/

#include <iostream>
#include <vector>
#include <list>
#include <numeric>// for itoa function
using namespace std;

int main()
{
    ////////// 1 //////////
    // Create an empty vector
    cout <<"1. One by One Initialization, using push_back:"<< endl;
    vector<int> vect;

    vect.push_back(10);
    vect.push_back(20);
    vect.push_back(30);

    for (int x : vect)
        cout << x << " ";//10 20 30
    cout << endl;    

    ////////// 2 //////////
    int n = 3;
    // Create a vector of size n with all values as 10.
    
    cout << "2. Creating a vector of size n,initialize with a Single Value:" << endl;
    vector<int> vect2(n, 10);

    for (int x : vect2)
        cout << x << " ";//10 10 10
    
    cout << endl;   
    ////////// 3 //////////
    cout << "3. Using Initializer List, with the list of values enclosed in curly braces {}:" << endl;
    vector<int> vect3{ 1111, 2222, 3333 };

    for (int x : vect3)
        cout << x << " ";
    cout << endl;
    
    ////////// 4 //////////
    cout <<"4. From an Array:" <<endl;
    int arr[] = { 11, 22, 33 };
    int n4 = sizeof(arr) / sizeof(arr[0]);
    vector<int> vect4(arr, arr + n4);
    
    cout << "sizeof(arr)  " << sizeof(arr) <<endl;
    cout << "sizeof(arr[0])  " << sizeof(arr[0]) <<endl;
    
    for (int x : vect4)
        cout << x << " ";
    cout << endl;
    
    ////////// 5 //////////   
    cout <<"5. From Another Vector: " <<endl;
    vector<int> vect5_1{ 100, 200, 300 };

    vector<int> vect5_2(vect5_1.begin(), vect5_1.end());

    for (int x : vect5_2)
        cout << x << " ";

    cout << endl;
    
    ////////// 6 //////////
    // creating array with size 10
    cout <<"6. Using std::fill() function: " <<endl;
    vector<int> vect6(10);

    // initializing using fill() function
    int value = 3;
    fill(vect6.begin(), vect6.end(), value);

    // printing vector
    for (int x : vect6)
        cout << x << " ";

    cout << endl;
    
    ////////// 7 //////////

    // declaring a vector with size 5
    cout <<"7. Using std::iota() function: "<<endl;
    vector<int> vec7(5);

    // initializing using iota()
    iota(vec7.begin(), vec7.end(), 1);

    // printing the vector
    for (int i = 0; i < 5; i++) 
    {
        cout << vec7[i] << " ";
    }
    cout << endl;
    ////////// 8 //////////   
    cout <<"8. From Any STL Container: " <<endl;
    list <int> l{ 100, 200, 300 };

    vector<int> vect8(l.begin(), l.end());

    for (int x : vect8)
        cout << x << " ";

    cout << endl;
    
    return 0;
}
