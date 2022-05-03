#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int start = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == nums.size() - 1 || nums[i] + 1 < nums[i + 1]) {
                if (start == i) {
                    ans.push_back(to_string(nums[i]));
                } else {
                    string s = to_string(nums[start]) + "->" + to_string(nums[i]);
                    ans.push_back(s);
                }

                start = i + 1;
            } 
        }
        
        return ans;
    }
};