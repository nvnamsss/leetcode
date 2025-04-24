#include <bits/stdc++.h>
using namespace std;

class Solution {
    string getKey(int x, int y) {
        return to_string(x) + "-" + to_string(y);
    }
    long long divideandconquer(vector<int>& nums, vector<long long>& prefix, unordered_map<string, long long>& memo, int l, int r) {
        if (l == r) {
            return nums[l];
        }
        
        string key = getKey(l, r);
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }
        
        long long ans = l % 2 == 1 ? prefix[l] - prefix[r + 1] : prefix[r + 1] - prefix[l];
        
        for (int i = l; i < r; ++i) {
            long long costLeft = divideandconquer(nums, prefix, memo, l, i);
            long long costRight = divideandconquer(nums, prefix, memo, i + 1, r);
            
            ans = max(ans, costLeft + costRight);
        }
        
        memo.insert({key, ans});
        return ans;
    }
    
public:
    long long maximumTotalCost(vector<int>& nums) {
        vector<long long> prefix = vector<long long>(nums.size() + 1);
        unordered_map<string, long long> memo;
        
        // vector<vector<long long>> memo = vector<vector<long long>(n, vector<long long>(n, -1))>;
        int sign = 1;
        
        for (int i = 0; i < nums.size(); ++i) {
            prefix[i+1] = prefix[i] + nums[i] * sign;
            sign *= -1;
        }
        
        return divideandconquer(nums, prefix, memo, 0, nums.size() - 1);
        
    }
};

int main() {
    Solution s;
    vector<int> arr = {1,-2,3,4};
    long long ans = s.maximumTotalCost(arr);
    cout << ans << endl;

    return 1;
}