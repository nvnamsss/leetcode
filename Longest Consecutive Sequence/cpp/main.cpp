#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int rs = 0;
        unordered_set<int> set;
        for (int loop = 0; loop < nums.size(); loop++)
        {
            if (set.find(nums[loop]) == set.end()) {
                set.insert(nums[loop]);
            }
        }
        
        for (int loop = 0; loop < nums.size(); loop++)
        {
            if (set.find(nums[loop] - 1) == set.end()) {
                int seq = 1;
                int value = nums[loop] + 1;
                while (set.find(value) != set.end()) {
                    value++;
                    seq++;
                }

                rs = max(rs, seq);
            }
        }
        return rs;
    }
};