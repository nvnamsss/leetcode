/*
Alice and Bob continue their games with piles of stones.  There are a number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].  The objective of the game is to end with the most stones. 

Alice and Bob take turns, with Alice starting first.  Initially, M = 1.

On each player's turn, that player can take all the stones in the first X remaining piles, where 1 <= X <= 2M.  Then, we set M = max(M, X).

The game continues until all the stones have been taken.

Assuming Alice and Bob play optimally, return the maximum number of stones Alice can get.

 

Example 1:

Input: piles = [2,7,9,4,4]
Output: 10
Explanation:  If Alice takes one pile at the beginning, Bob takes two piles, then Alice takes 2 piles again. Alice can get 2 + 4 + 4 = 10 piles in total. If Alice takes two piles at the beginning, then Bob can take all three piles left. In this case, Alice get 2 + 7 = 9 piles in total. So we return 10 since it's larger. 
Example 2:

Input: piles = [1,2,3,4,5,100]
Output: 104
 

Constraints:

1 <= piles.length <= 100
1 <= piles[i] <= 104
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int recursive(vector<int>& piles, vector<vector<int>>& dp, int total, int i, int m) {
        int ans = 0;
        int earn = 0;
        if (i == piles.size()) return 0;

        if (dp[i][m] != 0) return dp[i][m];

        for (int j = 0; j < m * 2 && i + j < piles.size(); j++)
        {
            total -= piles[i + j];
            earn += piles[i + j];
            int optimal = recursive(piles, dp, total, i + j + 1, max(m, j + 1));
            int point = earn + total - optimal;
            ans = max(ans, point);
        }
        dp[i][m] = ans;
        return ans;
    }   
public:
    int stoneGameII(vector<int>& piles) {
        if (piles.size() == 1) return piles[0];
        vector<vector<int>> dp = vector<vector<int>>(piles.size(), vector<int>(piles.size(), 0));
        int i = 0;      
        int m = 1;
        int total = 0;
        for (int i = 0; i < piles.size(); i++)
        {
            total += piles[i];
        }
        
        return recursive(piles, dp, total, 0, 1);
    }
};

int main() {
    Solution s;
    vector<int> piles = vector<int>{2,7,9,4,4};
    int rs = s.stoneGameII(piles);
    cout << "rs: " << rs << endl;

    piles = vector<int>{1,2,3,4,5,100};   
    rs = s.stoneGameII(piles);
    cout << "rs: " << rs << endl;

}