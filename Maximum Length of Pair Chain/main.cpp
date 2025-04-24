/*
You are given an array of n pairs pairs where pairs[i] = [lefti, righti] and lefti < righti.

A pair p2 = [c, d] follows a pair p1 = [a, b] if b < c. A chain of pairs can be formed in this fashion.

Return the length longest chain which can be formed.

You do not need to use up all the given intervals. You can select pairs in any order.

 

Example 1:

Input: pairs = [[1,2],[2,3],[3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4].
Example 2:

Input: pairs = [[1,2],[7,8],[4,5]]
Output: 3
Explanation: The longest chain is [1,2] -> [4,5] -> [7,8].
 

Constraints:

n == pairs.length
1 <= n <= 1000
-1000 <= lefti < righti <= 1000
*/

#include <bits/stdc++.h>
using namespace std;
class Comparer {
    public:
    bool operator() (vector<int>& a, vector<int>& b) {
        // if (a[1] == b[1]) {
        //     return a[0] < b[0];
        // }
        return a[0] < b[0];
    }
};
class Solution {
    int search(vector<vector<int>>& pairs, int target) {
        int l = 0;
        int r = pairs.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (pairs[m][0] > target) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        vector<vector<int>> pstart = vector<vector<int>>(pairs.size());
        vector<vector<int>> pend = vector<vector<int>>(pairs.size());
        for (int i = 0; i < pairs.size(); ++i) {
            pstart[i] = {pairs[i][0], i};
            pend[i] = {pairs[i][1], i};
        }
        vector<int> dp = vector<int>(pairs.size());
        sort(pstart.begin(), pstart.end(), Comparer());
        sort(pend.begin(), pend.end(), Comparer());
        for (int i = 0; i < pairs.size(); ++i) {
            int start = pstart[i][0];
            int index = pstart[i][1];

            int pivot = search(pend, start - 1);
            for (int j = 0; j <= pivot; ++j) {
                int trueIndex = pend[j][1];
                dp[index] = max(dp[index], dp[trueIndex] + 1);
            }
        }

        int ans = 0;
        for (int i = 0; i < dp.size(); ++i) {
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> p = {{-10,-8},{8,9},{-5,0},{6,10},{-6,-4},{1,7},{9,10},{-4,7}};
    s.findLongestChain(p);
}