/*
Alex and Lee play a game with piles of stones.  There are an even number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].

The objective of the game is to end with the most stones.  The total number of stones is odd, so there are no ties.

Alex and Lee take turns, with Alex starting first.  Each turn, a player takes the entire pile of stones from either the beginning or the end of the row.  This continues until there are no more piles left, at which point the person with the most stones wins.

Assuming Alex and Lee play optimally, return True if and only if Alex wins the game.

 

Example 1:

Input: piles = [5,3,4,5]
Output: true
Explanation: 
Alex starts first, and can only take the first 5 or the last 5.
Say he takes the first 5, so that the row becomes [3, 4, 5].
If Lee takes 3, then the board is [4, 5], and Alex takes 5 to win with 10 points.
If Lee takes the last 5, then the board is [3, 4], and Alex takes 4 to win with 9 points.
This demonstrated that taking the first 5 was a winning move for Alex, so we return true.
 

Constraints:

2 <= piles.length <= 500
piles.length is even.
1 <= piles[i] <= 500
sum(piles) is odd.
*/

#include <bits/stdc++.h>

using namespace std;
class Solution
{
    vector<vector<pair<int, int>>> memo;
public:
    bool stoneGame(vector<int> &piles)
    {
        memo = vector<vector<pair<int, int>>>(piles.size() + 1, vector<pair<int,int>>(piles.size() + 1));
        pair<int,int> scores = dp(piles, 0, piles.size() - 1);

        return scores.first > scores.second;
    }

    pair<int, int> dp(vector<int> &piles, int left, int right) {
        if (left > right) return {0,0};
        if (memo[left][right].first != 0) return memo[left][right];

        pair<int,int> leftPick = dp(piles, left + 1, right);
        pair<int,int> rightPick = dp(piles, left, right - 1);

        if(piles[left] + leftPick.second > piles[right] + rightPick.second) {
            memo[left][right] = {piles[left] + leftPick.second, leftPick.first};
        } else {
            memo[left][right] = {piles[right] + rightPick.second, rightPick.first};
        }
        return memo[left][right];
    }
};