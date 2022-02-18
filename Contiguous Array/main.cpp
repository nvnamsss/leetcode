#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> m;
        int prefix = 0;
        int ans = 0;
        m[0] = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0) {
                prefix = prefix - 1;
            } else {
                prefix = prefix + 1;
            }

            if (m.find(prefix) != m.end()) {
                ans = max(ans, i - m[prefix]);
            } else {
                m[prefix] = i;
            }

        }
           
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {0,1};
    cout << s.findMaxLength(nums) << endl;

    nums = {0,1,0};
    cout << s.findMaxLength(nums) << endl;

    nums = {0,1,0,1};
    cout << s.findMaxLength(nums) << endl;

}