/*
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

 

Example 1:


Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
Example 2:


Input: heights = [2,4]
Output: 4
 

Constraints:

1 <= heights.length <= 105
0 <= heights[i] <= 104

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int ans = 0;
        stack<int> s;
        stack<int> s2;
        heights.push_back(-1);
        for (int i = 0; i < heights.size(); i++)
        {
            int step = 0;
            while (!s.empty() && s.top() >= heights[i])
            {
                int v1 = s.top();
                int v2 = s2.top();
                step += v2;

                s.pop();
                s2.pop();
                ans = max(ans, v1 * step);
            }

            s.push(heights[i]);
            s2.push(step + 1);
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << s.largestRectangleArea(heights) << endl;
    heights = {2, 1, 2, 3, 5, 6};
    cout << s.largestRectangleArea(heights) << endl;
    heights = {2, 1, 2};
    cout << s.largestRectangleArea(heights) << endl;
    heights = {4, 2, 0, 3, 2, 4, 3, 4};
    cout << s.largestRectangleArea(heights) << endl;
}