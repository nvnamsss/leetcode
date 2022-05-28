/*
You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.

One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.

Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).

Note: You cannot rotate an envelope.

 

Example 1:

Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
Output: 3
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
Example 2:

Input: envelopes = [[1,1],[1,1],[1,1]]
Output: 1
 

Constraints:

1 <= envelopes.length <= 105
envelopes[i].length == 2
1 <= wi, hi <= 105
*/

#include <bits/stdc++.h>
using namespace std;

class Comparator {
    bool operator() (vector<int>& a, vector<int>& b) {
        return a[0]+a[1] < b[0]+b[1];
    }
};

class Solution {
    int searchW(vector<vector<int>>& envelopes, int target) {
        int l = 0;
        int r = envelopes.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (envelopes[m][0] > target) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return 0;
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end());
        vector<int> dp = vector<int>(envelopes.size());
        int ans = 0;
        for (int i = 0; i < envelopes.size(); i++)
        {
            int nearestW = searchW(envelopes, i);
        }
        
        return ans;
    }
};