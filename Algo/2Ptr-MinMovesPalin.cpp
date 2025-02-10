#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minMovesToMakePalindrome(string s) 
{
    int n = s.size();
    int left = 0, right = n - 1;
    int moves = 0;
    
    while (left < right) 
    {
        if (s[left] == s[right]) 
        {
            left++, right--;
        } 
        else 
        {
            int l = right;
            while (l > left && s[l] != s[left])
                l--;
            
            if (l == left) 
            {
                swap(s[left], s[left + 1]);
                moves++;
            } 
            else 
            {
                for (int i = l; i < right; i++) 
                {
                    swap(s[i], s[i + 1]);
                    moves++;
                }
                left++, right--;
            }
        }
    }
    return moves;
}

int main() 
{
    string s;
    cin >> s;
    cout << minMovesToMakePalindrome(s) << endl;
    return 0;
}
