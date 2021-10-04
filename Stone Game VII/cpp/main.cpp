/*
Alice and Bob take turns playing a game, with Alice starting first.

There are n stones arranged in a row. On each player's turn, they can remove either the leftmost stone or the rightmost stone from the row and receive points equal to the sum of the remaining stones' values in the row. The winner is the one with the higher score when there are no stones left to remove.

Bob found that he will always lose this game (poor Bob, he always loses), so he decided to minimize the score's difference. Alice's goal is to maximize the difference in the score.

Given an array of integers stones where stones[i] represents the value of the ith stone from the left, return the difference in Alice and Bob's score if they both play optimally.

 

Example 1:

Input: stones = [5,3,1,4,2]
Output: 6
Explanation: 
- Alice removes 2 and gets 5 + 3 + 1 + 4 = 13 points. Alice = 13, Bob = 0, stones = [5,3,1,4].
- Bob removes 5 and gets 3 + 1 + 4 = 8 points. Alice = 13, Bob = 8, stones = [3,1,4].
- Alice removes 3 and gets 1 + 4 = 5 points. Alice = 18, Bob = 8, stones = [1,4].
- Bob removes 1 and gets 4 points. Alice = 18, Bob = 12, stones = [4].
- Alice removes 4 and gets 0 points. Alice = 18, Bob = 12, stones = [].
The score difference is 18 - 12 = 6.
Example 2:

Input: stones = [7,90,5,1,100,10,10,2]
Output: 122
 

Constraints:

n == stones.length
2 <= n <= 1000
1 <= stones[i] <= 1000
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int stoneGameVII(vector<int> &stones)
    {
        /* due to the problem, memorizing the sum of the remaining stones's value is needed.

        then after optimized the sum, we try to optimized the move of each player.
        intuitively, we saw that alice try to maximize the difference in score while bob do the opposite.

        thus in fact, we can say that both player are trying to maximum the score they have
        thus alice will try to pick the lesser score stone and so do bob   

        intuitively, it seems right but greedy iss not optimal thus we must change our mind
        by simulating the game instead we could yield the optimally play, of course the complexity be O(n^2)
        
        we denote dp[a][b] be the optimal score when we picking ath number in bth order
        
        */
        int n = stones.size();
        int sum[n + 1];
        int alice = 0;
        int bob = 0;
        int left = 1;
        int right = n;

        bool turn = false;
        for (int loop = 0; loop <= n; loop++)
        {
            sum[loop] = 0;
        }
        
        for (int loop = 0; loop < n; loop++)
        {
            sum[loop + 1] = sum[loop] + stones[loop];
            cout << sum[loop + 1] << endl;
        }

        for (int loop = 0; loop < n; loop++)
        {
            for (int loop2 = 0; loop2 < n - loop; loop2++)
            {

            }
            
        }
        
        
        return alice - bob;
    }

    
};

int main() {
    Solution s;
    vector<int> stones{5,3,1,4,2};
    int rs = s.stoneGameVII(stones);
    cout << "Result: "<< rs << " - Expect: " << 6 << endl;
    
    return 0;
}