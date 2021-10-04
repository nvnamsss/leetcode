/*
You are given an integer array matchsticks where matchsticks[i] is the length of the ith matchstick. You want to use all the matchsticks to make one square. You should not break any stick, but you can link them up, and each matchstick must be used exactly one time.

Return true if you can make this square and false otherwise.

 

Example 1:


Input: matchsticks = [1,1,2,2,2]
Output: true
Explanation: You can form a square with length 2, one side of the square came two sticks with length 1.
Example 2:

Input: matchsticks = [3,3,3,3,4]
Output: false
Explanation: You cannot find a way to form a square with all the matchsticks.
 

Constraints:

1 <= matchsticks.length <= 15
0 <= matchsticks[i] <= 109
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool recursive(vector<int> &matchsticks, int index, vector<long> s, int max) {
        if (index == matchsticks.size()) {
            for (int i = 0; i < 3; i++)
            {
                if (s[i] != max) return false;
            }
            return true;
        }

        for (int i = 0; i < 3; i++)
        {
            if (s[i] + matchsticks[index] > max) continue;
            s[i] = s[i] + matchsticks[index];
            if (recursive(matchsticks, index + 1, s, max)) return true;
            s[i] = s[i] - matchsticks[index];
        }

        return false;
    }

    bool makesquare(vector<int> &matchsticks)
    {
        int max = 0;
        // can = false;
        for (int i = 0; i < matchsticks.size(); i++)
        {
            max += matchsticks[i];
        }
        if (max % 4 != 0)
            return false;

        return recursive(matchsticks, 0 , vector<long>{0,0,0}, max / 4);
    }
};

int main() {
    Solution s;
    vector<int> sticks{1,1,2,2,2};
    s.makesquare(sticks);

    sticks = vector<int>{2,2,2,2,2,2};
    s.makesquare(sticks);

    sticks = vector<int>{3,1,3,3,10,7,10,3,6,9,10,3,7,6,7};
    s.makesquare(sticks);

    sticks = vector<int>{6961655,6721573,5852338,4455955,7980746,4533546,1148969,101844,9721301,4048728,4397033,2520627,2522511,6094454,1023140};
    s.makesquare(sticks);

}