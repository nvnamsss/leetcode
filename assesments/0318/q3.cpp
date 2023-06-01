/*
You have a keyboard layout as shown above in the X-Y plane, where each English uppercase letter is located at some coordinate.

For example, the letter 'A' is located at coordinate (0, 0), the letter 'B' is located at coordinate (0, 1), the letter 'P' is located at coordinate (2, 3) and the letter 'Z' is located at coordinate (4, 1).
Given the string word, return the minimum total distance to type such string using only two fingers.

The distance between coordinates (x1, y1) and (x2, y2) is |x1 - x2| + |y1 - y2|.

Note that the initial positions of your two fingers are considered free so do not count towards your total distance, also your two fingers do not have to start at the first letter or the first two letters.

 

Example 1:

Input: word = "CAKE"
Output: 3
Explanation: Using two fingers, one optimal way to type "CAKE" is: 
Finger 1 on letter 'C' -> cost = 0 
Finger 1 on letter 'A' -> cost = Distance from letter 'C' to letter 'A' = 2 
Finger 2 on letter 'K' -> cost = 0 
Finger 2 on letter 'E' -> cost = Distance from letter 'K' to letter 'E' = 1 
Total distance = 3
Example 2:

Input: word = "HAPPY"
Output: 6
Explanation: Using two fingers, one optimal way to type "HAPPY" is:
Finger 1 on letter 'H' -> cost = 0
Finger 1 on letter 'A' -> cost = Distance from letter 'H' to letter 'A' = 2
Finger 2 on letter 'P' -> cost = 0
Finger 2 on letter 'P' -> cost = Distance from letter 'P' to letter 'P' = 0
Finger 1 on letter 'Y' -> cost = Distance from letter 'A' to letter 'Y' = 4
Total distance = 6
 

Constraints:

2 <= word.length <= 300
word consists of uppercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    pair<int, int> c2l(char c) {
        int v = c - 'A';
        int row = v / 6;
        int column = v % 6;

        return {row, column};
    }

    int distance(int x1, int x2, int y1, int y2) {
        return abs(x1 - x2) + abs(y1 - y2);
    }
    
    int recursive(string& w, vector<vector<int>>& dp, int i1, int i2, int last) {
        if (i1 == w.size() || i2 == w.size()) {
            return 0;
        }

        if (dp[i1][i2] != -1) {
            return dp[i1][i2];
        }

        int v1 = recursive(w, dp, i1, max(i1, i2) + 1, i2);
        int v2 = recursive(w, dp, max(i1, i2) + 1, i2, i1);

        int ans = INT32_MAX;
        pair<int, int> p = c2l(w[max(i1, i2)]);
        if (last != -1) {
            pair<int, int> plast = c2l(w[last]);
            ans = min(ans, distance(p.first, plast.first, p.second, plast.second));
        } else {
            ans = 0;
        }

        dp[i1][i2] = min(v1, v2) + ans;
        return dp[i1][i2];        
    }
public:
    int minimumDistance(string word) {

        vector<vector<int>> dp = vector<vector<int>>(word.size(), vector<int>(word.size(), -1));
        return recursive(word, dp, 0, 0, -1);

    }
};

int main() {
    Solution s;
    cout << s.minimumDistance("CAKE") << endl;
}