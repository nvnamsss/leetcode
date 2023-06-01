/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int ml = height[l];
        int mr = height[r];
        int ans = 0;
        while (l < r) {
            if (height[l] >= height[r]) {
                r--;
                if (height[r] < mr) {
                    ans += mr - height[r];
                } else {
                    mr = height[r];
                }
            } else {
                l++;
                if (height[l] < ml) {
                    ans += ml - height[l];
                } else {
                    ml = height[l];
                }
            }
        }

        return ans;
    }
};  

int main() {
    Solution s;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << s.trap(height) << endl;
}