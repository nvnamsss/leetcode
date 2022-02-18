#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int cur;
        int prev;
        for (int i = 0; i < nums.size(); i++)
        {
            int m = max(cur, prev + nums[i]);
            prev = cur;
            cur = m;
        }

        return max(cur, prev);                
    }
};