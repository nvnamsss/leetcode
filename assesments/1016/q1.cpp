/*
You are given an integer array deck where deck[i] represents the number written on the ith card.

Partition the cards into one or more groups such that:

Each group has exactly x cards where x > 1, and
All the cards in one group have the same integer written on them.
Return true if such partition is possible, or false otherwise.



Example 1:

Input: deck = [1,2,3,4,4,3,2,1]
Output: true
Explanation: Possible partition [1,1],[2,2],[3,3],[4,4].
Example 2:

Input: deck = [1,1,1,2,2,2,3,3]
Output: false
Explanation: No possible partition.


Constraints:

1 <= deck.length <= 104
0 <= deck[i] < 104
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int GcdOfArray(vector<int> &arr, int idx)
    {
        if (idx == arr.size() - 1)
        {
            return arr[idx];
        }
        int a = arr[idx];
        int b = GcdOfArray(arr, idx + 1);
        return __gcd(a, b); // __gcd(a,b) is inbuilt library function
    }

public:
    bool hasGroupsSizeX(vector<int> &deck)
    {
        unordered_map<int, int> groups;

        for (int i = 0; i < deck.size(); i++)
        {
            groups[deck[i]]++;
        }

        vector<int> arr = vector<int>(groups.size());
        for (auto &&it : groups)
        {
            arr.push_back(it.second);
        }

        int v = GcdOfArray(arr, 0);
        return v != 1;
    }
};