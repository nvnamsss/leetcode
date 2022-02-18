#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> recoverArray(vector<int> &nums)
    {
        vector<int> ans;
        vector<int> even;
        vector<int> odd;
        unordered_map<int, int> m;
        unordered_map<int, int> vs;
        sort(nums.begin(), nums.end());
        vector<int> possibleK = vector<int>(nums.size() - 1, 0);
        for (int i = 1; i < nums.size(); i++)
        {
            possibleK[i - 1] = nums[i] - nums[0];
        }

        for (auto &&k : possibleK)
        {
            for (int i = 0; i < count; i++)
            {
                /* code */
            }
            
        }
        
        return ans;
    }
};