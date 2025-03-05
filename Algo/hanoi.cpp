/*
Analysis of the simplest implementation of Towers of Hanoi 

https://github.com/deepgrace/giant/blob/master/src/hanoi.hpp

Cost Analysis of the Code

Tower of Hanoi implementation using std::stack and std::array follows the classic O(2ⁿ) time complexity.

## Time Complexity
The recurrence relation for this problem is:
 T(n) = 2T(n-1) + O(1) 

Solving this recurrence relation yields:
 T(n) = O(2^n)

Thus, the time complexity is **O(2ⁿ)**.

## Space Complexity
- **Recursive Call Stack**: O(n)
- **Data Structure Storage**: O(n) (for three stacks storing n disks)

The total space complexity is **O(n)**.


*/

#include <iostream>
#include <array>
#include <stack>

/*
           _                         _                         _
          | |                       | |                       | |
         _| |_                      | |                       | |
        |_____|                     | |                       | |
       |_______|                    | |                       | |
      |_________|                   | |                       | |
     |___________|                  | |                       | |
    |_____________|                 | |                       | |
   |_______________|         _______| |_______         _______| |_______
  |                 |       |                 |       |                 |
 -----------------------------------------------------------------------------
           #0                        #1                        #2
*/

using namespace std;

template <typename T>
void hanoi(int n, array<stack<T>, 3>& peg, int from, int to, int use)
{
    if (n > 0)
    {
        hanoi(n - 1, peg, from, use, to);
        peg[to].push(peg[from].top());
        peg[from].pop();
        cout << from << " -> " << to << endl;
        hanoi(n - 1, peg, use, to, from);
    }
}

template <typename T = int>
void move(int n)
{
    array<stack<T>, 3> peg;
    for (int i = n; i > 0; --i)
         peg[0].push(i);
    hanoi(n, peg, 0, 1, 2);
}

int main()
{
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;
    move(n);
    return 0;
}
