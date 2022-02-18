/*
You are given an integer array nums. You want to maximize the number of points you get by performing the following operation any number of times:

Pick any nums[i] and delete it to earn nums[i] points. Afterwards, you must delete every element equal to nums[i] - 1 and every element equal to nums[i] + 1.
Return the maximum number of points you can earn by applying the above operation some number of times.

 

Example 1:

Input: nums = [3,4,2]
Output: 6
Explanation: You can perform the following operations:
- Delete 4 to earn 4 points. Consequently, 3 is also deleted. nums = [2].
- Delete 2 to earn 2 points. nums = [].
You earn a total of 6 points.
Example 2:

Input: nums = [2,2,3,3,3,4]
Output: 9
Explanation: You can perform the following operations:
- Delete a 3 to earn 3 points. All 2's and 4's are also deleted. nums = [3,3].
- Delete a 3 again to earn 3 points. nums = [3].
- Delete a 3 once more to earn 3 points. nums = [].
You earn a total of 9 points.
 

Constraints:

1 <= nums.length <= 2 * 104
1 <= nums[i] <= 104
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int m = 0;
        unordered_map<int, int> count;
        for (int i = 0; i < nums.size(); i++)
        {
            if (count.find(nums[i]) == count.end()) {
                count.insert({nums[i], 0});
            }
            count[nums[i]]++;
        }

        int avoid = 0;
        int use = 0;        
        int prev = -1;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == prev) continue;
            m = max(avoid, use);
            if (nums[i]-1 != prev ){
                use = nums[i] * count[nums[i]] + m;
                avoid = m;
            } else {
                use = nums[i] * count[nums[i]] + avoid;
                avoid = m;
            }

            prev = nums[i];
        }
        

        return max(avoid, use);
    }
};

int main() {
    Solution s;
    vector<int> nums =vector<int>{3,4,2};
    s.deleteAndEarn(nums);
}