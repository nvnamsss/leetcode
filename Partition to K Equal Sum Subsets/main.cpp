/*
Given an integer array nums and an integer k, return true if it is possible to divide this array into k non-empty subsets whose sums are all equal.

 

Example 1:

Input: nums = [4,3,2,3,5,2,1], k = 4
Output: true
Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
Example 2:

Input: nums = [1,2,3,4], k = 3
Output: false
 

Constraints:

1 <= k <= nums.length <= 16
1 <= nums[i] <= 104
The frequency of each element is in the range [1, 4].
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int n;
    int sn;
    
    bool recursive(vector<int>& nums, vector<int>& subsets, int index, int total) {
        if (index == n) {
            return true;
        }

        set<int> set;
        for (int i = 0; i < sn; i++)
        {
            if (set.find(subsets[i]) == set.end() && subsets[i] + nums[index] <= total) {
                subsets[i] += nums[index];
                if (recursive(nums, subsets, index + 1, total)) {
                    return true;
                }
                subsets[i] -= nums[index];
                set.insert(subsets[i]);
            }
        }
        
        return false;
    }

    bool recursive2(vector<int>& nums, vector<bool>& visited, int total, int current, int index, int k) {
        if (k == 0) {
            return true;
        }

        if (current == total) {
            return recursive2(nums, visited, total, 0, 0, k - 1);
        }

        for (int i = index; i < nums.size(); i++)
        {
            if (visited[i] || current + nums[i] > total) continue;
            visited[i] = true;
            if (recursive2(nums, visited, total, current + nums[i], i + 1, k)) {
                return true;
            }
            visited[i] = false;
        }
        
        return false;
    }

public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }

        if (sum % k != 0) {
            return false;
        }
        n = nums.size();
        sn = k;
        vector<bool> visited = vector<bool>(nums.size(), false);
        return recursive2(nums, visited, sum / k, 0, 0, k);
    }
};

int main() {
    Solution s;
    vector<int> nums = vector<int>{4,3,2,3,5,2,1};

    bool rs = s.canPartitionKSubsets(nums, 4);
    cout << "result: " << rs << endl;

    nums = vector<int>{1,2,3,4};
    rs = s.canPartitionKSubsets(nums, 3);
    cout << "result: " << rs << endl;
    
    nums = vector<int>{354,1983,167,2655,73,927,470,485,1035,405,1358,1944,3404,4078,2500,577};
    rs = s.canPartitionKSubsets(nums, 5);
    cout << "result: " << rs << endl;
    
    nums = vector<int>{1739,5391,8247,236,5581,11,938,58,1884,823,686,1760,6498,6513,6316,2867};
    rs = s.canPartitionKSubsets(nums, 6);
    cout << "result: " << rs << endl;

    return 0;
}