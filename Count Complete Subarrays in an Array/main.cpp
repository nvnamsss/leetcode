#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countCompleteSubarrays(vector<int> &nums)
    {
        int l = 0;
        int r = 0;
        unordered_map<int, int> mp;
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            m[nums[i]]++;
        }
        
        int prev_l = 0;
        int ans = 0;
        while (r < nums.size()) {
            // extend
            mp[nums[r]]++;
            if (mp.size() == m.size()) {
                // complete

                // shrink
                while (mp.size() == m.size()) {
                    mp[nums[l]]--;
                    if (mp[nums[l]] == 0) {
                        mp.erase(nums[l]);
                    }
                    l++;
                }

                // count
                ans += (l - prev_l) * (nums.size() - r);
                prev_l = l;                 
            }
            ++r;
        }
        
        return ans;
    }
};