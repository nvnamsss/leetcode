#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreater(vector<int>& nums) {
        vector<int> rs = vector<int>(nums.size(), -1);
        stack<int> s;
        for (int i = 0; i < nums.size(); i++)
        {
            if (!s.empty() && nums[s.top()] < nums[i]) {
                rs[s.top()] = nums[i];
                s.pop();
            }
            s.push(i);
        }
        
        return rs;
    }
};