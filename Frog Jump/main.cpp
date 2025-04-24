/*
A frog is crossing a river. The river is divided into some number of units, and at each unit, there may or may not exist a stone. The frog can jump on a stone, but it must not jump into the water.

Given a list of stones' positions (in units) in sorted ascending order, determine if the frog can cross the river by landing on the last stone. Initially, the frog is on the first stone and assumes the first jump must be 1 unit.

If the frog's last jump was k units, its next jump must be either k - 1, k, or k + 1 units. The frog can only jump in the forward direction.

 

Example 1:

Input: stones = [0,1,3,5,6,8,12,17]
Output: true
Explanation: The frog can jump to the last stone by jumping 1 unit to the 2nd stone, then 2 units to the 3rd stone, then 2 units to the 4th stone, then 3 units to the 6th stone, 4 units to the 7th stone, and 5 units to the 8th stone.
Example 2:

Input: stones = [0,1,2,3,4,8,9,11]
Output: false
Explanation: There is no way to jump to the last stone as the gap between the 5th and 6th stone is too large.
 

Constraints:

2 <= stones.length <= 2000
0 <= stones[i] <= 231 - 1
stones[0] == 0
stones is sorted in a strictly increasing order.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canCross(vector<int>& stones) {
        if (stones[1] - stones[0] != 1) {
            return false;
        }

        if (stones.size() == 2) {
            return stones[1] - stones[0] == 1;
        }
        int n = stones.size();
        vector<unordered_set<int>> dp = vector<unordered_set<int>>(n);
        for (int i = n - 2; i >= 0; --i) {
            dp[i].insert(stones[n - 1] - stones[i]);
            // dp[i].insert(stones[n - 1] - stones[i] - 1);
            // dp[i].insert(stones[n - 1] - stones[i] + 1);
            for (int j = i +1; j < n - 1; ++j) {
                int distance = stones[j] - stones[i];
                if (dp[j].count(distance) || dp[j].count(distance + 1) || dp[j].count(distance - 1)) {
                    dp[i].insert(distance);
                }
            }
        }

        return dp[1].count(1) || dp[1].count(2) || dp[1].count(0);
    }
};

int main() {
    Solution s;
    vector<int> stones = {0,1,3,5,6,8,12,17};
    cout << s.canCross(stones) << endl;
}